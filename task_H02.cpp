#include <iostream>
#include <stdexcept>

class Complex {
    double r_, i_;

public:
    Complex(double r = 0.0, double i = 0.0) : r_(r), i_(i) {}

    double real() const { return r_; }
    double imag() const { return i_; }

    Complex operator+(const Complex& other) const {
        return Complex(r_ + other.r_, i_ + other.i_);
    }

    Complex operator-(const Complex& other) const {
        return Complex(r_ - other.r_, i_ - other.i_);
    }

    Complex operator*(const Complex& other) const {
        // (a+bi)(c+di) = (ac - bd) + (ad + bc)i
        return Complex(r_ * other.r_ - i_ * other.i_,
                       r_ * other.i_ + i_ * other.r_);
    }

    Complex operator/(const Complex& other) const {
        // (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c^2 + d^2)
        double denom = other.r_ * other.r_ + other.i_ * other.i_;
        if (denom == 0.0) throw std::runtime_error("Division by zero complex number");

        return Complex((r_ * other.r_ + i_ * other.i_) / denom,
                       (i_ * other.r_ - r_ * other.i_) / denom);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        os << z.r_;
        if (z.i_ >= 0) os << " + " << z.i_ << "i";
        else          os << " - " << -z.i_ << "i";
        return os;
    }
};

int main() {
    Complex a(4, 5);
    Complex b(2, -3);

    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n\n";

    std::cout << "a + b = " << (a + b) << "\n";
    std::cout << "a - b = " << (a - b) << "\n";
    std::cout << "a * b = " << (a * b) << "\n";

    try {
        std::cout << "a / b = " << (a / b) << "\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
