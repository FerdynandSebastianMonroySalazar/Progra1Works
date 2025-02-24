//Ejercicio 5.9
//Ferdynand Monroy Febrero 2025
#include <iostream>
using namespace std;

int main() {
    long producto = 1;

    for (int i = 1; i <= 15; i += 2) {
        producto *= i;
    }

    cout << "El producto de los enteros impares del 1 al 15 es: " << producto << endl;
    return 0;
}
