# C++ 阶段式项目学习路线

这个目录是一套按阶段推进的现代 C++ 小项目。每个阶段都是独立项目，都有自己的 `CMakeLists.txt`、源码和 `README.md`。

建议学习顺序：

1. `stage02-oop-raii`：封装、RAII、`unique_ptr`
2. `stage03-stl-algorithms`：STL 算法、lambda、排序和筛选
3. `stage04-move-semantics`：移动语义、`std::move`、禁止拷贝
4. `stage05-modern-types`：`optional`、`variant`、`enum class`
5. `stage06-testing-errors`：错误处理、简单测试、断言
6. `stage07-concurrency`：线程、互斥锁、异步任务

每个阶段的通用编译方式：

```bash
cd stage02-oop-raii
cmake -S . -B build
cmake --build build
./build/stage02_oop_raii
```

把 `stage02-oop-raii` 换成对应目录名，把 `stage02_oop_raii` 换成对应可执行文件名即可。

