#include <cassert>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class Robot {
public:
    Robot(std::string name, int battery) : name_(std::move(name)), battery_(battery) {
        if (name_.empty()) {
            throw std::invalid_argument("机器人名字不能为空");
        }
        if (battery_ < 0 || battery_ > 100) {
            throw std::invalid_argument("电量必须在 0 到 100 之间");
        }
    }

    const std::string& name() const {
        return name_;
    }

    int battery() const {
        return battery_;
    }

    void charge(int amount) {
        if (amount < 0) {
            throw std::invalid_argument("充电量不能是负数");
        }
        battery_ += amount;
        if (battery_ > 100) {
            battery_ = 100;
        }
    }

private:
    std::string name_;
    int battery_;
};

void testChargeDoesNotExceed100() {
    Robot robot("测试机器人", 80);
    robot.charge(50);
    assert(robot.battery() == 100);
}

void testInvalidBatteryThrows() {
    bool thrown = false;

    try {
        Robot robot("坏数据机器人", 150);
    } catch (const std::invalid_argument& error) {
        std::cout << "Caught expected exception: " << error.what() << "\n";
        thrown = true;
    }

    assert(thrown);
}

void testEmptyNameThrows() {
    bool thrown = false;

    try {
        Robot robot("", 50);
    } catch (const std::invalid_argument& error) {
        thrown = true;
        std::cout << "Caught expected exception: " << error.what() << "\n";
    }

    assert(thrown);
}

int main() {
    testChargeDoesNotExceed100();
    testInvalidBatteryThrows();
    testEmptyNameThrows();

    std::cout << "所有测试通过\n";
    return 0;
}
