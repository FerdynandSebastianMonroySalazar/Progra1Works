#include <iostream>
using namespace std;

int mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    cout << "Ingrese dos numeros enteros: ";
    cin >> num1 >> num2;
    cout << "El MCD de " << num1 << " y " << num2 << " es: " << mcd(num1, num2) << endl;
    return 0;
}
