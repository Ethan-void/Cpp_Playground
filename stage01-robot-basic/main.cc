#include <vector>  
#include <algorithm>
#include "CLI11.hpp"
#include "Robot.h"
#include "SpecialRobots.h"
#include "Systems.h"                                     

int main(int argc, char** argv) {
    std::vector<std::shared_ptr<Robot>> robots;  

    // std::vector<std::shared_ptr<Robot>> robots2;
    // 1. 定义命令行解析器
    CLI::App app{"机器人管理系统 - 终端控制版"};

    // 2. 设置可配置的参数变量（带默认值）
    std::string robotName = "默认巡逻者";
    int robotBattery = 80;
    int wingCount = 0; // 如果大于0，我们就创建一个飞行机器人
    int fins = 0; // 如果大于0，我们就创建一个水下机器人

    // 3. 配置选项
    app.add_option("-n,--name", robotName, "设置初始机器人的名字");
    app.add_option("-b,--battery", robotBattery, "设置初始机器人的电量 (0-100)");
    app.add_option("-w,--wings", wingCount, "设置翼展数量（若设置则创建飞行机器人）");
    app.add_option("-f,--fins",fins,"设置鳍数（若设置则创建水下机器人）");

    // 4. 执行解析
    // 如果输入 --help 或参数错误，程序会自动打印帮助信息并退出
    CLI11_PARSE(app, argc, argv);

    if (wingCount > 0) {
        robots.push_back(std::make_shared<Multifunctional::FlyingRobot>(robotName, robotBattery, wingCount));
    } else if (fins > 0) {
        robots.push_back(std::make_shared<Multifunctional::SwimmingRobot>(robotName, robotBattery, fins));
    } else {
        robots.push_back(std::make_shared<Robot>(robotName, robotBattery));
    }

    robots.push_back(std::make_shared<Robot>("地面巡逻者", 50));
    robots.push_back(std::make_shared<Multifunctional::FlyingRobot>("天空守护者", 60, 4));
    robots.push_back(std::make_shared<Multifunctional::SwimmingRobot>("深海探索者", 70, 2));

    std::cout << "=== 机器人状态 ===" << std::endl;
    for (const auto& robot : robots) {
        robot->report();  // 多态调用
    };

    std::cout << std::endl << "=== 机器人维修系统启动 ===" << std::endl;
    repairRobot(robots[0].get());
    std::cout << "=== 维修完成 ===" << std::endl << std::endl;

    std::cout << "=== 机器人充电系统启动 ===" << std::endl;
    chargeRobot(*robots[1]);
    std::cout << "=== 充电完成 ===" << std::endl << std::endl; 

    std::cout << "=== 机器人升级系统启动 ===" << std::endl;
    updateRobot(robots[2]);
    std::cout << "=== 升级完成 ===" << std::endl<< std::endl;

    std::cout << "=== 通用维修系统启动 ===" << std::endl;
    repair(*robots[3]);
    Car::Car myCar1("car1");
    repair(myCar1);
    Car::Car *myCar2 = new Car::Car("car2");
    repair(*myCar2);
    delete myCar2;  // 手动释放内存
    std::cout << "=== 通用维修完成 ===" << std::endl << std::endl;

    std::cout << "=== 机器人状态 ===" << std::endl;
    for (const auto& robot : robots) {
        robot->report(); 
    };


    std::vector<int> num1{5, 3, 8, 1, 4}, num2{10, 20, 15, 5, 25}, num3{5, 3, 8, 1, 3};
    
    std::cout << std::endl << "=== compare1 ===" << std::endl;
    std::cout<<compare::compare1(num1[0], num2[0])<<std::endl;
    std::cout<<compare::compare1(num1, num3)<<std::endl;

    std::cout << "=== compare2 ===" << std::endl;
    std::cout<<compare::compare2(num1, num2)<<std::endl;
    std::cout<<compare::compare2(num1, num3)<<std::endl;

    std::cout << "=== 自动销毁（倒序） ===" << std::endl;
    
    // sort(robots.begin(), robots.end(), [](const shared_ptr<Robot>& a, const shared_ptr<Robot>& b) {
    //     return a->battery > b->battery;  
    // });
    // sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
    //     return a.name < b.name;  
    // });

    return 0;
}