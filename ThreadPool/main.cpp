#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <future>

using namespace std;

class ThreadPool {
public:
    // 构造函数：启动指定数量的工作线程
    ThreadPool(size_t threads) : stop(false) {
        for(size_t i = 0; i < threads; ++i)
            workers.emplace_back(
                [this] {
                    for(;;) {
                        std::function<void()> task;

                        {
                            // === 简历对应点：使用 std::unique_lock (RAII) 管理锁 ===
                            std::unique_lock<std::mutex> lock(this->queue_mutex);
                            
                            // 等待条件变量：如果停止了或者有新任务，就醒来
                            this->condition.wait(lock,
                                [this]{ return this->stop || !this->tasks.empty(); });
                            
                            // 如果停止且任务队列为空，线程退出
                            if(this->stop && this->tasks.empty())
                                return;
                            
                            // 取出任务
                            task = std::move(this->tasks.front());
                            this->tasks.pop();
                        }

                        // 执行任务
                        task();
                    }
                }
            );
    }

    // 析构函数：优雅关闭，把剩下的任务做完再走
    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all(); // 叫醒所有睡觉的线程起来下班
        for(std::thread &worker: workers)
            worker.join();      // 等待它们真正结束
    }

    // === 简历对应点：C++17 模板编程，支持任意函数作为任务 ===
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type> {
        
        using return_type = typename std::result_of<F(Args...)>::type;

        // === 简历对应点：虽然这里用的 shared_ptr，但可以说你理解智能指针避免内存泄漏 ===
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );
        
        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            // 如果线程池已经停止，就不允许再加任务了
            if(stop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            // 把任务加入队列
            tasks.emplace([task](){ (*task)(); });
        }
        condition.notify_one(); // 唤醒一个线程去干活
        return res;
    }

private:
    // 工作线程数组
    std::vector<std::thread> workers;
    // 任务队列
    std::queue<std::function<void()>> tasks;
    
    // === 简历对应点：std::mutex 和 线程同步 ===
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

// --- 测试 Demo ---
int main() {
    // 创建一个包含 4 个线程的池子
    ThreadPool pool(4);
    
    // 模拟的一堆结果
    std::vector<std::future<int>> results;

    // 扔 8 个任务进去
    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时
                return i * i;
            })
        );
    }

    // 打印结果
    for(auto && result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
    
    return 0;
}