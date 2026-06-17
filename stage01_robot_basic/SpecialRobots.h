#pragma once

#include "Robot.h"
namespace Multifunctional {
    class FlyingRobot : public Robot {
    public:
        int wings;
        FlyingRobot(std::string n, int b, int w); 
        void report() const override;
    };

    class SwimmingRobot : public Robot {
    public:
        int fins;
        SwimmingRobot(std::string n, int b, int f);    
        void report() const override;
    };
}