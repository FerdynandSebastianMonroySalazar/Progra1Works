//Ejercicio 5.21
//Ferdynand Monroy Febrero 2025
#include <iostream>
using namespace std;

int main() {
    int codigo;
    double salario;

    cout << "Ingrese el codigo de empleado (1-4): ";
    cin >> codigo;

    switch (codigo) {
        case 1:
            cout << "Ingrese el salario semanal fijo: ";
            cin >> salario;
            break;
        case 2:
            double horas, tarifa;
            cout << "Ingrese las horas trabajadas: ";
            cin >> horas;
            cout << "Ingrese la tarifa por hora: ";
            cin >> tarifa;
            salario = (horas <= 40) ? horas * tarifa : 40 * tarifa + (horas - 40) * tarifa * 1.5;
            break;
        case 3:
            double ventas;
            cout << "Ingrese las ventas totales: ";
            cin >> ventas;
            salario = 250 + 0.057 * ventas;
            break;
        case 4:
            int piezas, montoPorPieza;
            cout << "Ingrese el numero de piezas producidas: ";
            cin >> piezas;
            cout << "Ingrese el monto por pieza: ";
            cin >> montoPorPieza;
            salario = piezas * montoPorPieza;
            break;
        default:
            cout << "Codigo invalido." << endl;
            return 1;
    }

    cout << "El salario semanal es: " << salario << endl;
    return 0;
}
