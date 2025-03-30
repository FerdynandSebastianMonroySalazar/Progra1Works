#include "equipos.h"
#include <iostream>
#include <iomanip>

Equipos::Equipos(std::string nombre)
: nombre(nombre), juegosJugados(0), juegosGanados(0), juegosEmpatados(0), juegosPerdidos(0), puntos(0), porcentaje(0.0)
{
    //ctor
}

Equipos::~Equipos()
{
    //dtor
}

void Equipos::registrarPartido(int golesAnotados, int golesRecibidos){
    juegosJugados++;
    if (golesAnotados>golesRecibidos) {
        juegosGanados++;
        puntos +=3;
    } else if (golesAnotados<golesRecibidos) {
        juegosPerdidos++;
    } else {
        juegosEmpatados++;
        puntos +=1;
    }
}

void Equipos::mostrarInfo() const {
    std::cout << std::setw(15) << nombre
              << std::setw(10) << juegosJugados
              << std::setw(10) << juegosGanados
              << std::setw(10) << juegosEmpatados
              << std::setw(10) << juegosPerdidos
              << std::setw(10) << puntos
              << std::setw(10) << porcentaje << "%"
              << std::endl;
}

std::string Equipos::getNombre() const { return nombre; }
int Equipos::getPuntos() const { return puntos; }
