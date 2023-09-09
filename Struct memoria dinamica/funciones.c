#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


VentaPtr cargarVentasTeclado(){

    VentaPtr v = (VentaPtr) malloc(sizeof(struct Venta));

    printf("\nIngrese anio de  venta: ");
    scanf("%d", &v->anio);
    printf("\nIngrese cantidad ventas: ");
    scanf("%d", &v->ventas);

    return v;
}

VentaPtr crearArrayVentas(int t){

    VentaPtr v = (VentaPtr) malloc(t * (sizeof(struct Venta)));
    return v;
}

void cargarArraysVentas(VentaPtr v[], int t){

    for (int i=0;i<t;i++){
        v[i]=cargarVentasTeclado();
    }

}

void mostrarVenta(VentaPtr v){

    printf("\n---- Ventas ----");
    printf("\nAnio: %d", v->anio);
    printf("\nAnio: %d\n", v->ventas);

}

void mostrarArraysVenta(VentaPtr v[], int t){

    for (int i=0;i<t;i++){
        mostrarVenta(v[i]);
    }

}

void guardarVentasEnArchivo(VentaPtr v[], int t){

    FILE * a = fopen("ventas.txt", "w");

    for(int i=0; i<t; i++){
        fprintf(a,"%d;%d\n", v[i]->anio, v[i]->ventas);
    }

    fclose(a);
}

void liberarArraysVentas(VentaPtr v){

        free(v);

}

void leerVentasDeArchivo(VentaPtr v[]){

    FILE * a = fopen("ventas.txt", "r");
    int j=0;
    int anioAux=0;
    int ventasAux=0;

    while(fscanf(a,"%d;%d\n",&anioAux,&ventasAux)!= EOF){
        VentaPtr aux = (VentaPtr)malloc(sizeof(struct Venta));
        aux->anio=anioAux;
        aux->ventas=ventasAux;
        v[j]=aux;

        j++;}
    fclose(a);
}

int buscarVentasPorAnio(VentaPtr v[],int t){
    int ventasAux=0;
    int busqueda=0;
    printf("\nIngrese el anio para buscar las ventas:\n");
    scanf("%d", &busqueda);

    for(int i=0; i<t; i++){
        if(v[i]->anio==busqueda){
            printf("\nEn el anio %d, las ventas fueron de %d\n",v[i]->anio,v[i]->ventas);
            ventasAux=v[i]->ventas;
            return ventasAux;
        }
    }
    if(ventasAux==0){
        printf("\nNo se encontro...\n");
        }
    return -1;
}

void promedioVentasDeTodosLosAnio(VentaPtr v[],int t){
    int prom=0;
    for(int i=0; i<t; i++){
        prom=prom+v[i]->ventas;
    }
    printf("\nEl promedio de ventas de todos los anios es: %.2f\n",(float)prom/t);
}

int contarReglonesArchivo(char nombArchivo[]){
    FILE *archivo;
    int contador = 0;
    char caracter;

    archivo = fopen(nombArchivo, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }
    // Recorrer el archivo caracter por caracter y contar las líneas
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            contador++;
        }
    }
    fclose(archivo); // Cerrar el archivo

    return contador;
}
