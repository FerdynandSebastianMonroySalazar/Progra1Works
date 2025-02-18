//Laboratorio módulo 1 control sobre partidos politicos
//Ferdynand Monroy Febrero 2025

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_CANDIDATOS = 2; //número de candidatos
const int NUM_AFILIADOS = 50; //número de afiliados
const int NUM_RONDAS = 5;     //número de rondas de votación

//Generador de votos aleatorios
int generarVotoAleatorio() {
    return rand() % NUM_CANDIDATOS;
}

//Función que muestra la tabla
void mostrarResultados(string candidatos[], int votos[][NUM_RONDAS]) {
    cout << "\nResultados de las votaciones:\n";
    cout << "Candidato\t";
    for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
        cout << "Ronda " << ronda + 1 << "\t";
    }
    cout << endl;

    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << candidatos[i] << "\t\t";
        for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
            cout << votos[i][ronda] << "\t\t";
        }
        cout << endl;
    }
}

//Cálculo del ganador y perdedor
void calcularGanadorPerdedor(string candidatos[], int votos[][NUM_RONDAS]) {
    int totalVotos[NUM_CANDIDATOS] = {0};

    //Suma de todos los votos
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
            totalVotos[i] += votos[i][ronda];
        }
    }

    //Encontrar al candidato con más votos y el que tiene menos votos
    int ganador = 0, perdedor = 0;
    for (int i = 1; i < NUM_CANDIDATOS; i++) {
        if (totalVotos[i] > totalVotos[ganador]) {
            ganador = i;
        }
        if (totalVotos[i] < totalVotos[perdedor]) {
            perdedor = i;
        }
    }

    cout << "\nEl candidato a la presidencia ganador es: " << candidatos[ganador] << " con " << totalVotos[ganador] << " votos." << endl;
    cout << "El candidato con menos votos es: " << candidatos[perdedor] << " con " << totalVotos[perdedor] << " votos." << endl;
}

//Inicializar números aleatorios
int main() {
    srand(time(0));
    string candidatos[NUM_CANDIDATOS];
    int votos[NUM_CANDIDATOS][NUM_RONDAS] = {0};

    //Ingresar los nombres de los candidatos
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
        cin >> candidatos[i];
    }

    char opcion;
    do {
        //Reiniciar votos para una nueva elección
        for (int i = 0; i < NUM_CANDIDATOS; i++) {
            for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
                votos[i][ronda] = 0;
            }
        }

        //Rondas de votación
        for (int ronda = 0; ronda < NUM_RONDAS; ronda++) {
            for (int afiliado = 0; afiliado < NUM_AFILIADOS; afiliado++) {
                int voto = generarVotoAleatorio();
                votos[voto][ronda]++;
            }
        }

        //Resultados
        mostrarResultados(candidatos, votos);

        //Mostrar ganador y perdedor
        calcularGanadorPerdedor(candidatos, votos);

        //Repetición de elección
        cout << "¿Desea realizar otra eleccion? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}
