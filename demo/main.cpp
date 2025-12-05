#include "math0520lib/mat.hpp"
#include <iostream>

int main(int argc, char** argv) {
    Mat<12, 11, float> mat;
    std::cout << "Hello, math0520" << '\n';
    std::cout << mat.row_count() << '\n';
    std::cout << mat.at(1, 1) << '\n';
    Mat<2, 2, float> mat1({{2, 2}, {2, 2}});
    std::cout << mat1.at(1, 1) << '\n';
    return 0;
}
