// Ejemplo de utilización de matrices codigo heredado de C
//Declaraciòn de Bibliotecas y librerias estandar de C++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
//Declaraciòn de Constantes
#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100
//Declaraciòn de Prototipos de Funciòn
void llamaCiclo();   //Funciòn que controla el Ciclo comparativo de datos por todas las facultades
int busquedaAleatorios(int minimo, int maximo); //Funciòn que permite obtener valores aleatorios en las notas de cada alumno
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]); //Funciòn que permite asignar a cada alumno las notas aleatorios
void imprimirMatrizLinea(); //Funciòn que apoya el despliegue de titulos en el comparativo de facultades
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);
//Funciòn que permite el despliegue de cada facultad con sus alumnos y el calculo de promedios (menor y mayor)

//Función agregada para proemdio de alumnos
void calcularMejorAlumnoDeCadaFacultad(float promedio_facultad_1, float promedio_facultad_2, float promedio_facultad_3, 
                                       char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], 
                                       float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], 
                                       float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], 
                                       float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) 
{
    //Variables para almacenar los nombres y promedios de los mejores alumnos de cada facultad
    char mejorAlumnoFacultad1[MAXIMA_LONGITUD_CADENA];
    char mejorAlumnoFacultad2[MAXIMA_LONGITUD_CADENA];
    char mejorAlumnoFacultad3[MAXIMA_LONGITUD_CADENA];
    float mejorPromedioFacultad1 = 0;
    float mejorPromedioFacultad2 = 0;
    float mejorPromedioFacultad3 = 0;

    //Mostrar si el mejor alumno es de la facultad de ingenieria
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        if (matriz_facultad_1[y][NUMERO_NOTAS] > mejorPromedioFacultad1) {
            mejorPromedioFacultad1 = matriz_facultad_1[y][NUMERO_NOTAS];
            memcpy(mejorAlumnoFacultad1, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
    }

    //Mostrar si el mejor alumno es de la facultad de arquitectura
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        if (matriz_facultad_2[y][NUMERO_NOTAS] > mejorPromedioFacultad2) {
            mejorPromedioFacultad2 = matriz_facultad_2[y][NUMERO_NOTAS];
            memcpy(mejorAlumnoFacultad2, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
    }

    //Mostrar si el mejor alumno es de la facultad de administración
    for (int y = 0; y < NUMERO_ALUMNOS; y++) {
        if (matriz_facultad_3[y][NUMERO_NOTAS] > mejorPromedioFacultad3) {
            mejorPromedioFacultad3 = matriz_facultad_3[y][NUMERO_NOTAS];
            memcpy(mejorAlumnoFacultad3, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
    }

    //Mostrar cual de los tres alumnos tiene el mejor promedio
    float mejorPromedioGlobal = mejorPromedioFacultad1;
    char mejorAlumnoGlobal[MAXIMA_LONGITUD_CADENA];
    memcpy(mejorAlumnoGlobal, mejorAlumnoFacultad1, MAXIMA_LONGITUD_CADENA);

    if (mejorPromedioFacultad2 > mejorPromedioGlobal) {
        mejorPromedioGlobal = mejorPromedioFacultad2;
        memcpy(mejorAlumnoGlobal, mejorAlumnoFacultad2, MAXIMA_LONGITUD_CADENA);
    }

    if (mejorPromedioFacultad3 > mejorPromedioGlobal) {
        mejorPromedioGlobal = mejorPromedioFacultad3;
        memcpy(mejorAlumnoGlobal, mejorAlumnoFacultad3, MAXIMA_LONGITUD_CADENA);
    }

    //Resultados
    cout << " Mejores Alumnos de Cada Facultad " << endl;
    cout << "Facultad de Ingenieria: " << mejorAlumnoFacultad1 << " con promedio: " << mejorPromedioFacultad1 << endl;
    cout << "Facultad de Arquitectura: " << mejorAlumnoFacultad2 << " con promedio: " << mejorPromedioFacultad2 << endl;
    cout << "Facultad de Administracion: " << mejorAlumnoFacultad3 << " con promedio: " << mejorPromedioFacultad3 << endl;
    cout << " El mejor alumno de todos es: " << mejorAlumnoGlobal << " con promedio: " << mejorPromedioGlobal << endl << endl;
}

int main()
{
    srand(getpid()); //Proceso preparativo para generaciòn de valores aleatorios
    llamaCiclo();
    return 0;
}

void llamaCiclo()
{
    //Declaraciòn de matrices por cada facultad
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;  //Variable que controla el ciclo de repeticiòn
    bool repetir = true;  //Variable booleana del ciclo de repeticiòn
    //Declaraciòn de variables flotantes para el calculo de promedios
    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;
    //Declaraciòn de matriz que almacenarà los nombres de los alumnos
    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};
    //Ciclo repetitivo del comparativo de facultades
    do
    {
        system("cls");
        //Inicializar los promedios por facultad
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        cout << "*** Comparativo de Facultades ***" << endl << endl;
        llenarMatriz(matriz_facultad_1); //Calculo de las notas por facultad
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria"); //Despliegue de valores por facultad
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");
        //Calculo del mejor promedio de las facultades
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            //Facultad 1 es mayor
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            //Facultad 2 es mayor
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
        } else
        if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            //Facultad 3 es mayor
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
        } else
        {
            //Varias facultades son iguales en promedio
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }

        //Calcular el mejor promedio de alumnos de cada facultad
        calcularMejorAlumnoDeCadaFacultad(promedio_facultad_1, promedio_facultad_2, promedio_facultad_3, alumnos, matriz_facultad_1, matriz_facultad_2, matriz_facultad_3);

        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}

int busquedaAleatorios(int minimo, int maximo)
{
    //Calculo de valores aleatorios tomando como base la nota minima y màxima del parcial
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1])
{
    //Funciòn que permite llenar cada matriz con valores aleatorios
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            if (x == 0 || x == 3)  //Calculo del primer parcial o actividades
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            } else if (x == 1)  //Calculo del segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            } else if (x == 2)  //Calculo del examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio al final de la matriz
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea()
{
    //Funciòn que despliega titulo de cada nota calculada
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}

float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++)
    {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor) //Se va guardando la nota mayor y el nombre del alumno
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) //Se va guardando la nota menor y el nombre del alumno
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    //Calculo del promedio general de cada facultad
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral; //Retorno del promedio general por facultad
}