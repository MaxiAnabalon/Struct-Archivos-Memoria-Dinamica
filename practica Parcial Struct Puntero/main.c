#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Obra{
    char nombreObra[20];
    char autor[20];
    float precio;
};

typedef struct Obra * ObraPtr;

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
ObraPtr cargarObraParametro(char nom[20], char autor[20], float p);
void cargarArraysObras(ObraPtr o[], int t);
void mostrarObra(ObraPtr o);
void mostrarArraysObras(ObraPtr o[], int t);
void ordenarObrasPorNombre(ObraPtr o[], int t);
void buscarObraPorNombre(ObraPtr o[], int t, char busq[20]);
void buscarObraPorPrecio(ObraPtr o[], int t, float p);

int main()
{
    MuseoPtr m1;
    m1=cargarMuseoParametro("Bellas Artes",  "Riobanba 1678");
    mostrarMuseo(m1);
    ordenarObrasPorNombre(m1->obras, 10);
    buscarObraPorNombre(m1->obras, 10, "Noche Estrellada");
    buscarObraPorPrecio(m1->obras, 10,230000);
    //system("cls");
    //system("pause");
    mostrarMuseo(m1);

    return 0;
}

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

ObraPtr cargarObraParametro(char nom[20], char autor[20], float p){

    ObraPtr o = (ObraPtr) malloc(sizeof(struct Obra));

    strcpy(o->nombreObra, nom);
    strcpy(o->autor, autor);
    o->precio=p;
    return o;
};

void cargarArraysObras(ObraPtr o[], int t){

    for(int i=3; i<t; i++){
        o[0]=cargarObraParametro("Noche Estrellada","Van Gogh",23000000);
        o[1]=cargarObraParametro("El Beso","Gustav Klimt",17000000);
        o[2]=cargarObraParametro("El Grito","Edvard Munch",11000000);
        o[i]=cargarObraParametro("vacio","vacio",-1);
    }
};

void mostrarObra(ObraPtr o){
    printf("\n---- Obra ----");
    printf("\nNombre: %s ", o->nombreObra);
    printf("\nAutor: %s " , o->autor);
    printf("\nCosto: %.2f \n", o->precio);
};

void mostrarArraysObras(ObraPtr o[], int t){
    for(int i=0; i<t; i++){
        mostrarObra(o[i]);
    }
}

void ordenarObrasPorNombre(ObraPtr o[], int t){

    ObraPtr aux ;

    for ( int i = 0; i < t; i++){
        for ( int j = 0; j< t-1; j++){
            //ObraPtr aux = (ObraPtr) malloc(sizeof(struct Obra));
            if ( strcmp(o[j]->nombreObra ,  o[j+1]->nombreObra) == 1){
                aux = o[j];
                o[j] = o[j+1];
                o[j+1] = aux;
            }
        }
    }
    //sleep(5);
    system("pause");
    system("cls");

}

void buscarObraPorNombre(ObraPtr o[], int t, char busq[20]){
    int e=0;
    for(int i=0; i<t; i++){
        if(strcmp(o[i]->nombreObra, busq) == 0){
            printf("\n---- Obra Encontrada ----");
            mostrarObra(o[i]);
            e=1;
            printf("\n--------------------------");
        }
    }
    if (e==0){printf("\nObra no encontrada...\n");}
}

void buscarObraPorPrecio(ObraPtr o[], int t, float p){
    int e=0;
    for(int i=0; i<t; i++){
        if(o[i]->precio == p){
            printf("\n---- Obra Encontrada por precio ----");
            mostrarObra(o[i]);
            e=1;
            printf("--------------------------\n");
        }
    }
    if (e==0){printf("\nObra no encontrada por precio...\n");}
}

