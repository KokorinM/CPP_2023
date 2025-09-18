#include <iostream>

class CreditCard {
private:
    int Number;     // номер карты
    double Balance; // текущий баланс

public:
    // Конструктор: инициализирует номер карты и начальный баланс
    CreditCard(int num, double bal) : Number(num), Balance(bal) {}

    // Пополнение баланса
    void Put(double amount) {
        if (amount > 0) {
            Balance += amount;
        }
    }

    // Снятие средств с баланса
    void Take(double amount) {
        if (amount > 0 && amount <= Balance) {
            Balance -= amount;
        }
    }

    // Пример вспомогательного метода для вывода состояния карты
    void print() const {
        std::cout << "Card Number: " << Number << ", Balance: " << Balance << std::endl;
    }
};

int main() {
    // Создание объекта CreditCard с номером 1234 и балансом 50
    CreditCard firstCC(1234, 50);

    // Объявление указателя на CreditCard и привязка к объекту
    CreditCard* pCard = &firstCC;

    // Демонстрация обращения к методам через указатель с использованием ->
    // 1) вывод текущего состояния через метод print
    pCard->print();

    // 2) добавление средств через Put
    pCard->Put(25);       // баланс становится 75
    pCard->print();

    // 3) снятие средств через Take
    pCard->Take(10);       // баланс становится 65
    pCard->print();

    return 0;
}