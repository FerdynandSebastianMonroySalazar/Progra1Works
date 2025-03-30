#include <iostream>
#include "Torneo.h"

using namespace std;

int main()
{
    Torneo torneo;
    int numEquipos;

    std::cout <<"Ingrese el numero de equipos: ";
    std::cin >> numEquipos;
    for (int i=0; i<numEquipos; i++){
        std::string nombre;
        std::cout <<"Ingrese el nombre del equipo" << i+1 << ":";
        std::cin >> nombre;
        torneo.agregarEquipos(nombre);
    }
    torneo.simularPartidos();
    torneo.calcularEstadisticas();
    torneo.mostrarResultados();

    return 0;
}
