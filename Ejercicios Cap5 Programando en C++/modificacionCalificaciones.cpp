//Ejercicio 5.15
//Ferdynand Monroy Febrero 2025
#include <iostream>
using namespace std;

int main() {
    int calificacion;
    double suma = 0.0;
    int contador = 0;

    cout << "Ingrese las calificaciones (A=4, B=3, C=2, D=1, F=0): ";
    while (cin >> calificacion) {
        suma += calificacion;
        contador++;
    }

    if (contador > 0) {
        double promedio = suma / contador;
        cout << "El promedio de puntos de calificaciones es: " << promedio << endl;
    } else {
        cout << "No se ingresaron calificaciones." << endl;
    }

    return 0;
}
