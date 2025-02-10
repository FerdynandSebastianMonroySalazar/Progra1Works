#include <iostream>

// Programa de laboratorio aritmetico
// Febrero 2025 Ferdynand 

int main() {
    int a, b, c;

    std::cout << "Ingrese tres enteros distintos: ";
    std::cin >> a >> b >> c;

    int suma = a + b + c;
    int promedio = suma / 3;
    int producto = a * b * c;
    int menor = a;
    int mayor = a;

    if (b < menor) menor = b;
    if (c < menor) menor = c;
    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;

    std::cout << "La suma es " << suma << std::endl;
    std::cout << "El promedio es " << promedio << std::endl;
    std::cout << "El producto es " << producto << std::endl;
    std::cout << "El menor es " << menor << std::endl;
    std::cout << "El mayor es " << mayor << std::endl;

    return 0;
}