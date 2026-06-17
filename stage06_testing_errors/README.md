# 阶段 6：错误处理 + 简单测试

这个阶段学习“程序不只要能跑，还要能证明自己跑对了”。

你要重点看：

- 构造函数里检查非法参数
- `throw std::invalid_argument` 表示参数不合法
- `try/catch` 捕获错误
- `assert` 做最简单的测试
- 测试函数不靠眼睛看输出，而是自动判断结果

核心思想：

```text
正常路径要写。
错误路径也要写。
写完以后要能自动检查。
```

编译运行：

```bash
cmake -S . -B build
cmake --build build
./build/stage06_testing_errors
```

