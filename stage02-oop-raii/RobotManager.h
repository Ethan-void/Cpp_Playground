#pragma once

#include "Robot.h"

#include <memory>
#include <vector>

class RobotManager {
public:
    void addRobot(std::unique_ptr<Robot> robot);
    void reportAll() const;
    void chargeLowBatteryRobots(int threshold);

private:
    // unique_ptr 表示 RobotManager 独占这些机器人。
    std::vector<std::unique_ptr<Robot>> robots_;
};

