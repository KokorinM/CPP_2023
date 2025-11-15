#include <iostream>

void sort(int arr[]) {
    // простой пузырьковый сортировщик по убыванию
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int a[10] = {
        1,
        8,
        3,
        6,
        5,
        4,
        9,
        2,
        8,
        12
    };
    sort(a);
    // вывод отсортированного массива
    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    return 0;
}