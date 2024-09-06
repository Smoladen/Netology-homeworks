#include <iostream>
#include <fstream>
#include <string>

class Address{

private:
    std::string city;
    std::string street;
    int house;
    int apartment;
public:
    Address() : city(""), street(""), house(0), apartment(0) {}
    Address(std::string city, std::string street, int house, int apartment) : city(city), street(street), house(house), apartment(apartment) {}

    std::string getAdress(){
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }
    std::string getCity() const{
        return city;
    }
};

void sort(Address* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i].getCity() < arr[j].getCity()) {
                Address temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main() {
    int numOfAdresses;
    std::string city;
    std::string street;
    int house;
    int apartment;

    std::ifstream read("in.txt");
    std::ofstream write("out.txt");
    read >> numOfAdresses;

    Address* adresses = new Address[numOfAdresses];

    write << numOfAdresses;

    for(int i = 0; i < numOfAdresses; i++){
        read >> city >> street >> house >> apartment;
        adresses[i] = Address(city,street,house,apartment);
    }

    sort(adresses, numOfAdresses);

    for(int i = numOfAdresses - 1; i >= 0; i--){
        write << std::endl << adresses[i].getAdress();
    }

    delete[] adresses;
    return 0;
}
