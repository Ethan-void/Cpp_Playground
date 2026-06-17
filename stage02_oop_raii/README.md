# 阶段 2：封装 + RAII

这个阶段的目标是把“能跑的类”改造成“更像现代 C++ 的类”。

你要重点看：

- 成员变量为什么改成 `private`
- 为什么外部不能直接写 `robot.battery = 100`
- 为什么用 `std::unique_ptr` 表示“这个机器人只归一个管理器拥有”
- 为什么删除 `new/delete`
- `const` 成员函数是什么意思

核心思想：

```text
对象自己管理自己的状态。
资源交给智能指针管理。
外部通过清晰的函数接口操作对象。
```

编译运行：

```bash
cmake -S . -B build
cmake --build build
./build/stage02_oop_raii
```

阅读顺序：

1. `Robot.h`
2. `Robot.cpp`
3. `RobotManager.h`
4. `RobotManager.cpp`
5. `main.cpp`

