#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "museo.h"
#include "obras.h"

MuseoPtr cargarMuseoParametro(char nom[20], char direc[20]){

    MuseoPtr m = (MuseoPtr) malloc (sizeof(struct Museo));

    strcpy(m->nombreMuseo,  nom);
    strcpy(m->direccion,  direc);
    m->dire=cargarDirectorParametro("Maximiliano", "Anabalon", 33445667);
    cargarArraysObras(m->obras, 10);

    return m;
};

void mostrarMuseo(MuseoPtr m){

    printf("\n\n---- MUSEO ----");
    printf("\nNombre: %s ", m->nombreMuseo );
    printf("\nDireccion: %s \n" , m->direccion);
    mostrarDirector(m->dire);
    mostrarArraysObras(m->obras, 10);
};

DirectorPtr cargarDirectorParametro(char nom[20], char apell[20], int dni){

    DirectorPtr d = (DirectorPtr) malloc(sizeof(struct Director));

    strcpy(d->nombreDir,  nom);
    strcpy(d->apellidoDir,  apell);
    d->dni=dni;
    return d;
};

void mostrarDirector(DirectorPtr d){
    printf("\n---- Director ----");
    printf("\nNombre: %s ", d->nombreDir);
    printf("\nApellido: %s " , d->apellidoDir);
    printf("\nDni: %d \n", d->dni);
};



