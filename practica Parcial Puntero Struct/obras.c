#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "obras.h"
#include "museo.h"



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
