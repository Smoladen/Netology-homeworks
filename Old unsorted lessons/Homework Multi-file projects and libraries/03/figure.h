#ifndef FUGIRE_CLASS_H
#define FUGIRE_CLASS_H
#include <string>

class Figure {
protected:
    int numOfSides;
    std::string status;
    int a, b, c, d;
    int A, B, C, D;
    std::string name;
public:
    Figure(){name = "Figure: "; numOfSides=0; status = "Правельный";}
    Figure(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D){}
    Figure(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C){}

    virtual void print_info();
    virtual bool chec_status();
};
#endif
