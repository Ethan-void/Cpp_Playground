#pragma once

#include <iostream>
#include <string>

class Robot {
public:
    std::string name;
    int battery;
    Robot(std::string n, int b);
    virtual void report() const;
    virtual ~Robot();
};