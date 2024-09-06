#include <iostream>
#include "../class/math_functions.h"

int main() {
    int double1, double2;
    int operation;
    std::cout << "Enter the first number: ";
    std::cin >> double1;
    std::cout << "Enter the second number: ";
    std::cin >> double2;

    std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;
    if(operation == 1){
        std::cout << "Результат сложения: " << addition(double1,double2);
    }else if(operation == 2){
        std::cout << "Результат вычитания: " << subtraction(double1, double2);
    }else if(operation == 3){
        std::cout << "Результат умножения: " << multiplication(double1, double2);
    }else if(operation == 4){
        std::cout << "Результат деления: " << division(double1, double2);
    }else if(operation == 5){
        std::cout << "Результат возведения в степень: " << power(double1, double2);
    }else
        std::cout << "Неверный ввод";

}
