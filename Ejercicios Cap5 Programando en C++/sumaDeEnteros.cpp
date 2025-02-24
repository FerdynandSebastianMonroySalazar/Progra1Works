//Laboratorio 5.5
//Ferdynand Monroy Febrero 2025
#include <iostream>
using namespace std;

int main() {
    int cantidad, valor, suma = 0;
    cout << "Ingrese la cantidad de valores para sumar: ";
    cin >> cantidad;

    for (int i = 0; i < cantidad; ++i) {
        cout << "Ingrese un valor: ";
        cin >> valor;
        suma += valor;
    }

    cout << "La suma es: " << suma << endl;
    return 0;
}
