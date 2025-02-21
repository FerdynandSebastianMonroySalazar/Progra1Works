//Programa equipos de football con arreglos y funciones
//Ferdynand Monroy Febrero 2025

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int numEquipos = 6;
const int numPartidos = 2 * (numEquipos - 1); //calculo para asignar correctamente los partidos

//Estructura de los equipos
struct Equipo {
    string nombre;
    int juegosJugados;
    int juegosGanados;
    int juegosEmpatados;
    int juegosPerdidos;
    int puntos;
    double porcentaje;
};

//Funcion para generar goles aleatorios de 0 a maximo
int generarGolesAleatorios(int maxGoles) {
    return rand() % (maxGoles + 1);
}

//Ingreso de nombre de los equipos
void ingresarNombresEquipos(Equipo equipos[numEquipos]) {
    cout << "Ingrese el nombre de los equipos:" << endl;
    for (int i = 0; i < numEquipos; i++) {
        cout << "Equipo " << i + 1 << ": ";
        cin >> equipos[i].nombre;
    }
}

//Funcion que simula el resultados de los partidos
void simularResultados(Equipo equipos[numEquipos]) {
    srand(time(0));
    int maxGoles = 5;

    for (int i = 0; i < numEquipos; i++) {
        for (int j = 0; j < numEquipos; j++) {
            if (i != j) {
                // Partidos de ida
                int golesEquipoi = generarGolesAleatorios(maxGoles);
                int golesEquipoj = generarGolesAleatorios(maxGoles);
                equipos[i].juegosJugados++;
                equipos[j].juegosJugados++;
                if (golesEquipoi > golesEquipoj) {
                    equipos[i].juegosGanados++;
                    equipos[j].juegosPerdidos++;
                    equipos[i].puntos += 3;
                } else if (golesEquipoi < golesEquipoj) {
                    equipos[j].juegosGanados++;
                    equipos[i].juegosPerdidos++;
                    equipos[j].puntos += 3;
                } else {
                    equipos[i].juegosEmpatados++;
                    equipos[j].juegosEmpatados++;
                    equipos[i].puntos += 1;
                    equipos[j].puntos += 1;
                }

                // Partidos de vuelta
                int golesEquipoiVuelta = generarGolesAleatorios(maxGoles);
                int golesEquipojVuelta = generarGolesAleatorios(maxGoles);
                equipos[i].juegosJugados++;
                equipos[j].juegosJugados++;
                if (golesEquipoiVuelta > golesEquipojVuelta) {
                    equipos[i].juegosGanados++;
                    equipos[j].juegosPerdidos++;
                    equipos[i].puntos += 3;
                } else if (golesEquipoiVuelta < golesEquipojVuelta) {
                    equipos[j].juegosGanados++;
                    equipos[i].juegosPerdidos++;
                    equipos[j].puntos += 3;
                } else {
                    equipos[i].juegosEmpatados++;
                    equipos[j].juegosEmpatados++;
                    equipos[i].puntos += 1;
                    equipos[j].puntos += 1;
                }
            }
        }
    }
}

//Funcion para calcular el porcentaje
void calcularPorcentajes(Equipo equipos[numEquipos]) {
    for (int i = 0; i < numEquipos; i++) {
        equipos[i].porcentaje = (static_cast<double>(equipos[i].puntos) / (numPartidos * 3)) * 100;
    }
}

//Mostrar los resultados estilo tabulado
void mostrarResultados(Equipo equipos[numEquipos]) {
    cout << setw(15) << "Equipo" << setw(15) << "Jugados" << setw(15) << "Ganados" << setw(15) << "Empatados" << setw(15) << "Perdidos" << setw(15) << "Puntos" << setw(15) << "Porcentaje" << endl;
    for (int i = 0; i < numEquipos; i++) {
        cout << setw(15) << equipos[i].nombre << setw(15) << equipos[i].juegosJugados << setw(15) << equipos[i].juegosGanados << setw(15) << equipos[i].juegosEmpatados << setw(15) << equipos[i].juegosPerdidos << setw(15) << equipos[i].puntos << setw(15) << fixed << setprecision(2) << equipos[i].porcentaje << "%" << endl;
    }
}

int main() {
    Equipo equipos[numEquipos] = {
        {"", 0, 0, 0, 0, 0, 0.0},
        {"", 0, 0, 0, 0, 0, 0.0},
        {"", 0, 0, 0, 0, 0, 0.0},
        {"", 0, 0, 0, 0, 0, 0.0},
        {"", 0, 0, 0, 0, 0, 0.0},
        {"", 0, 0, 0, 0, 0, 0.0},
    };

    ingresarNombresEquipos(equipos);
    simularResultados(equipos);
    calcularPorcentajes(equipos);
    mostrarResultados(equipos);
    return 0;
}
