#pragma once
#include<cmath>
#include <iostream>
enum class ShapeType{
    Line,
    Square,
    Cube,
    Circle,
    Cylinder
};


class Shape{
public:
    virtual ~Shape() = default;
    virtual void shift(int dx, int dy, int dz) = 0;
    virtual void scale(double factor) =0;
    virtual double  getArea() const =0;
    virtual double getVolume() const = 0;
    virtual ShapeType getType() const = 0;
};

class Line : public Shape{
public:
    Line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2){}

    void shift(int dx, int dy, int dz) override{
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }
    void scale(double factor) override{
        x1 *= factor; y1 *= factor;
        x2 *= factor; y2 *= factor;
    }
    double getArea() const override {return 0;}
    double getVolume() const override {return 0;}
    ShapeType getType() const override{return ShapeType::Line;}
private:
    int x1, y1, x2, y2;
};

class Square : public Shape{
public:
    Square(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2){
        a = std::abs(x1 - x2);
        b = std::abs(y1 - y2);
    }
    void shift(int dx, int dy, int dz) override{
        x1 += dx;
        y1 += dy;
        x2 += dx;
        y2 += dy;
    }
    void scale(double factor) override{
        x1 *= factor; y1 *= factor;
        x2 *= factor; y2 *= factor;
    }
    double getArea() const override {return a * b;}
    double getVolume() const override { return 0;}
    ShapeType getType() const override{return ShapeType::Square;}

private:
    int x1, y1, x2, y2;
    int a,b;
};

class Cube : public Shape{
public:
    Cube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2) : x1(_x1), y1(_y1), z1(_z1), x2(_x2), y2(_y2), z2(_z2){
        a = std::abs(x1 - x2);
        b = std::abs(y1 - y2);
        c = std::abs(z1 - z2);
    }
    void shift(int dx, int dy, int dz) override{
        x1 += dx; y1 += dy; z1 += dz;
        x2 += dx; y2 += dy; z2 += dz;
    }
    void scale(double factor) override{
        x1 *= factor; y1 *= factor; z1 *= factor;
        x2 *= factor; y2 *= factor; z2 *= factor;
    }
    double getArea() const override{ return 2 * (a*b + a*c + b*c);}
    double getVolume() const override{return a*b*c;}
    ShapeType getType() const override{return ShapeType::Cube;}
private:
    int x1, y1, z1, x2, y2 ,z2;
    int a,b,c;
};


class Circle : public Shape{
public:
    Circle(int _x1, int _y1, double R) : x1(_x1), y1(_y1), radius(R){}

    void shift(int dx, int dy, int dz) override{std::cout << "Not possible to shift Circle"; }
    void scale(double factor) override{std::cout << "Not possible to scale Circle";}
    double getArea() const override{return 3.14 * (radius * radius);}
    double getVolume() const override{return 0;}
    ShapeType getType() const override{return ShapeType::Circle;}
private:
    int x1,y1;
    double radius;
};

class Cylinder : public Shape{
public:
    Cylinder(int _x1, int _y1, double R, double H) : x1(_x1), y1(_y1), radius(R), height(H){}
    void shift(int dx, int dy, int dz) override{std::cout << "Not possible to shift Cylinder"; }
    void scale(double factor) override{std::cout << "Not possible to scale Cylinder";}
    double getArea() const override{return 2 * (3.14 * radius * (radius + height));}
    double getVolume() const override{return 3.14 * radius * radius * height;}
    ShapeType getType() const override{return ShapeType::Cylinder;}
private:
    int x1,y1;
    double radius,height;
};
