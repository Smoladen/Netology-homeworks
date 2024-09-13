#include <iostream>
#include <thread>
#include <future>
#include "thread_pool.h"


void doWork1() {
    std::cout << "Function: " << __FUNCTION__ << " completed!" << std::endl;
}

void doWork2() {
    std::cout << "Function: " << __FUNCTION__ << " completed!" << std::endl;
}

int main(int argc, char** argv) {

    const int cores = std::thread::hardware_concurrency();
    std::vector<std::function<void()>> vectorOfFunctions{ doWork1, doWork2 };
    int countSubmits = 8;
    thread_pool ThreadPool{ cores };


    std::thread thread1(&thread_pool::submit, &ThreadPool, vectorOfFunctions, countSubmits);
    thread1.join();

    return 0;
}
