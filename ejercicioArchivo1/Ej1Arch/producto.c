#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

void mostrarProducto (ProductoPtr prod){

    printf("\n----- P R O D U C T O -----\n");
    printf("\n NOMBRE: %s | PRECIO: %.2f\n",prod->nombre,prod->precio);
};

void mostrarProductos(ProductoPtr prod[], int tam){

    for(int i = 0; i<tam; i++){

        if(prod[i]->precio != -1){
            mostrarProducto(prod[i]);
        }
    }
};

ProductoPtr crearProductoPorTeclado(){

    ProductoPtr prod = (ProductoPtr) malloc(sizeof(struct Producto));
    char aux[20] = " ";

    printf("\n\nCreando Producto nuevo\n");

    printf("\nIngrese el nombre:\n");
    fflush(stdin);
    gets(aux);
    strcpy(prod->nombre,aux);

    printf("Ingrese el precio:\n");
    scanf("%f",&prod->precio);

    return prod;
};

void iniciarProductos(ProductoPtr prod[], int tam){

    ProductoPtr a = (ProductoPtr) malloc(sizeof(struct Producto));

    char aux[20] = " ";

    strcpy(a->nombre,aux);

    a->precio = -1;

    for(int i = 0; i<tam; i++){

        prod[i]= a;
    }
};

int buscarPosDisponible(ProductoPtr prod[], int tam){

    int posicion = -2;
    int i = 0;

    while(posicion == -2 && i<tam){

        if(prod[i]->precio == -1){
            posicion = i;
        }
        i++;
    }
    return posicion;
};

void agregarProductos(ProductoPtr prod[],ProductoPtr p, int tam){

    int i = buscarPosDisponible(prod,tam);

    if(i!= -2){
        prod[i] = p;
    }else{
        printf("\nYa no hay mas espacio para agregar\n");
    }
};

ProductoPtr transformarTextoAProducto(char c[],int tam){

    int pos1 = -1;

    char auxNombre[40] = " ";
    char auxPrecio[40] = " ";

    ProductoPtr prod = (ProductoPtr) malloc(sizeof(struct Producto));

    for(int i = 0; i<tam; i++){
        if(c[i] == ';'){
            pos1 = i;
            i = tam;
        }
    }

    for(int i = 0; i<pos1; i++){
        auxNombre[i] = c[i];
    }

    for(int i = pos1+1; i<tam; i++){
        auxPrecio[i-pos1-1] = c[i];
    }

    strcpy(prod->nombre,auxNombre);
    prod->precio = atof(auxPrecio);

    return prod;
};

void cargarProductos(ProductoPtr prod[], int tam){

    iniciarProductos(prod,tam);

    FILE * archivo = fopen("productos.txt", "r");

    while(!feof(archivo)){

        char aux[40] = " ";
        fgets(aux,40,archivo);

        ProductoPtr p = transformarTextoAProducto(aux,40);

        agregarProductos(prod, p, tam);
    }
    fclose(archivo);
};

void guardarProductos(ProductoPtr prod[], int tam){

    ProductoPtr a = (ProductoPtr) malloc(sizeof(struct Producto));

    char aux[20] = " ";

    strcpy(a->nombre,aux);

    a->precio = -1;

    FILE * archivo = fopen("productos.txt", "w");

    for(int i = 0; i<tam; i++){
        if(prod[i]->precio != a->precio){
            if(i!=0){
                fprintf(archivo,"\n");
            }
            fprintf(archivo, "%s;%.2f", prod[i]->nombre, prod[i]->precio);
        }
    }
    fclose(archivo);
};

void ordenarProductos(ProductoPtr prod[], int t){

    ProductoPtr aux;

    for (int i=0; i<t-1; i++){
        for (int j=i+1;j<t;j++){
            if (prod[i]->precio < prod[j]->precio){
                aux = prod[i];
                prod[i]= prod[j];
                prod[j]= aux;
            }
        }
    }
};
