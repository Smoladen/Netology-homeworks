#include <iostream>
#include <vector>
#include <algorithm>

void UniqueVector(std::vector<int>& numbers){
    sort(numbers.begin(),numbers.end());

    auto uniqIt = std::unique(numbers.begin(), numbers.end());

    numbers.erase(uniqIt,numbers.end());
}

int main()
{
    std::vector <int> numbers = {1,2,3,4,5,6,6,7,8,7,3,3};

    auto IteratorCounter = numbers.begin();

    std::cout << "[IN]: ";

    while(numbers.end() != IteratorCounter){
        std::cout << *IteratorCounter << ' ';
        IteratorCounter++;
    }

    UniqueVector(numbers);

    std::cout<<std::endl << "[OUT]: ";

    IteratorCounter = numbers.begin();

    while(numbers.end() != IteratorCounter){
        std::cout << *IteratorCounter << ' ';
        IteratorCounter++;
    }
    return 0;
}
