#include <iostream>
using namespace std;

int main() {
    char operacion;
    double primerNumero, segundoNumero;

    cout << "Ingrese la operación (+, -, *, /): ";
    cin >> operacion;

    cout << "Ingrese el primer número: ";
    cin >> primerNumero;

    cout << "Ingrese el segundo número: ";
    cin >> segundoNumero;

    switch (operacion) {
        case '+':
            cout << "Resultado: " << primerNumero + segundoNumero << endl;
            break;
        case '-':
            cout << "Resultado: " << primerNumero - segundoNumero << endl;
            break;
        case '*':
            cout << "Resultado: " << primerNumero * segundoNumero << endl;
            break;
        case '/':
            if (segundoNumero != 0) {
                cout << "Resultado: " << primerNumero / segundoNumero << endl;
            } else {
                cout << "Error: División por cero no permitida." << endl;
            }
            break;
        default:
            cout << "Operación no válida." << endl;
            break;
    }

    return 0;
}