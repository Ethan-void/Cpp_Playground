#pragma once

#include <iostream>
#include <string>

class Robot {
public:
    Robot(std::string name, int battery);

    // 这些函数只读取对象状态，所以函数末尾加 const。
    const std::string& name() const;
    int battery() const;

    // 这些函数会修改对象状态，所以不加 const。
    void repair();
    void charge();
    void consumeBattery(int amount);
    void report() const;

private:
    // private 表示外部不能随便改，必须通过成员函数改。
    std::string name_;
    int battery_;
};

