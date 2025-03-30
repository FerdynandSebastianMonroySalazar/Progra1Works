#ifndef TORNEO_H
#define TORNEO_H
#include "Equipos.h"
#include <vector>

class Torneo
{
    public:
        Torneo();
        void agregarEquipos(const std::string & nombre);
        void simularPartidos();
        void calcularEstadisticas();
        void mostrarResultados() const;

        virtual ~Torneo();

    protected:

    private:
        std::vector<Equipos> equipos;
        int generarGolesAleatorios(int maxGoles);

};

#endif // TORNEO_H
