# 阶段 4：移动语义

这个阶段学习 `std::move` 和“所有权转移”。

你要重点看：

- 为什么有些对象可以移动，但不允许复制
- `std::move` 不是移动本身，而是告诉编译器“这个对象可以被搬走”
- `std::unique_ptr` 为什么必须移动
- 任务从 `pending` 移动到 `running`，再移动到 `done`

核心思想：

```text
复制是再做一份。
移动是把原来的资源交出去。
```

编译运行：

```bash
cmake -S . -B build
cmake --build build
./build/stage04_move_semantics
```

