#include "RobotManager.h"

#include <iostream>

void RobotManager::addRobot(std::unique_ptr<Robot> robot) {
    if (robot) {
        robots_.push_back(std::move(robot));
    }
}

void RobotManager::reportAll() const {
    for (const auto& robot : robots_) {
        robot->report();
    }
}

void RobotManager::chargeLowBatteryRobots(int threshold) {
    for (const auto& robot : robots_) {
        if (robot->battery() < threshold) {
            std::cout << "给 " << robot->name() << " 充电\n";
            robot->charge();
        }
    }
}

