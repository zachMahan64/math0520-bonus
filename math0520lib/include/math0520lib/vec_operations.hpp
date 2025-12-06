#ifndef MATH0520LIB_VEC_HPP
#define MATH0520LIB_VEC_HPP

#include <stdexcept>
#include <type_traits>
#include <vector>
template <class T>
    requires std::is_integral_v<T> || std::is_floating_point_v<T>
[[nodiscard]] T dot(std::vector<T>& v, std::vector<T>& u) {
    if (v.size() != u.size()) {
        throw std::logic_error(
            "lengths of vectors do not match when taking dot product");
    }
    std::vector<T> w;
    w.reserve(v.size());

    T accum;
    for (size_t i = 0; i < v.size(); i++) {
        accum += v[i] * u[i];
    }
    return accum;
}

#endif // !MATH0520LIB_VEC_HPP
