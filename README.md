# DCS111

中山大学数据科学与计算机学院课程「程序设计Ⅰ」课程作业某班某学生代码

提供了丰富的C语言代码和一个非常好用的[Visual Studio Code](https://code.visualstudio.com/)配置。

- 保证所有代码均可通过VMatrix评测，文件名即题号。
- Visual Studio Code 配置支持编译和调试。

## Visual Studio Code 配置说明

### 依赖

需要先安装以下插件：

- [CodeLLDB](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb)
- [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

另外需要操作系统有可用的 `clang` 和 `lldb`。也可以非常简单地修改配置文件来使用 `gcc` & `gdb`。

需要有*nix支持的shell或系统。未在Windows下测试。

### 使用

**单文件作业**

- 直接运行即可。

**多文件作业**

构建系统被配置为自动包括同名目录下所有相同拓展名的文件。例如，当打开 `6196.c` 时，运行前的编译会自动包括 `6196.c` 和 `6196` 文件夹下所有的 `.c` 文件。

这个特性主要是为了支持锁部分文件的题目。注意：运行的启动文件可以不包含任何文件，仅仅作为启动的占位符让配置检测到要包括的文件，就像 `6196.c` 一样。

可以参考 `6196` 的代码。
