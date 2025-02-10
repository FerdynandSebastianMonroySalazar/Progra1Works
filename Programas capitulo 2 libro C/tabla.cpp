#include <iostream>

// Programa de laboratorio tabla
// Febrero 2025 Ferdynand 

int main() {
    std::cout << "entero\tcuadrado\tcubo\n";
    for (int i = 0; i <= 10; ++i) {
        std::cout << i << "\t" << i * i << "\t\t" << i * i * i << "\n";
    }

    return 0;
}