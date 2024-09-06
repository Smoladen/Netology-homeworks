#include <iostream>
#include <fstream>
#include <string>

class Address {

private:
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address() : city(""), street(""), house(0), apartment(0) {}
    Address(std::string city, std::string street, int house, int apartment) :
        city(city), street(street), house(house), apartment(apartment) {}

    std::string getAddress() {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
};

int main() {
    int numOfAddresses;
    std::string city;
    std::string street;
    int house;
    int apartment;

    std::ifstream read("in.txt");
    std::ofstream write("out.txt");
    read >> numOfAddresses;

    write << numOfAddresses;

    Address* addresses = new Address[numOfAddresses];

    for(int i = 0; i < numOfAddresses; i++) {
        read >> city >> street >> house >> apartment;
        addresses[i] = Address(city, street, house, apartment);
    }

    for(int i = numOfAddresses - 1; i >= 0; i--) {
        write << std::endl << addresses[i].getAddress();
    }

    delete[] addresses;
    return 0;
}
