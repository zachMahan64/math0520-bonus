#ifndef MATH0520LIB_MAT_HPP
#define MATH0520LIB_MAT_HPP
#include <array>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>
#include <vector>

/**
 * simple matrix class supporting basic options
 *
 * template params: H (height). W (width). T (numeric type)
 */
template <size_t H, size_t W, typename T>
    requires std::is_floating_point_v<T> || std::is_integral_v<T>
class Mat {
  private:
    std::array<std::vector<T>, H> rows{};

  public:
    Mat() {
        // zero init
        for (auto& row : rows) {
            row = std::vector<T>(W);
        }
    }

    Mat(const std::initializer_list<std::initializer_list<T>>& lists) {
        if (lists.size() != H) {
            throw std::runtime_error(
                "invalid row length when constructing Mat");
        }
        size_t i = 0;
        for (const auto& list : lists) {
            if (list.size() != W) {
                throw std::runtime_error(
                    "invalid column length when constructing Mat");
            }

            rows[i] = std::vector<T>(list.begin(), list.end());
            i++;
        }
    }

    T at(size_t row, size_t col) {
        if (row >= H || col >= W) {
            throw std::out_of_range(
                "out of bounds reading matrix entry: Mat::at");
        }
        return rows.at(row).at(col);
    }
    size_t row_count() { return H; }
    size_t col_count() { return W; }
};
#endif // !MATH0520LIB_MAT_HPP
