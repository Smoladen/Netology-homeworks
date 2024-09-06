#include <iostream>
#include "function.h"


int main() {

    table<int> test(2, 3);

    test[0][0] = 4;

    std::cout << test[0][0] << std::endl; // выводит 4

    Size size = test.getSize();
    std::cout << "Rows: " << size.rows << ", Cols: " << size.cols << std::endl; // выводит "Rows: 2, Cols: 3"

    return 0;
}
