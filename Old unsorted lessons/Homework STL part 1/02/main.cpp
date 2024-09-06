#include <iostream>
#include <list>

int main()
{
    std::list<int> list;

    std::cout << "[IN]: "<< std::endl;
    int num_of_elements;
    int num;
    std::cin >> num_of_elements;

    do{
        std::cin >> num;
        list.push_front(num);
        num_of_elements--;
    }while(num_of_elements != 0);

    list.sort(std::greater<int>());
    list.unique();

    std::cout << "[OUT]:" << std::endl;

    for (int elem : list) {
        std::cout << elem << std::endl;
    }

    return 0;
}
