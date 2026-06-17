#include "Robot.h"

using namespace std;

Robot::Robot(string n, int b) : name(n), battery(b) {}

void Robot::report() const {
    cout << "[机器人 " << name << "] 当前电量: " << battery << "%" << endl;
}

Robot::~Robot() {
    cout << "[机器人 " << name << "] 被销毁了。" << endl;
}