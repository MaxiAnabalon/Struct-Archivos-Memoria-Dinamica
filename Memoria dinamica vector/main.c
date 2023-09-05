#include <stdio.h>
#include <stdlib.h>

int * crearVector(int  tam);

int main()
{

    int * vector;
    crearVector(5);


    return 0;
}

int * crearVector(int  tam){

    int * vec = (int *) malloc(tam * sizeof(int));
    return vec;
}
