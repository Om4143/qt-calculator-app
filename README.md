# Qt Calculator App

A basic desktop calculator built with Qt Widgets and CMake. Supports
addition, subtraction, multiplication, and division through a simple
button-based UI.

## How it works

- `mainwindow.ui` defines the button/display layout (Qt Designer form)
- `mainwindow.h/.cpp` holds the logic: digit input, picking an operator,
  computing the result on equals, and clearing
- `main.cpp` just launches the `QApplication` and shows the window

Basic flow: press digits to build a number, press an operator to store it
and wait for the second number, then press `=` to compute. Division by
zero shows "Error" instead of crashing.

## Build

Requires Qt 6 (or Qt 5) with the Widgets module, CMake 3.16+, and a C++17
compiler.

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

Or open `CMakeLists.txt` directly in Qt Creator and hit Run.

## Notes

Built and tested with Qt 6.11 on macOS.
