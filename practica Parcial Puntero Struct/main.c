#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "obras.h"
#include "museo.h"

void guardarMuseoEnArchivo(MuseoPtr m);

int main()
{
    MuseoPtr m1;
    m1=cargarMuseoParametro("Bellas Artes",  "Riobanba 1678");
    mostrarMuseo(m1);
    guardarMuseoEnArchivo(m1);
    ordenarObrasPorNombre(m1->obras, 10);
    buscarObraPorNombre(m1->obras, 10, "Noche Estrellada");
    buscarObraPorPrecio(m1->obras, 10,230000);
    //system("cls");
    //system("pause");
    mostrarMuseo(m1);
    guardarMuseoEnArchivo(m1);

    return 0;
}


void guardarMuseoEnArchivo(MuseoPtr m){

    FILE * a = fopen("museo.txt", "w");

        fprintf(a,"%s;%s\n", m->nombreMuseo, m->direccion);


    fclose(a);
}

