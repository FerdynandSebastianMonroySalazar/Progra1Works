//Ejercicio 5.13
//Ferdynand Monroy Febrero 2025
#include <iostream>
using namespace std;

int main() {
    int valores[5];

    cout << "Ingrese cinco numeros entre 1 y 30: ";
    for (int i = 0; i < 5; ++i) {
        cin >> valores[i];
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < valores[i]; ++j) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}
