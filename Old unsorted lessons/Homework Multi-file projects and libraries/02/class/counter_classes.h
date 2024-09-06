#ifndef COUNTER_CLASSES_H
#define COUNTER_CLASSES_H

class Counter{

private:
    int num;
public:
    Counter(){
        num = 1;
    }
    Counter(int num){
        this->num = num;
    }
    void increment();
    void decrement();
    int value();
};

#endif
