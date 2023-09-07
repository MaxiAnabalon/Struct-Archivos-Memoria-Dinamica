#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Archivos
void crearoBorrarArchivo(char nombre[20]);
void cargarArchivoconVector(int * v, int tam, char nombreArch[20]);
void leerVectordeArchivo(int * v, char nombreArch[20]);
int contadorDatosArchivos(char nombreArch);


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
    char nombreArchivo[20]="archivoVector.txt";
    //crearoBorrarArchivo(nombreArchivo);
    int t=6;
    int * vector;
    vector = crearVector(t);
    //cargarVectorTeclado(vector, t);
    //cargarArchivoconVector(vector, t, nombreArchivo);
    leerVectordeArchivo(vector, nombreArchivo);
    mostrarVector(vector, t);
    liberarVector(vector);
    printf("\n-------- Vector Dinamico reutilizada ------\n");
    vector = crearVector(3);
    cargarVectorAleatorio(vector, 3);
    mostrarVector(vector, 3);

    return 0;
}
///Vector Dinamico
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

///Archivos
void crearoBorrarArchivo(char nombre[20]){
    FILE * a = fopen(nombre, "w");
    fclose(a);
}

void cargarArchivoconVector(int * v, int tam, char nombreArch[20]){

    FILE * a = fopen(nombreArch, "a");
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
