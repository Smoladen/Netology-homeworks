#include <iostream>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

void power(int& val){
    val*= val;
}

template<typename Id>
void my_for_each(Id begin, Id end/* void (*test)(int)*/){
    int req_chunk_size =2;
    int chunk_size = std::distance(begin,end);

    if(chunk_size <= req_chunk_size){
        std::for_each(begin,end,power);
    }else{
        auto middle = begin;
        std::advance(middle, chunk_size / 2);

        std::future<void> devide = std::async(std::launch::async, my_for_each<Id>, begin, middle);
        my_for_each(middle,end);

        devide.get();

    }

}

int main()
{
    std::vector v = {1,3,4,56,23,22,2,6,15,2};

    my_for_each(v.begin(),v.end());

    for(int i = 0; i< 10; i++){
        std::cout << v[i] << ' ';
    }
    return 0;
}
