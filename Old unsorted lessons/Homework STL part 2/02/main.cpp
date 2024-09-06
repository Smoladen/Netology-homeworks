#include <iostream>
#include <set>
#include <list>
#include <vector>

template <typename Container>
void print_container(const Container& container){
    for(auto It = container.begin(); It != container.end(); It++){
        if(It != container.begin())
            std::cout << ", ";
        std::cout << *It;
    }
    std::cout << std::endl;
}


int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set); // four one three two. помните почему такой порядок? :)

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector); // one, two, three, four
    return 0;
}
