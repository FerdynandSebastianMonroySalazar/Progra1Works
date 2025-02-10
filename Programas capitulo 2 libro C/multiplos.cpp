#include <iostream>

// Programa de laboratorio multiplos
// Febrero 2025 Ferdynand 

int main() {
    int a, b;

    std::cout << "Ingrese dos enteros: ";
    std::cin >> a >> b;

    if (a % b == 0) {
        std::cout << a << " es múltiplo de " << b << std::endl;
    } else {
        std::cout << a << " no es múltiplo de " << b << std::endl;
    }

    return 0;
}