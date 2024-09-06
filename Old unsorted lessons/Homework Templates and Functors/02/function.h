#ifndef FUNCTION_HEADER
#define FUNCTION_HEADER
#include <iostream>
#include <vector>

struct Size {
    size_t rows;
    size_t cols;
};

template <typename T>
class table {
public:

    table(size_t rows, size_t cols) : data(rows, std::vector<T>(cols)), size{rows, cols} {}

    std::vector<T>& operator[](size_t row) {
        return data[row];
    }

    const std::vector<T>& operator[](size_t row) const {
        return data[row];
    }

    Size getSize() const {
        return size;
    }

private:
    std::vector<std::vector<T>> data;
    Size size;
};

#endif
