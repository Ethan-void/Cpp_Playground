#include <iostream>
#include <optional>
#include <string>
#include <type_traits>
#include <variant>
#include <vector>

enum class RobotType {
    Ground,
    Flying,
    Swimming
};

struct RobotConfig {
    std::string name;
    RobotType type;
    std::optional<int> battery;
};

struct BatteryLow {
    std::string robotName;
    int battery;
};

struct Damaged {
    std::string robotName;
    std::string part;
};

struct MissionComplete {
    std::string robotName;
    std::string mission;
};

using RobotEvent = std::variant<BatteryLow, Damaged, MissionComplete>;

std::string typeName(RobotType type) {
    switch (type) {
    case RobotType::Ground:
        return "地面机器人";
    case RobotType::Flying:
        return "飞行机器人";
    case RobotType::Swimming:
        return "水下机器人";
    }
    return "未知机器人";
}

void printConfig(const RobotConfig& config) {
    int battery = config.battery.value_or(100);
    std::cout << config.name << " | " << typeName(config.type) << " | " << battery << "%\n";
}

void handleEvent(const RobotEvent& event) {
    std::visit([](const auto& e) {
        using Event = std::decay_t<decltype(e)>;

        if constexpr (std::is_same_v<Event, BatteryLow>) {
            std::cout << e.robotName << " 电量过低: " << e.battery << "%\n";
        } else if constexpr (std::is_same_v<Event, Damaged>) {
            std::cout << e.robotName << " 部件损坏: " << e.part << "\n";
        } else if constexpr (std::is_same_v<Event, MissionComplete>) {
            std::cout << e.robotName << " 完成任务: " << e.mission << "\n";
        }
    }, event);
}

int main() {
    std::vector<RobotConfig> configs{
        {"地面巡逻者", RobotType::Ground, 60},
        {"天空守护者", RobotType::Flying, std::nullopt},
        {"深海探索者", RobotType::Swimming, 25},
    };

    std::cout << "机器人配置:\n";
    for (const auto& config : configs) {
        printConfig(config);
    }

    std::vector<RobotEvent> events{
        BatteryLow{"深海探索者", 25},
        Damaged{"天空守护者", "左翼"},
        MissionComplete{"地面巡逻者", "巡逻 A 区"},
    };

    std::cout << "\n机器人事件:\n";
    for (const auto& event : events) {
        handleEvent(event);
    }

    return 0;
}
