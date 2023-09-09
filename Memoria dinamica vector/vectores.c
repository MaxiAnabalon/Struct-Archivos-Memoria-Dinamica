#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectores.h"
#include "archivos.h"


///Funciones de vector Dinamico
int * crearVector(int  tam){

    int * pVec = (int *) malloc(tam * sizeof(int));
    return pVec;
}

void cargarVectorAleatorio(int * v, int tam){

    for(int i=0; i<tam; i++){
        v[i]= rand() % 101;
    }
}

void cargarVectorTeclado(int * v, int tam){
    int num=0;
    printf("\nIngrese %d numeros dentro del vector:\n", tam);
    for(int i=0; i<tam; i++){
        scanf("%d", &num);
        v[i]=num;
    }
}
void mostrarVector(int * v, int tam){
    printf("\n---------- Mostrar vector dinamico ----------\n");
    for(int i=0; i<tam; i++){
        printf("[%d] ",v[i]);
    }
    printf("\n");
}

void liberarVector(int * v){
    free(v);
}
///Busquedas
int busquedaSecuencialNumeroVector (int * v, int tam){
    int buscando=0;
    printf("\nIngrese el numero que  desea buscar: ");
    scanf("%d", & buscando);

    int pos = -1;

    for (int i=0;i<tam;i++){
        if (v[i]==buscando){
            pos=i;
        }
    }
    if(pos==-1){
        printf("\nNO SE ENCONTRO...\n");
        return -1;
    }
    else{
        printf(" %d , esta en la posicion %d\n",buscando, pos);
        return pos;}
}

int busquedaBinariaNumeroVector(int * v, int tam){
    int buscando=0;
    printf("\nIngrese el numero que  desea buscar:\n");
    scanf("%d", & buscando);
    int sup=0;
    int inf=0;
    int centro=0;
    sup=tam-1;

    while(inf<=sup){
        centro=(sup+inf)/2;
        if (v[centro]==buscando){

            printf("El numero %d , esta en la posicion %d\n",buscando, centro);
            return centro;
        }
    else
        {if(buscando>v[centro]){
            inf=centro+1;
        }else{
            sup = centro-1;
        }}}
    printf("\nNO SE ENCONTRO...\n");
    return -1;

}

//Ordenamiento Burbuja con tipo de orden
void ordenBurbuja(int * v, int tam){
        float aux;
        int orden=0;
        do{
        printf("\nOrdenamiento Burbuja, 1 para mayor a menor o 2 menor a mayor:\n");
        scanf("%d", & orden);
            if (orden <0 && orden>2){
                printf("\nError  vuelva a ingresar un valor correcto!!!...\n");};
        }while(orden <0 && orden>2);
        if (orden ==1){
            for(int i = 0; i<tam; i++){
                for(int j = 0; j<tam-1; j++){
                    if (v[j]<v[j+1]){
                        aux=v[j];
                        v[j]=v[j+1];
                        v[j+1]=aux;
                    }
                }
            }printf("\n***Ordenamiento Burbuja de Mayor a menor***\n");
            //mostrarVector(v, tam);
        }
        else{
            for(int i = 0; i<tam; i++){
                for(int j = 0; j<tam-1; j++){
                    if (v[j]>v[j+1]){
                        aux=v[j];
                        v[j]=v[j+1];
                        v[j+1]=aux;
                    }
                }
            }printf("\n***Ordenamiento Burbuja de Menor a mayor***\n");
            //mostrarVector(v, tam);
        }
}
//Ordenamiento Seleccion con tipo de orden
void ordenSeleccion(int * v, int tam){
    int orden=0;
        do{
        printf("\nOrdenamiento Seleccion, 1 para mayor a menor o 2 menor a mayor:\n");
        scanf("%d", & orden);
            if (orden <1 || orden>2){
                printf("\nError  vuelva a ingresar un valor correcto!!!...\n");};
        }while(orden <1 || orden>2);
    int x, y, min, max;
    float temp;
    if (orden==1){
        for (x=0; x < tam; x++){
            max=x;
            for(y=x+1; y < tam; y++){
                if (v[max]<v[y]){
                        max=y;
                    }
            temp=v[max];
            v[max]=v[x];
            v[x]=temp;
            }}printf("\n***Ordenamiento Seleccion de Mayor a menor***\n");
            //mostrarVector(v, tam);
            }
    else{for (x=0; x < tam; x++){
            min=x;
            for(y=x+1; y < tam; y++){
                if (v[min]>v[y]){
                        min=y;
                    }
            temp=v[min];
            v[min]=v[x];
            v[x]=temp;
            }}printf("\n***Ordenamiento Seleccion de Menor a mayor***\n");
            ///mostrarVector(v, tam);
            }
    }

//Ordenamiento Insercion con tipo de orden
void ordenInsercion(int * v, int tam){
    int orden=0;
        do{
        printf("\nOrdenamiento Insercion, 1 para mayor a menor o 2 menor a mayor:\n");
        scanf("%d", & orden);
            if (orden <1 || orden>2){
                printf("\nError  vuelva a ingresar un valor correcto!!!...\n");};
        }while(orden <1 || orden>2);
    int x,y,m,izq,der;
    float temp;
    if(orden==1){
        for(x=1;x<tam;x++){{
            temp = v[x];
            izq = 0;der = x-1;
            while(izq <= der){
                    m=(izq+der)/2;
            if (temp>v[m]){
                    der=m-1;}
            else{izq=m+1;}}
            y = x-1;
                while(y>=izq){
                 v[y+1]=v[y];
                 y=y-1;}v[izq]=temp;
            }}printf("\n***Ordenamiento Insercion de Mayor a menor***\n");
            //mostrarVector(v, tam);
            }
        else { for(x=1;x<tam;x++){
            temp = v[x];
            izq = 0;der = x-1;
            while(izq <= der){
                    m=(izq+der)/2;
            if (temp<v[m]){
                    der=m-1;}
            else{izq=m+1;}}
            y = x-1;
                while(y>=izq){
                 v[y+1]=v[y];
                 y=y-1;}v[izq]=temp;
            }printf("\n***Ordenamiento Insercion de Menor a mayor***\n");
            //mostrarVector(v, tam);
        }}
