#include <iostream>
#include <string>

class Figure{
protected:
    int sides_count;
    std::string name;
public:
    Figure(){
        sides_count = 0;
        name = "Figure: ";
    }
    int get_sides_count(){
        return sides_count;
    }
    std::string get_name(){
        return name;
    }
};

class Triange : public Figure{
public:
    Triange(){
        sides_count = 3;
        name = "Triangle: ";
    }
};

class Quadrangle : public Figure{
public:
    Quadrangle(){
        sides_count = 4;
        name = "Quandrangle: ";
    }
};

int main() {
    Figure figure;
    Triange triange;
    Quadrangle quadrangle;

    std::cout << "Amount of sides : "<< std::endl;
    std::cout << figure.get_name() << figure.get_sides_count() << std::endl;
    std::cout << triange.get_name() << triange.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name() << quadrangle.get_sides_count() << std::endl;

    return 0;
}
