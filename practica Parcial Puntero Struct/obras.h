#ifndef OBRAS_H_INCLUDED
#define OBRAS_H_INCLUDED

struct Obra{
    char nombreObra[20];
    char autor[20];
    float precio;
};


typedef struct Obra * ObraPtr;

ObraPtr cargarObraParametro(char nom[20], char autor[20], float p);
void cargarArraysObras(ObraPtr o[], int t);
void mostrarObra(ObraPtr o);
void mostrarArraysObras(ObraPtr o[], int t);
void ordenarObrasPorNombre(ObraPtr o[], int t);
void buscarObraPorNombre(ObraPtr o[], int t, char busq[20]);
void buscarObraPorPrecio(ObraPtr o[], int t, float p);



#endif // OBRAS_H_INCLUDED
