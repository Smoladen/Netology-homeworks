#pragma once
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

template<class T>
class safe_queue{
private:
    std::queue<T> queueOfWorks;
    std::mutex queueMutex;
    std::condition_variable cond_variable;
public:
    void push(T work){
        std::lock_guard<std::mutex> lockMutex(queueMutex);
        queueOfWorks.push(work);
        cond_variable.notify_one();
    };

    T pop(){
        std::unique_lock<std::mutex> lockMutex(queueMutex);
        cond_variable.wait(lockMutex, [this](){return !queueOfWorks.empty();});
        T work = std::move(queueOfWorks.front());
        queueOfWorks.pop();
        return work;
    }
    bool empty(){
        std::lock_guard<std::mutex> lock(queueMutex);
        return queueOfWorks.empty();
    }
    void front(){
    std::lock_guard<std::mutex> lock(queueMutex);
    queueOfWorks.front()();
    }

};
