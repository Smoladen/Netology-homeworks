#include <iostream>

class Calculator
{
private:
    double num1;
    double num2;

public:
    // Calculator(double num1, double num2){
    //     this->num1 = num1;
    //     this->num2 = num2;
    // }
    double add(){
        return num1 + num2;
    }
    double multiply(){
        return num1 * num2;
    }
    double subtract_1_2(){
        return num1 - num2;
    }
    double subtract_2_1(){
        return num2 - num1;
    }
    double divide_1_2(){
        return num1 / num2;
    }
    double divide_2_1(){
        return num2 / num1;
    }
    bool set_num1(double num1){
        if(num1 != 0){
            this->num1 = num1;
            return true;
        }
        else{
            std::cout << "Неверный ввод!" << std::endl;
            return false;
        }
    }
    bool set_num2(double num2){
        if(num2 != 0){
            this->num2 = num2;
            return true;
        }
        else{
            std::cout << "Неверный ввод!" << std::endl;
            return false;
        }
    }
};

int main()
{
    //Calculator callCalc(printNum1, printNUm2);
    Calculator callCalc;

    while(true){
        double printNum1;
        double printNum2;

        std::cout << "Enter a number 1: ";
        std::cin >> printNum1;

        while(!callCalc.set_num1(printNum1)){
            std::cout << "Введите num1 заново: ";
            std::cin >> printNum1;
        }

        std::cout << "Enter a number 2: ";
        std::cin >> printNum2;

        while(!callCalc.set_num2(printNum2)){
            std::cout << "Введите num2 заново: ";
            std::cin >> printNum2;
        }

        std::cout << "num1 + num2 = " << callCalc.add() << std::endl;
        std::cout << "num1 * num2 = " <<  callCalc.multiply() << std::endl;
        std::cout << "num1 - num2 = " <<  callCalc.subtract_1_2() << std::endl;
        std::cout << "num1 - num2 = " <<  callCalc.subtract_2_1() << std::endl;
        std::cout << "num1 / num2 = " <<  callCalc.divide_1_2() << std::endl;
        std::cout << "num1 / num2 = " <<  callCalc.divide_2_1() << std::endl;
    }
    return 0;
}
