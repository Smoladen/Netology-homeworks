#include <iostream>
#include <vector>

template <typename T>
void move_vectors(std::vector<T>& source, std::vector<T>& destination){
    destination = std::move(source);
}


int main()
{

    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(one, two);

    // std::cout << "one: ";
    // for (const auto& str : one) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "two: ";
    // for (const auto& str : two) {
    //     std::cout << str << " ";
    // }
    // std::cout << std::endl;
    return 0;

}
