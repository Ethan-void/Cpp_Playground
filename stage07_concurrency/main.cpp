#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

std::mutex coutMutex;

class Robot {
public:
    Robot(std::string name, int battery) : name_(std::move(name)), battery_(battery) {}

    void doWork(const std::string& task) {
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << name_ << " 开始任务: " << task << "\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        int batteryAfterWork = 0;
        {
            std::lock_guard<std::mutex> lock(mutex_);
            battery_ -= 10;
            batteryAfterWork = battery_;
        }

        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << name_ << " 完成任务: " << task << "，剩余电量 " << batteryAfterWork << "%\n";
        }
    }

private:
    std::string name_;
    int battery_;
    std::mutex mutex_;
};

int main() {
    Robot ground("地面巡逻者", 80);
    Robot flying("天空守护者", 90);
    Robot swimming("深海探索者", 70);

    std::vector<std::thread> threads;

    threads.emplace_back([&ground] {
        ground.doWork("巡逻 A 区");
    });

    threads.emplace_back([&flying] {
        flying.doWork("空中侦察");
    });

    threads.emplace_back([&swimming] {
        swimming.doWork("水下探测");
    });

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "所有机器人任务完成\n";
    return 0;
}
