#include <iostream>
#include <iomanip>

class CreditCard {
private:
    int Number;      // номер из 4 цифр
    float Balance;   // баланс карты в рублях

public:
    // Конструктор
    CreditCard(int number, float balance)
        : Number(number), Balance(balance) {}

    // Поместить деньги на карту
    void Put(float amount) {
        if (amount <= 0.0f) {
            std::cout << "Сумма должна быть положительной.\n";
            return;
        }
        Balance += amount;
        std::cout << "Положено: " << std::fixed << std::setprecision(2) << amount
                  << " Р. Текущий баланс: " << Balance << " Р.\n";
    }

    // Снять деньги с карты
    void Take(float amount) {
        if (amount <= 0.0f) {
            std::cout << "Сумма должна быть положительной.\n";
            return;
        }
        if (amount > Balance) {
            std::cout << "Недостаточно средств. Текущий баланс: "
                      << std::fixed << std::setprecision(2) << Balance << " Р.\n";
            return;
        }
        Balance -= amount;
        std::cout << "Снято: " << std::fixed << std::setprecision(2) << amount
                  << " Р. Текущий баланс: " << Balance << " Р.\n";
    }

    // Метод для вывода информации о карте
    void PrintInfo() const {
        std::cout << "Карта #" << Number << ", баланс: "
                  << std::fixed << std::setprecision(2) << Balance << " Р.\n";
    }
};

int main() {
    // Создание объекта: номер 1234, баланс 50 Р.
    CreditCard firstCC(1234, 50.0f);

    // Вызов метода через объект
    firstCC.PrintInfo();

    // Создание указателя на объект
    CreditCard* pCard = &firstCC;

    // Демонстрация обращения к методам по указателю (->)
    pCard->Put(25.0f);    // положить 25 Р
    pCard->Take(10.5f);   // снять 10.5 Р

    // Попытка снять больше, чем есть
    pCard->Take(100.0f);

    // Финальное состояние
    pCard->PrintInfo();

    return 0;
}
