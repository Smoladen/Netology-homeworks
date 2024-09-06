#include <iostream>
#include <string>

struct BankAccount{
  int accountNumber = 123456;
  double balance = 10.50;
  std::string customerName = "Alex";
};

void changeBal(BankAccount& account, double newBalance){
  account.balance = newBalance;
}

int main() {
  BankAccount acc1;
  
  int printAccNum;
  std::string printCustName;
  double printBalOld;
  double printBalNew;

  std::cout << "Введите номер счёта: ";
  std::cin >> printAccNum;
  if(printAccNum == acc1.accountNumber){
    std::cout << "Введите имя владельца: ";
    std::cin >> printCustName;
    if(printCustName == acc1.customerName){
      std::cout << "Введите баланс: ";
      std::cin >> printBalOld;
      if(printBalOld == acc1.balance){
        std::cout << "Введите новый баланс: ";
        std::cin >> printBalNew;
        changeBal(acc1,printBalNew);
        std::cout << "Ваш Счёт: " << acc1.customerName<< ", " <<acc1.accountNumber<< ", " <<acc1.balance<< ", " << "\n";
      }else{
        std::cout << "Неверный баланс. Обновите страницу и попробуйте еще раз.\n";
      }
    }else{
      std::cout << "Неверное имя владельца. Обновите страницу и попробуйте еще раз.\n";
    }
  }else{
    std::cout << "Неверный номер счёта. Обновите страницу и попробуйте еще раз.\n";
  }
  return 0;
}