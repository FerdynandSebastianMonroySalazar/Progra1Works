#include <iostream>
#include <stdlib.h>
#include <iomanip> // Para usar setw
#include <ctime> // Para usar time()

//Solución de programa vectores/matrices por grupo 4

using namespace std;

// Declaración de Constantes
#define NUMEROALUMNOS 5
#define NUMEROMATERIAS 5
#define NUMERONOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAX_LONGITUD_CADENA 100

// Declaración de Prototipos de Función
void LlamarCiclo();
void InicializarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1]);
void LlenarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1]);
void imprimirMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1], char alumnosFacultad[NUMEROALUMNOS][MAX_LONGITUD_CADENA]);
int busquedaAleatoriaDeNotas(int minimo, int maximo);

int main()
{
    // Inicializamos el generador de números aleatorios con la hora del sistema
    srand(time(0));

    LlamarCiclo(); // Solo llamamos la función una vez
    return 0;
}

void LlamarCiclo()
{
    // Matrices para las facultades
    float matrizFacultad_1[NUMEROALUMNOS][NUMERONOTAS+1];
    float matrizFacultad_2[NUMEROALUMNOS][NUMERONOTAS+1];
    float matrizFacultad_3[NUMEROALUMNOS][NUMERONOTAS+1];

    // Variables para los promedios
    float promedioFacultad_1;
    float promedioFacultad_2;
    float promedioFacultad_3;

    // Arreglo con los nombres de los alumnos
    char alumnosFacultad[NUMEROALUMNOS][MAX_LONGITUD_CADENA] = {"Carlos", "Luis", "Maria", "Pedro", "Mario"};

    // Eliminar ciclo infinito
    promedioFacultad_1 = 0;
    promedioFacultad_2 = 0;
    promedioFacultad_3 = 0;
    cout << "*** Comparativo de Facultades ***" << endl << endl;

    // Inicializar las matrices
    InicializarMatriz(matrizFacultad_1);
    InicializarMatriz(matrizFacultad_2);
    InicializarMatriz(matrizFacultad_3);

    // Llenar las matrices con notas aleatorias
    LlenarMatriz(matrizFacultad_1);
    LlenarMatriz(matrizFacultad_2);
    LlenarMatriz(matrizFacultad_3);

    // Imprimir las matrices
    imprimirMatriz(matrizFacultad_1, alumnosFacultad);
}

void InicializarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1])
{
    // Inicializar las matrices con ceros
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        for (int j = 0; j < NUMERONOTAS; j++)
        {
            matriz[i][j] = 0.00; // Inicializamos las notas en cero
        }
    }
}

void LlenarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1])
{
    // Llenar las matrices con calificaciones aleatorias
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        float suma = 0;
        int calificacionAlumno = 0;

        for (int j = 0; j < NUMERONOTAS; j++)
        {
            if (j == 0 || j == 3) // Primer parcial o Actividades
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 20);
            }
            else if (j == 1) // Segundo parcial
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 25);
            }
            else if (j == 2) // Examen final
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 35);
            }

            suma += (float)calificacionAlumno;
            matriz[i][j] = (float)calificacionAlumno;
            calificacionAlumno = 0;
        }
        matriz[i][NUMERONOTAS] = suma; // Guardamos la suma de las notas en la última columna
    }
}

void imprimirMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS+1], char alumnosFacultad[NUMEROALUMNOS][MAX_LONGITUD_CADENA])
{
    // Imprimir cabecera
    cout << "(nota1)=>Primer Parcial (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    cout << " " << endl;
    cout << setw(15) << "Alumno" << setw(10) << "P1" << setw(10) << "P2" << setw(10) << "Final" << setw(15) << "Actividades" << setw(13) << "Promedio" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    // Imprimir las calificaciones de cada alumno
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        cout << setw(15) << alumnosFacultad[i]; // Nombre del alumno

        // Imprimir las calificaciones de cada materia
        for (int j = 0; j < NUMERONOTAS; j++)
        {
            cout << setw(10) << matriz[i][j]; // Calificación de cada materia
        }

        // Imprimir el promedio
        cout << setw(15) << matriz[i][NUMERONOTAS] / NUMERONOTAS << endl; // Promedio
    }
}

int busquedaAleatoriaDeNotas(int minimo, int maximo)
{
    // Generar un número aleatorio en el rango dado
    return minimo + rand() % (maximo - minimo + 1); // Usamos el operador % para generar el número aleatorio dentro del rango
}
