#include <iostream>

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
    void increment(){
        num++;
    }
    void decrement(){
        num--;
    }
    int value(){
        return num;
    }
};

int main() {
    int number;
    std::string answer;
    char comand;
    Counter c;

    do{
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> answer;
        if(answer == "да"){
            std::cout << "Enter a number: ";
            std::cin >> number;
            c = Counter(number);
        }else if(answer == "нет"){

        }else{
            std::cout << "Вы ввели недопустимое значение." << std::endl;
        }}while(answer != "да" && answer != "нет");

    do{
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> comand;
        if(comand == '+'){
            c.increment();
        }else if(comand == '-'){
            c.decrement();
        }else if(comand == '='){
            std::cout << "Значение счётчика: " << c.value() << std::endl;
        }else if(comand != 'x'){
            std::cout << "Вы ввели недопустимое значение." << std::endl;
        }
    }while(comand != 'x');
    std::cout << "До свидания!";
    return 0;
}
