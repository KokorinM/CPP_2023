#include <iostream>
#include <cmath>
#include <clocale>   // setlocale

// Площадь правильного N-угольника со стороной A
double get_square(double A, int N) {
    if (A <= 0 || N < 3) return 0.0; // Простая проверка входных данных

    const double pi = std::acos(-1.0);
    // Формула: S = (N * A^2) / (4 * tan(pi / N))
    return (N * A * A) / (4.0 * std::tan(pi / N));
}

int main() {
    // Включаем русскую локаль, чтобы кириллица в консоли отображалась корректно
    std::setlocale(LC_ALL, "Russian");

    double A;
    int N;

    // Ввод: сторона A и число сторон N
    std::cin >> A >> N;

    // Вывод площади
    std::cout << get_square(A, N) << "\n";
    return 0;
}
