#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vectores.h"
#include "archivos.h"


///Archivos
void crearoBorrarArchivo(char nombre[20]){
    FILE * a = fopen(nombre, "w");
    fclose(a);
}

void guardarVectorenArchivo(int * v, int tam, char nombreArch[20]){

    FILE * a = fopen(nombreArch, "w");
    for(int i=0; i<tam; i++){
        fprintf(a,"%d;\n", v[i]);
    }
    fclose(a);
}

void leerVectordeArchivo(int * v, char nombreArch[20]){

    FILE * a = fopen(nombreArch, "r");
    int j=0;
    int num = 0;
    while(fscanf(a,"%d;\n",&num)!= EOF){
        //fgets(num,5, a);
        /*int posdelimitador=-1;
        for (int i=0; i<5; i++){
            if(num[i]== ';'){
                posdelimitador = i;
                i=50;}}
        char numAux[5] = "";
        for (int i=0; i<(posdelimitador); i++){
                numAux[i] = num[i];}*/
        v[j] = num;
        j++;}

    fclose(a);
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
