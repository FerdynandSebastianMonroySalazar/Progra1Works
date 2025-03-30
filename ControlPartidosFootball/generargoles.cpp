#include "generargoles.h"
#include <cstdlib>

GenerarGoles::GenerarGoles()
{
    //ctor
}

GenerarGoles::~GenerarGoles()
{
    //dtor
}

int GenerarGoles::generarGolesAleatorios(int maxGoles) {
    return rand() % (maxGoles+1);
}
