#include "Systems.h"

void repairRobot(Robot* r) {
    if (r) {
    std::cout << "[维修工] 正在维修机器人 " << r->name << "..." << std::endl;
    r->name = r->name + " (已维修)";
    std::cout << "[维修工] 维修完成！" << std::endl;
    } else {
        std::cout << "[维修工] 机器人指针为空，无法维修。" << std::endl;
    }
};

void chargeRobot(Robot& r) {
    std::cout << "[充电站] 正在为机器人 " << r.name << " 充电..." << std::endl;
    r.battery=100;
    r.name=r.name+" (已充电)";
    std::cout << "[充电站] 充电完成！ 当前电量: " << r.battery << "%" << std::endl;
};

void updateRobot(const std::shared_ptr<Robot>& r) {
    if (r) {
        std::cout << "[工程师] 正在升级机器人 " << r->name << "..." << std::endl;
        r->name = r->name + " (已升级)";
        std::cout << "[工程师] 升级完成！" << std::endl;
    } else {
        std::cout << "[工程师] 机器人智能指针为空，无法升级。" << std::endl;
    }
};

namespace Car{
    Car::Car(std::string n) : name(n) {}
    void Car::report() const {
        std::cout << "[小车 " << name << "] 当前状态: 已启动" << std::endl;
    }
    Car::~Car() {
        std::cout << "[小车 " << name << "] 被销毁了。" << std::endl;
    }
}
