# 阶段 5：现代类型工具

这个阶段学习用类型表达业务含义。

你要重点看：

- `enum class`：比普通 enum 更安全
- `std::optional`：可能有值，也可能没有值
- `std::variant`：一个变量可以是几种类型之一
- `std::visit`：处理 variant 中真正存着的类型

核心思想：

```text
不要用一堆 int 和 string 硬猜含义。
让类型本身表达“这里可能没有值”或“这里有几种事件”。
```

编译运行：

```bash
cmake -S . -B build
cmake --build build
./build/stage05_modern_types
```

