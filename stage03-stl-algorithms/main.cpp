#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Robot {
    std::string name;
    int battery;
    std::string type;
};

void printRobots(const std::vector<Robot>& robots) {
    for (const auto& robot : robots) {
        std::cout << robot.name << " | " << robot.type << " | " << robot.battery << "%\n";
    }
}

int main() {
    std::vector<Robot> robots{
        {"地面巡逻者", 45, "ground"},
        {"天空守护者", 80, "flying"},
        {"深海探索者", 20, "swimming"},
        {"仓库助手", 60, "ground"},
    };

    std::cout << "原始顺序:\n";
    printRobots(robots);

    std::sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
        return a.battery < b.battery;
    });

    std::cout << "\n按电量从低到高排序:\n";
    printRobots(robots);

    auto lowBattery = std::find_if(robots.begin(), robots.end(), [](const Robot& robot) {
        return robot.battery < 30;
    });

    if (lowBattery != robots.end()) {
        std::cout << "\n第一个低电量机器人: " << lowBattery->name << "\n";
    }

    int groundCount = std::count_if(robots.begin(), robots.end(), [](const Robot& robot) {
        return robot.type == "ground";
    });

    std::cout << "地面机器人数量: " << groundCount << "\n";

    std::for_each(robots.begin(), robots.end(), [](Robot& robot) {
        if (robot.battery < 50) {
            robot.battery = 100;
        }
    });

    std::cout << "\n低电量机器人充电后:\n";
    printRobots(robots);
    return 0;
}

