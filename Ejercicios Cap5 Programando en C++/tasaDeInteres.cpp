//Ejercicio 5.11
//Ferdynand Monroy Febrero 2025
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double principal = 1000.0; //Monto inicial

    cout << "Tasa de interes" << setw(20) << "Monto en deposito" << endl;
    cout << fixed << setprecision(2);

    for (double tasa = 0.05; tasa <= 0.10; tasa += 0.01) {
        double monto = principal * pow(1.0 + tasa, 10);
        cout << setw(15) << tasa * 100 << "%" << setw(20) << monto << endl;
    }

    return 0;
}
