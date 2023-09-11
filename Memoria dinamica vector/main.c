#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectores.h"
#include "archivos.h"


/* TAREA
- CARGAR POR TECLADO
- CARGAR POR ARCHIVO.TXT
- HACER LAS 2 BUSQUEDAS
- HACER LOS 3 ORDENAMIENTOS
*/

int main()
{
    srand(time(0));
    char nombreArchivo[20]="archivoVector.txt";
    //crearoBorrarArchivo(nombreArchivo);
    int t=contarReglonesArchivo(nombreArchivo);

    int * vector;

    vector = crearVector(t);

    //cargarVectorTeclado(vector, t);

    //guardarVectorenArchivo(vector, t, nombreArchivo);
    leerVectordeArchivo(vector, nombreArchivo);

    mostrarVector(vector, t);
    //ordenBurbuja(vector, t);
    //busquedaSecuencialNumeroVector(vector, t);
    //ordenBurbuja(vector,t);
    //ordenSeleccion(vector,t);
    ordenInsercion(vector,t);
    mostrarVector(vector, t);
    busquedaBinariaNumeroVector(vector, t);

    guardarVectorenArchivo(vector, t, nombreArchivo);
    liberarVector(vector);

    printf("\n-------- Vector Dinamico reutilizada ------\n");

    vector = crearVector(3);
    cargarVectorAleatorio(vector, 3);
    mostrarVector(vector, 3);

    return 0;
}

