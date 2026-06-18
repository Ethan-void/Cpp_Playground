#include "RobotManager.h"

#include <memory>

int main() {
    RobotManager manager;

    manager.addRobot(std::make_unique<Robot>("地面巡逻者", 45));
    manager.addRobot(std::make_unique<Robot>("天空守护者", 80));
    manager.addRobot(std::make_unique<Robot>("深海探索者", 20));

    manager.reportAll();

    manager.chargeLowBatteryRobots(50);

    manager.reportAll();
    return 0;
}

