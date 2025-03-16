#include <iostream>

class Fecha {
private:
    int mes;
    int dia;
    int anio;

public:
    Fecha(int m, int d, int a) {
        establecerMes(m);
        dia = d;
        anio = a;
    }

    void establecerMes(int m) {
        mes = (m >= 1 && m <= 12) ? m : 1;
    }

    int obtenerMes() const {
        return mes;
    }

    void establecerDia(int d) {
        dia = d;
    }

    int obtenerDia() const {
        return dia;
    }

    void establecerAnio(int a) {
        anio = a;
    }

    int obtenerAnio() const {
        return anio;
    }

    void mostrarFecha() const {
        std::cout << obtenerMes() << "/" << obtenerDia() << "/" << obtenerAnio() << std::endl;
    }
};

int main() {
    Fecha fecha(13, 15, 2023);
    fecha.mostrarFecha();
    fecha.establecerMes(5);
    fecha.establecerDia(20);
    fecha.establecerAnio(2024);
    fecha.mostrarFecha();

    return 0;
}
