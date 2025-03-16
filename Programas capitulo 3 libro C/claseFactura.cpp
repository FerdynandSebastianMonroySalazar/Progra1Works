#include <iostream>
#include <string>

class Factura {
private:
    std::string numeroPieza;
    std::string descripcionPieza;
    int cantidad;
    int precioPorArticulo;

public:
    Factura(std::string pieza, std::string descripcion, int cant, int precio)
        : numeroPieza(pieza), descripcionPieza(descripcion), cantidad(cant), precioPorArticulo(precio) {}

    void establecerNumeroPieza(std::string pieza) {
        numeroPieza = pieza;
    }

    std::string obtenerNumeroPieza() const {
        return numeroPieza;
    }

    void establecerDescripcionPieza(std::string descripcion) {
        descripcionPieza = descripcion;
    }

    std::string obtenerDescripcionPieza() const {
        return descripcionPieza;
    }

    void establecerCantidad(int cant) {
        cantidad = (cant > 0) ? cant : 0;
    }

    int obtenerCantidad() const {
        return cantidad;
    }

    void establecerPrecioPorArticulo(int precio) {
        precioPorArticulo = (precio > 0) ? precio : 0;
    }

    int obtenerPrecioPorArticulo() const {
        return precioPorArticulo;
    }

    int obtenerMontoFactura() const {
        return cantidad * precioPorArticulo;
    }
};

int main() {
    Factura factura("12345", "Martillo", 2, 1500);
    std::cout << "Monto de la factura: $" << factura.obtenerMontoFactura() << std::endl;
    return 0;
}
