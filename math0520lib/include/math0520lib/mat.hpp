#ifndef MATH0520LIB_MAT_HPP
#define MATH0520LIB_MAT_HPP
#include <array>
#include <cstddef>
#include <initializer_list>
#include <sstream>
#include <stdexcept>
#include <type_traits>
#include <vector>

/**
 * simple matrix class supporting basic row operations
 *
 * supports all standard numeric types via templates
 *
 * interally composed of an std::array of rows, where each row is a vector (for
 * easy row swapping)
 *
 * template params: H (height). W (width). T (numeric type)
 */
template <size_t H, size_t W, typename T>
    requires std::is_integral_v<T> || std::is_floating_point_v<T>
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

    // get the value of entry located at the zero-indexed entry given by (row,
    // col)
    T at(size_t row, size_t col) {
        if (row >= H || col >= W) {
            throw std::out_of_range(
                "out of bounds reading matrix entry: Mat::at");
        }
        return rows.at(row).at(col);
    }

    // swap specified zero-indexed rows (a, b)
    void swap_rows(size_t a, size_t b) {
        if (a >= H || b >= H) {
            throw std::out_of_range(
                "out of bounds reading matrix entry: Mat::swap_rows");
        }
        std::vector<T> temp = std::move(rows.at(b));
        rows.at(b) = std::move(rows.at(a));
        rows.at(a) = std::move(temp);
    }

    // copy a row to the first paramter, from the second paramter
    //
    // each paramter should reference a zero-indexed row
    void copy_row_to_from(size_t to, size_t from) {
        if (from >= H || to >= H) {
            throw std::out_of_range(
                "out of bounds reading matrix entry: Mat::copy_row");
        }
        rows.at(to) = rows.at(from);
    }

    // get the row count of the matrix
    size_t row_count() { return H; }

    // get the column count of the matrix
    size_t col_count() { return W; }

    // get the string representation of the matrix
    std::string to_string() const {
        std::stringstream sstr;
        for (const auto& row : rows) {
            sstr << '{';
            for (size_t i = 0; i < row.size(); i++) {
                sstr << row.at(i);
                if (i < row.size() - 1) {
                    sstr << ", ";
                }
            }
            sstr << "}\n";
        }

        return sstr.str();
    }

    /**
     * move a row of type vector<T> into the matrix
     * the length of the row must match the dimensions of the matrix
     */
    void move_row_into(size_t row_idx, const std::vector<T>&& row) {
        if (row.size() != W) {
            throw std::out_of_range("invalid size when trying to move row into "
                                    "matrix: Mat::move_row_into");
        }
        if (row_idx >= H) {
            throw std::out_of_range("invalid row_idx to move into specified for"
                                    "matrix: Mat::move_row_into");
        }
        rows.at(row_idx) = row;
    }

    /**
     * copy a row of type vector<T> into the matrix
     * the length of the row must match the dimensions of the matrix
     *
     * this is slower than Mat::move_row_into, but is preferred if the row you
     * want to add into the matrix is an expiring value
     */
    void copy_row_into(size_t row_idx, const std::vector<T>& row) {
        if (row.size() != W) {
            throw std::out_of_range("invalid size when trying to copy row into "
                                    "matrix: Mat::move_row_into");
        }
        if (row_idx >= H) {
            throw std::out_of_range("invalid row_idx to copy into specified for"
                                    "matrix: Mat::move_row_into");
        }
        rows.at(row_idx) = row;
    }
};

// overload allowing easy cout interop with the Mat class
template <size_t H, size_t W, typename T>
std::ostream& operator<<(std::ostream& os, const Mat<H, W, T> mat) {
    os << mat.to_string();
    return os;
}
#endif // !MATH0520LIB_MAT_HPP
