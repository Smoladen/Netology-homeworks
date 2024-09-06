#include <iostream>

class Fraction {
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}

    Fraction operator+(const Fraction& right) const {
        return Fraction((numerator_ * right.denominator_ + right.numerator_ * denominator_), right.denominator_ * denominator_);
    }

    Fraction operator-(const Fraction& right) const {
        return Fraction((numerator_ * right.denominator_ - right.numerator_ * denominator_), right.denominator_ * denominator_);
    }

    Fraction operator*(const Fraction& right) const {
        return Fraction((numerator_ * right.numerator_), right.denominator_ * denominator_);
    }

    Fraction operator/(const Fraction& right) const {
        return Fraction((numerator_ * right.denominator_), right.numerator_ * denominator_);
    }

    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    Fraction& operator++() {//before
        numerator_ += denominator_;
        return *this;
    }

    Fraction operator++(int) {//after
        Fraction temp(numerator_, denominator_);
        numerator_ += denominator_;
        return temp;
    }

    Fraction& operator--() {//before
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator--(int) {//after
        Fraction temp(numerator_, denominator_);
        numerator_ -= denominator_;
        return temp;
    }

    void print() const {
        std::cout << numerator_ << "/" << denominator_;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    int num1, den1, num2, den2;
    std::cout << "Введите числитель дроби 1: ";
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> den1;
    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    f1.print(); std::cout << " + "; f2.print(); std::cout << " = "; (f1 + f2).print(); std::cout << std::endl;
    f1.print(); std::cout << " - "; f2.print(); std::cout << " = "; (f1 - f2).print(); std::cout << std::endl;
    f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; (f1 * f2).print(); std::cout << std::endl;
    f1.print(); std::cout << " / "; f2.print(); std::cout << " = "; (f1 / f2).print(); std::cout << std::endl;
    std::cout << "++"; f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; (++f1 * f2).print(); std::cout << std::endl;
    std::cout << "--"; f1.print(); std::cout << " = "; (--f1).print(); std::cout << std::endl;
    f1.print(); std::cout << "++ "; std::cout << " * "; f2.print(); std::cout << " = "; (f1++ * f2).print(); std::cout << std::endl;
    f1.print(); std::cout << "-- "; std::cout << " = "; (f1--).print(); std::cout << std::endl;
    std::cout << "-"; f1.print(); std::cout << " = "; (-f1).print(); std::cout << std::endl;

    return 0;
}
