# 阶段 7：并发基础

这个阶段学习多个机器人“同时工作”。

你要重点看：

- `std::thread`：创建线程
- `join()`：等待线程结束
- `std::mutex`：保护共享数据
- `std::lock_guard`：自动加锁和解锁
- 为什么多个线程同时改同一个变量会有风险

核心思想：

```text
多个线程可以同时干活。
共享数据必须保护。
锁要尽量交给 RAII 对象管理。
```

编译运行：

```bash
cmake -S . -B build
cmake --build build
./build/stage07_concurrency


```

test-branch