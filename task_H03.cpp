#include <iostream>
#include <cstdlib>

bool has_same_digits(int x) {
    x = std::abs(x);
    int cnt[10] = {0};

    // считаем 0 как число с одной цифрой '0' (повторов нет)
    if (x == 0) {
        cnt[0] = 1;
        return false;
    }

    while (x > 0) {
        int d = x % 10;
        if (++cnt[d] >= 2) return true; // нашли повтор
        x /= 10;
    }
    return false;
}

int same_digits(int from, int to) {
    if (from > to) std::swap(from, to);

    int amount = 0;
    bool first = true;

    for (int n = from; n <= to; ++n) {
        if (has_same_digits(n)) {
            if (!first) std::cout << ' ';
            std::cout << n;
            first = false;
            ++amount;
        }
    }

    if (!first) std::cout << "\n";
    std::cout << "Amount: " << amount << "\n";
    return amount;
}

int same_digits(int to) {
    return same_digits(0, to);
}

int main() {
    same_digits(40);        // 11 22 33
    std::cout << "\n";
    same_digits(200, 250);  // 200 202 211 212 222 232 233 242 244
    return 0;
}
