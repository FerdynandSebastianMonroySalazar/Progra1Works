#include <iostream>
#include <cstdlib>
using namespace std;

// Programa de laboratorio para el cálculo del IMC
// Febrero 2025 Ferdynand 

int main() {
    float pesoEnLibras = 0;
    float alturaEnPulgadas = 0;
    float pesoEnKilogramos = 0;
    float alturaEnMetros = 0;
    float resultadoDeImc = 0;
    int opcionSeleccionada = 0;
    char salida;

    do {
        system("cls");
        cout << "IMC" << endl;
        // Menú
        cout << "1. Peso en libras y altura en pulgadas" << endl;
        cout << "2. Peso en kilogramos y altura en metros" << endl;
        cout << "Opcion: ";
        cin >> opcionSeleccionada;

        if (opcionSeleccionada == 1) {
            cout << "Ingrese su peso en libras: ";
            cin >> pesoEnLibras;
            cout << "Ingrese su altura en pulgadas: ";
            cin >> alturaEnPulgadas;
        } else if (opcionSeleccionada == 2) {
            cout << "Ingrese su peso en kilogramos: ";
            cin >> pesoEnKilogramos;
            cout << "Ingrese su altura en metros: ";
            cin >> alturaEnMetros;
        } else {
            cout << "Opción no válida." << endl;
            continue;
        }

        switch (opcionSeleccionada) {
            case 1:
                resultadoDeImc = (pesoEnLibras * 703) / (alturaEnPulgadas * alturaEnPulgadas);
                break;
            case 2:
                resultadoDeImc = pesoEnKilogramos / (alturaEnMetros * alturaEnMetros);
                break;
            default:
                cout << "Error en operación seleccionada" << endl;
                break;
        }

        cout << "El resultado de su IMC es: " << resultadoDeImc << endl;

        //Rango del IMC
        if (resultadoDeImc < 18.5) {
            cout << "Rango: Bajo peso" << endl;
        } else if (resultadoDeImc >= 18.5 && resultadoDeImc <= 24.9) {
            cout << "Rango: Normal" << endl;
        } else if (resultadoDeImc >= 25 && resultadoDeImc <= 29.9) {
            cout << "Rango: Sobrepeso" << endl;
        } else {
            cout << "Rango: Obeso" << endl;
        }

        cout << "Desea realizar una operación nueva? (Si=s / No=n): ";
        cin >> salida;

    } while (salida == 's' || salida == 'S');

    return 0;
}