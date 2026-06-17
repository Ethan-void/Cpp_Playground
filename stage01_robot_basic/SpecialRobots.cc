#include "SpecialRobots.h"
namespace Multifunctional {
    FlyingRobot::FlyingRobot(std::string n, int b, int w) : Robot(n, b), wings(w) {}
        
    void FlyingRobot::report() const  { 
        std::cout << "[飞行机器人 " << name << "] 当前电量: " << battery << "%, 翼展: " << wings << "片" << std::endl;
    }

    SwimmingRobot::SwimmingRobot(std::string n, int b, int f) : Robot(n, b), fins(f) {}     

    void SwimmingRobot::report() const {
        std::cout << "[水下机器人 " << name << "] 当前电量: " << battery << "%, 鳍数: " << fins << "片" << std::endl;
    }
}