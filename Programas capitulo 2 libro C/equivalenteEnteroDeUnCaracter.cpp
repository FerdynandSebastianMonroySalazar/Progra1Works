#include <iostream>

// Programa de laboratorio para equivalente de enteros de un caracter
// Febrero 2025 Ferdynand 

int main() {
    char caracter;

    std::cout << "Ingrese un carácter: ";
    std::cin >> caracter;

    std::cout << "El equivalente entero de '" << caracter << "' es " << static_cast<int>(caracter) << std::endl;

    return 0;
}