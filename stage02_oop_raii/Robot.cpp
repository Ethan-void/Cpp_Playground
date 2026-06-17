#include "Robot.h"

#include <algorithm>

Robot::Robot(std::string name, int battery)
    : name_(std::move(name)), battery_(std::clamp(battery, 0, 100)) {}

const std::string& Robot::name() const {
    return name_;
}

int Robot::battery() const {
    return battery_;
}

void Robot::repair() {
    name_ += " (已维修)";
}

void Robot::charge() {
    battery_ = 100;
}

void Robot::consumeBattery(int amount) {
    battery_ = std::clamp(battery_ - amount, 0, 100);
}

void Robot::report() const {
    std::cout << "[机器人 " << name_ << "] 当前电量: " << battery_ << "%\n";
}

