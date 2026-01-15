#include <iostream>

int main() {
    const int n = 10; 

    
    std::cout << "\t";
    for (int j = 1; j <= n; ++j) {
        std::cout << j << "\t";
    }
    std::cout << "\n";

   
    for (int i = 1; i <= n; ++i) {
        std::cout << i << "\t"; 
        for (int j = 1; j <= n; ++j) {
            std::cout << (i * j) << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}

