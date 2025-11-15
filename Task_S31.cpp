#include <iostream>

int main() {
    // Массив с названиями цифр
    const char* digits[] = {
        "ноль", "один", "два", "три", "четыре",
        "пять", "шесть", "семь", "восемь", "девять"
    };

    int num;
    std::cout << "Введите число от 0 до 9: ";
    std::cin >> num;

    if (num >= 0 && num <= 9) {
        std::cout << "Это число: " << digits[num] << std::endl;
    } else {
        std::cout << "Некорректный ввод. Пожалуйста, введите число от 0 до 9." << std::endl;
    }

    return 0;
}