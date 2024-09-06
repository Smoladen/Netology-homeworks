#include "math_functions.h"

double addition(double a, double b){
    return a + b;
}

double subtraction(double a, double b){
    return a - b;
}

double multiplication(double a, double b){
    return a * b;
}

double division(double a, double b){
    return a / b;
}

double power(double base, double exp){
    int result = 1;
    for(int i = 0; i < exp; i++){
        result *= base;
    }
    return result;
}
