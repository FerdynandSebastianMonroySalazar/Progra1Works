#include <iostream>

// Programa de laboratorio para enteros de mayor a menor
// Febrero 2025 Ferdynand 

int main() {
    int a, b, c, d, e;

    std::cout << "Ingrese cinco enteros: ";
    std::cin >> a >> b >> c >> d >> e;

    int menor = a;
    int mayor = a;

    if (b < menor) menor = b;
    if (c < menor) menor = c;
    if (d < menor) menor = d;
    if (e < menor) menor = e;

    if (b > mayor) mayor = b;
    if (c > mayor) mayor = c;
    if (d > mayor) mayor = d;
    if (e > mayor) mayor = e;

    std::cout << "El entero menor es " << menor << std::endl;
    std::cout << "El entero mayor es " << mayor << std::endl;

    return 0;
}