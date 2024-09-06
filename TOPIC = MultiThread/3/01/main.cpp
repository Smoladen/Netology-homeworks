#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <algorithm>

void findMinimal(std::vector<int>& vector, int start, std::promise<int> prom){
    int minimalNumberId = start;
    for(int i =start+1; i < vector.size(); i++ ){
        if(vector[i] < vector[minimalNumberId]){
            minimalNumberId = i;
        }
    }

    prom.set_value(minimalNumberId);
}



int main()
{
    std::vector<int> v = {11, 23, 15, 5, 6, 88, 37, 2, 99, 1};
    int minimalNumber;

    for(int i =0; i <v.size(); i++){
        std::promise<int> prom;
        std::future<int> fut = prom.get_future();

        std::thread(findMinimal, std::ref(v), i, std::move(prom)).detach();

        minimalNumber = fut.get();

        std::swap(v[i], v[minimalNumber]);
    }


    for(int i =0; i < 10; i++){
        std::cout << v[i] << ' ';
    }
    return 0;
}
