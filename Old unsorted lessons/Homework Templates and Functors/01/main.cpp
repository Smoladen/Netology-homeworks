#include <iostream>
#include <vector>
#include "function.h"

using namespace std;

int main()
{

    std::cout << "[IN]" << 5 << std::endl;
    std::cout << "[OUT]" << square(5)<< std::endl;

    std::vector<int> v{ -1, 2, 3 };

    std::cout << "[IN]";
    for (int i = 0; i < v.size(); i ++){
        std::cout << v[i] << ", ";
    }
    std::cout << std::endl;
    std::cout << "[OUT]";
    v = square(v);
    for (int i = 0; i < v.size(); i ++){
        std::cout << v[i] << ", ";
    }

    return 0;
}
