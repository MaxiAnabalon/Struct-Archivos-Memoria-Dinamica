#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Vectores Dinamicos
int * crearVector(int  tam);
void cargarVectorAleatorio(int * v, int tam);
void cargarVectorTeclado(int * v, int tam);
void mostrarVector(int * v, int tam);
void liberarVector(int * v);
/* TAREA
- CARGAR POR TECLADO
- CARGAR POR ARCHIVO.TXT
- HACER LAS 2 BUSQUEDAS
- HACER LOS 3 ORDENAMIENTOS
*/

int main()
{
    srand(time(0));
    int t=6;
    int * vector;
    vector = crearVector(t);
    cargarVectorTeclado(vector, t);
    mostrarVector(vector, t);
    liberarVector(vector);
    printf("\n-------- Vector Dinamico reutilizada ------\n");
    vector = crearVector(3);
    cargarVectorAleatorio(vector, 3);
    mostrarVector(vector, 3);

    return 0;
}

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
    printf("\n---------- Mostrar vector dinamico ----------\n", tam);
    for(int i=0; i<tam; i++){
        printf("[%d] ",v[i]);
    }
    printf("\n");
}

void liberarVector(int * v){
    free(v);
}
