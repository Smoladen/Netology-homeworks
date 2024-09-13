#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "safe_queue.h"

class thread_pool{
private:
    std::vector<std::thread> threads;
    std::mutex threadMutex;
    std::condition_variable condition;
    safe_queue<std::function<void()>> safeQueueOfWorks;
    std::atomic<bool> stop = false;
public:
    thread_pool(int numOfThreads){
        for(int i =0; i < numOfThreads; i++){
            threads.push_back(std::thread(&thread_pool::work, this));
        }
    }
    ~thread_pool(){
        for(auto& thread : threads)
                thread.join();
    }
    void work(){
        while(!stop){
            std::unique_lock<std::mutex> lockMutex(threadMutex);
            if(!safeQueueOfWorks.empty()){
                std::cout << "ID: " << std::this_thread::get_id() << std::endl;
                safeQueueOfWorks.front();
                safeQueueOfWorks.pop();
            }else{
                std::this_thread::yield();
            }
            lockMutex.unlock();
        }
    }
    void submit(std::vector<std::function<void()>> vectorFunctions, int countSubmits){
        for(int i = 0; i < countSubmits; i++){
            for(size_t j = 0; j < vectorFunctions.size(); j++){
                safeQueueOfWorks.push(vectorFunctions.at(j));
            }
        }
        stop = true;
    }

};
