#include <iostream>

// Programa de laboratorio de enteros
// Febrero 2025 Ferdynand 

int main() {
    int a, b, c;

    std::cout << "Ingrese tres enteros: ";
    std::cin >> a >> b >> c;

    int producto = a * b * c;

    std::cout << "El producto de los enteros es: " << producto << std::endl;

    return 0;
}