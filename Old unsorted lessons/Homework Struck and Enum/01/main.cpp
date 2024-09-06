#include <iostream>

enum months
{
  January = 1,
  February,
  march,
  april,
  may,
  june,
  july,
  august,
  September,
  october,
  november,
  december
};

int main() {
  int number;
  do{
    std::cout << "Введите номер месяца или 0 для выхода: ";
    std::cin >> number;
    if(number >=1 && number <= 12){
      switch (static_cast<months>(number)){
        case January: std::cout << "Январь\n";
          break;
        case February: std::cout << "Февраль\n";
          break;
        case march: std::cout << "Март\n";
          break;
        case april: std::cout << "Апрель\n";
          break;
        case may: std::cout << "Май\n";
          break;
        case june: std::cout << "Июнь\n";
          break;
        case july: std::cout << "Июль\n";
          break;
        case august: std::cout << "Август\n";
          break;
        case September: std::cout << "Сентябрь\n";
          break;
        case october: std::cout << "Октябрь\n";
          break;
        case november: std::cout << "Ноябрь\n";
          break;
        case december: std::cout << "Декабрь\n";
          break;
      }
    }else if(number !=0)
      std::cout << "Неверный номер месяца\n";
  }while(number != 0);
  std::cout << "До свидания!";
  return 0;
}