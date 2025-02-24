//Ejercicio 5.19
//Ferdynand Monroy Febrero 2025
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 0.0;
    int signo = 1;

    cout << "Termino" << setw(20) << "Aproximacion de pi" << endl;
    cout << fixed << setprecision(15);

    for (int i = 1; i <= 1000; ++i) {
        pi += signo * 4.0 / (2 * i - 1);
        signo *= -1;
        cout << setw(4) << i << setw(20) << pi << endl;
    }

    return 0;
}
