#ifndef EQUIPOS_H
#define EQUIPOS_H
#include <string>

class Equipos
{
    public:
        Equipos(std::string nombre);

        void registrarPartido(int golesAnotados, int golesRecibidos);
        void calcularPorcentaje(int totalPuntos);
        void mostrarInfo() const;
        std::string getNombre() const;
        int getPuntos() const;
        virtual ~Equipos();

    protected:

    private:
        std::string nombre;
        int juegosJugados;
        int juegosGanados;
        int juegosEmpatados;
        int juegosPerdidos;
        int puntos;
        double porcentaje;
};

#endif // EQUIPOS_H
