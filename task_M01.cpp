#include <iostream>

int main() {
    const int n = 10; // размер таблицы (1..10)

    // Верхняя строка-заголовок
    std::cout << "\t";
    for (int j = 1; j <= n; ++j) {
        std::cout << j << "\t";
    }
    std::cout << "\n";

    // Таблица умножения
    for (int i = 1; i <= n; ++i) {
        std::cout << i << "\t"; // левый столбец-заголовок
        for (int j = 1; j <= n; ++j) {
            std::cout << (i * j) << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}
