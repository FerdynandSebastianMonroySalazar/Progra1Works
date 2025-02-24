//Ejercicio 5.23
//Ferdynand Monroy Febrero 2025
#include <iostream>
using namespace std;

int main() {
    int n = 5; //Número de filas en la mitad superior del rombo

    //Parte superior del rombo
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    //Parte inferior del rombo
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
