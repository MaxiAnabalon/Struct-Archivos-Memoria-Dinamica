#ifndef MUSEO_H_INCLUDED
#define MUSEO_H_INCLUDED

#include "obras.h"

struct Director{
    char nombreDir[20];
    char apellidoDir[20];
    int dni;
};

typedef struct Director * DirectorPtr;

struct Museo{
    char nombreMuseo[20];
    char direccion[20];
    DirectorPtr dire;
    ObraPtr obras[10];
};

typedef struct Museo * MuseoPtr;


///Crear museo por parametro
MuseoPtr cargarMuseoParametro(char nom[20], char direc[20]);
void mostrarMuseo(MuseoPtr m);
DirectorPtr cargarDirectorParametro(char nom[20], char apell[20], int dni);
void mostrarDirector(DirectorPtr d);

#endif // MUSEO_H_INCLUDED
