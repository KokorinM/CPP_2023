#include <iostream>
#include <cmath>
#include <clocale>

double get_angle(double a, double b, double c) {
    // Проверка на корректность аргументов (>0)
    if (a <= 0.0 || b <= 0.0 || c <= 0.0) return 0.0;

    // Дополнительно (полезно): проверка существования треугольника
    if (a + b <= c || a + c <= b || b + c <= a) return 0.0;

    // Закон косинусов: cos(A) = (b^2 + c^2 - a^2) / (2bc)
    double cosA = (b*b + c*c - a*a) / (2.0 * b * c);

    // Защита от погрешностей (чтобы acos не получил число чуть вне [-1; 1])
    if (cosA > 1.0) cosA = 1.0;
    if (cosA < -1.0) cosA = -1.0;

    double angleRad = std::acos(cosA);
    double angleDeg = angleRad * 180.0 / std::acos(-1.0);
    return angleDeg;
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::cout << get_angle(5., 4., 3.) << "\n"; // 90 градусов
    return 0;
}
