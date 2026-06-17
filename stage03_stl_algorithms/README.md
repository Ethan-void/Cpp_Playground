# 阶段 3：STL 算法 + lambda

这个阶段练习“少写手动循环，多用标准算法”。

你要重点看：

- `std::sort`：排序
- `std::find_if`：查找符合条件的元素
- `std::count_if`：统计符合条件的元素数量
- `std::for_each`：对每个元素执行操作
- lambda：临时写一个小函数

核心思想：

```text
vector 负责存数据。
algorithm 负责处理数据。
lambda 负责描述条件或动作。
```

编译运行：

```bash
cmake -S . -B build
cmake --build build
./build/stage03_stl_algorithms
```

