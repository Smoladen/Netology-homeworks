#include <iostream>
#include <string>

struct adress1{
  std::string city;
  std::string street;
  int houseNum;
  int apartmentNum;
  int index;
};

void printstruct(adress1* p){
  std::cout << "Город: " << p->city << std::endl;
  std::cout << "Улица: " << p->street << std::endl;
  std::cout << "Номер дома: " << p->houseNum << std::endl;
  std::cout << "Номер квартиры: " << p->apartmentNum << std::endl;
  std::cout << "Индекс: " << p->index << std::endl;
}

int main() {
  adress1 Moskow = {"Moscow", "Lenina", 25, 10, 1917};
  printstruct(&Moskow);
  
  std::cout << std::endl;
  
  adress1 Berlin = {"Berlin", "Unter den Linden", 22, 21, 1231};
  printstruct(&Berlin);
}