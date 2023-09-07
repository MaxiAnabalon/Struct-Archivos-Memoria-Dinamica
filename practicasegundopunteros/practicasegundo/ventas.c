#include <stdio.h>
#include <stdlib.h>
#include "ventas.h"

typedef struct Ventas * VentasPtr;

void leerVentasDesdeArchivo(VentasPtr v[]){

int contador=0;
FILE * archivo;
archivo=fopen("ventas.txt","r");
int anioUno=0;
int unidV=0;

while(fscanf(archivo,"%d;%d\n",&anioUno,&unidV) != EOF){

    VentasPtr aux = malloc(sizeof(struct Ventas));

    printf("\nPrueba de como lee el archivo ANIO: %d\n", anioUno);
    printf("Prueba de como lee el archivo ANIO: %d\n", unidV);
    printf("HASTA AQUI LA LECTURA POR REGLON\n");//BORRAR ESTOS PRINT CUANDO QUIERAS... ERA SOLO PARA CHEQUEAR, LA STRUCT CARGA BIEN

    //fscanf(archivo,"%d,%d",&
    aux->anio = anioUno;
    aux->unidadesV = unidV;
    v[contador]= aux;
    //char aux[100]="";
    //fgets(aux,100,archivo);
    //buscarDelimitador(v,aux,contador);

    contador++;

}
fclose(archivo);
};

void mostrarVentas(VentasPtr v[]){

    for(int i=0;i<3;i++){
        printf("\nAnio:%d\n",v[i]->anio);
        printf("Ventas:%d\n",v[i]->unidadesV);
    }
};

void mostrarVentasTotales(VentasPtr v[]){
for(int i=0;i<3;i++){
    mostrarVentas(&v[i]);
}

};

void buscarDelimitador (VentasPtr v[100], char aux[100],int contador){
int ubicacion=0;
char aux1[100]="";
char aux2[100]="";

for (int i=0;i<100;i++){
    if (aux[i]==';'){
        ubicacion=i;
        i=100;
    }
}

for(int i=0;i<ubicacion;i++){
    aux1[i]=aux[i];
}
int inicioAux2=0;
for (int i=ubicacion+1;i<100;i++){
    aux2[inicioAux2]=aux[i];
    inicioAux2++;
}
v[contador]->anio=atoi(aux1);
v[contador]->unidadesV=atoi(aux2);

};

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
