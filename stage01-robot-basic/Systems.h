#pragma once

#include "Robot.h"
#include <memory>

void repairRobot(Robot* r);
void chargeRobot(Robot& r);
void updateRobot(const std::shared_ptr<Robot>& r);

template <typename T>
void repair(T& machine){
    std::cout << "[通用维修工] 正在维修 " << machine.name << "..." << std::endl;
    machine.name = machine.name + " (已维修)";
}

namespace Car{
    class Car {
    public:
        std::string name;    
        Car(std::string n);
        void report() const;
        ~Car();
    };
}

namespace compare{
    template <typename T>
    int compare1(const T& a, const T& b) {
        if (a > b) return 1;
        if (a < b) return -1;
        return 0;
    }

    template <typename T>
    int compare2(const std::vector<T>& v1, const std::vector<T>& v2) {
        if (v1.size() > v2.size()) return 1;
        if (v1.size() < v2.size()) return -1;
        for (size_t i = 0; i < v1.size(); ++i) {
            if (v1[i] > v2[i]) return 1;
            if (v1[i] < v2[i]) return -1;
        }
        return 0;
    }
}