#include "torneo.h"
#include <iostream>
#include <algorithm>
#include "generargoles.h"
#include <iomanip>

Torneo::Torneo()
{
    //ctor
}

Torneo::~Torneo()
{
    //dtor
}

void Torneo::agregarEquipos(const std::string & nombre) {
    equipos.emplace_back(nombre);
    }

void Torneo::simularPartidos() {
    int maxGoles=5;
    for (size_t i=0; i<equipos.size(); i++) {
        for(size_t j=i + 1; j<equipos.size(); j++) {
            int golesA = generarGolesAleatorios(int maxGoles);
            int golesB = generarGolesAleatorios(int maxGoles);
            equipos[i].registrarPartido(golesA, golesB);
            equipos[j].registrarPartido(golesB, golesA);
        }
    }
}

void Torneo::calcularEstadisticas() {
    int totalPuntos=equipos.size()*3;
    for (auto & equipo:equipos) {
        equipo.calcularPorcentaje(totalPuntos);
    }
}

void Torneo::mostrarResultados() const {
    std::cout << std::setw(15) << "Equipo"
              << std::setw(10) << "Jugados"
              << std::setw(10) << "Ganados"
              << std::setw(10) << "Empatados"
              << std::setw(10) << "Perdidos"
              << std::setw(10) << "Puntos"
              << std::setw(10) << "Porcentaje"
              << std::endl;
    for (const auto& equipo : equipos) {
        equipo.mostrarInfo();
    }
}
