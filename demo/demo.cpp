#include "demo.hpp"
#include "math0520lib/mat.hpp"
#include "math0520lib/vec_operations.hpp"
#include <iostream>

void run_demo() {
    std::cout << "Hello, math0520! This is my demo for a basic C++ linear "
                 "algebra library."
              << '\n';

    std::cout << "Here's a big matrix of all zeroes:" << '\n';
    Mat<12, 11, float> mat;
    std::cout << mat << '\n';

    Mat<2, 2, float> mat1({{2, 2}, {1, 1}});

    mat1.copy_row_to_from(1, 0);
    std::cout << mat1.at(1, 1) << '\n';
    std::cout << mat1;

    std::vector<int> v{1, 2, 3};
    std::vector<int> u{4, 5, 6};
    std::cout << "v: " << v;
    std::cout << "u: " << u;
    std::cout << "dot product: " << dot(v, u) << '\n';
    std::cout << "cross product: " << cross(v, u) << '\n';
}
