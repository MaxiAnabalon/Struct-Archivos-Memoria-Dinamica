#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "estudiante.h"
/* TAREA
- ELIMINAR ESTUDIANTE
- MODIFICAR ESTUDIANTE
- PERSISTENCIA DE MATERIA
- CREAR MAS MATERIAS Y LEVANTARLAS DEL TXT
*/


int main()
{
    printf("--------------------\n");
    int cantMate = 2;
    MateriaPtr m1[cantMate];
    cargarArrysMaterias(m1, cantMate);

    cargarEstudiantesDesdeArchivo(m1);

    mostrarArrysMaterias(m1, cantMate);
    //mostrarMateria(m1);

    //agregarEstudiante(m1->listaEstudiantes, TAM);

    //mostrarMateria(m1);

    //modificarEstudiante(m1->listaEstudiantes, TAM, 333);
    //eliminarEstudiante(m1->listaEstudiantes, TAM, 222);
    guardarDatosMateria(m1, cantMate);
    //guardarDatos(m1);



    return 0;
}


