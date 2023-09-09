#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.h"
#include "estudiante.h"


int main()
{
    printf("--------------------\n");

    MateriaPtr m[2];


    cargarMateriasDesdeArchivo(m);

    mostrarMaterias(m,2);


    return 0;
}


