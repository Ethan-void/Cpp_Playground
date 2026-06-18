#include <iostream>
#include <string>
#include <utility>
#include <vector>

class RobotTask {
public:
    RobotTask(std::string name, int cost) : name_(std::move(name)), cost_(cost) {}

    // 任务有唯一身份，所以这里故意禁止复制。
    RobotTask(const RobotTask&) = delete;
    RobotTask& operator=(const RobotTask&) = delete;//？为什么要删除复制构造函数和复制赋值运算符？因为每个任务应该有唯一的身份，禁止复制可以避免误操作导致多个任务指向同一个资源。

    // 允许移动，让任务可以从一个队列转移到另一个队列。
    RobotTask(RobotTask&&) noexcept = default;
    RobotTask& operator=(RobotTask&&) noexcept = default;

    const std::string& name() const {
        return name_;
    }

    int cost() const {
        return cost_;
    }

private:
    std::string name_;
    int cost_;
};

void printTasks(const std::string& title, const std::vector<RobotTask>& tasks) {
    std::cout << title << "\n";
    for (const auto& task : tasks) {
        std::cout << "- " << task.name() << "，耗电 " << task.cost() << "%\n";
    }
}

int main() {
    std::vector<RobotTask> pending;
    std::vector<RobotTask> running;
    std::vector<RobotTask> done;

    pending.emplace_back("巡逻 A 区", 10);
    pending.emplace_back("检查仓库", 20);

    printTasks("待执行任务:", pending);

    // 把 pending 中最后一个任务移动到 running。
    running.push_back(std::move(pending.back()));
    // 移动后删除原来的任务，避免重复任务。
    pending.pop_back();

    printTasks("\n执行中的任务:", running);
    printTasks("剩余待执行任务:", pending);

    done.push_back(std::move(running.back()));
    running.pop_back();

    printTasks("\n已完成任务:", done);
    return 0;
}
 
