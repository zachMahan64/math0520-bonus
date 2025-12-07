// math0520lib
// https://github.com/zachMahan64/math0520lib
// 2025
// Created by Zach Mahan

#include "demo.hpp"
#include <exception>
#include <iostream>

int main(int argc, char** argv) {
    try {
        run_demo();
    } catch (const std::exception& e) {
        std::cerr << "\n[ERROR] There were some issues when running your code:"
                  << '\n';
        std::cerr << e.what() << '\n';
    }
    return 0;
}
