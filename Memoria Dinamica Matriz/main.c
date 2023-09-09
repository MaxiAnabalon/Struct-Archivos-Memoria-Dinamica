#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Matrices Dianmicas
int ** crearMatriz(int  r, int c);
void cargarMatrizAleatorio(int ** m, int r, int c);
void mostrarMatriz(int ** m, int r, int c);
void liberarMatriz(int ** m, int r);
int buscarElemento(int ** matriz, int filas, int columnas);
// Calcular suma y promedio de columnas
void sumaReglon(int ** m, int r, int c);
void sumaColumna(int ** m, int r, int c);
//Matriz archivo
void guardarMatrizEnArchivo(int **matriz, int r, int c);
void leerMatrizenArchivo(int **m, int r, int c);
;
/* TAREA
- BUSCAR EN UNA MATRIZ
- SUMA Y PROMEDIOS DE FILAS Y COLUMNAS
- RECUPERAR DESDE TXT
*/

int main()
{
    srand(time(0));
    int ** matriz;
    matriz = crearMatriz(3, 4);

    //cargarMatrizAleatorio(matriz, 3, 4);
    //leerMatrizenArchivo(matriz, 3, 4);
    mostrarMatriz(matriz, 3, 4);

    sumaReglon(matriz, 3, 4);
    sumaColumna(matriz, 3, 4);

    buscarElemento(matriz,  3,  4);
    guardarMatrizEnArchivo(matriz,  3,  4);
    liberarMatriz(matriz, 3);

    printf("\n-------- Matriz  Dinamico reutilizada ------\n");
    matriz = crearMatriz(2, 7);
    cargarMatrizAleatorio(matriz, 2, 7);
    mostrarMatriz(matriz, 2, 7);
    buscarElemento(matriz,  2,  7);

    return 0;
}

int ** crearMatriz(int  r, int c){
    int ** pMatriz = (int **) malloc (r * sizeof(int *));
    for (int i=0; i<r; i++){
        pMatriz[i] = (int *) malloc (c * sizeof(int));
    }
    return pMatriz;
}

void cargarMatrizAleatorio(int ** m, int r, int c){

    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            m[i][j] = rand() % 100+1;
        }
    }


}

void mostrarMatriz(int ** m, int r, int c){
    printf("\n------ Mostrar Matriz Dinamica ------\n");

    for (int i=0; i<r; i++){
        printf("[");
        for (int j=0; j<c; j++){
            printf(" %d ", m[i][j]);
        }
        printf("]\n");
    }


}
// Función para guardar una matriz en un archivo
void guardarMatrizEnArchivo(int **matriz, int r, int c) {
    FILE *archivo = fopen("matriz.txt", "w"); // Abrir el archivo en modo escritura

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Escribir la matriz en el archivo
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fprintf(archivo, "%d;", matriz[i][j]);

            /*if (j < c - 1) {
                fprintf(archivo, ";"); // Usar punto y coma como delimitador
            }*/
        }
        fprintf(archivo, "#"); // Nueva línea al final de cada fila
    }

    fclose(archivo); // Cerrar el archivo
}

/*
void guardarMatrizenArchivo(int **m, int r, int c){

    FILE * a = fopen("matriz.txt", "w");
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                fprintf(a,"%d;", m[i][j]);
            }
            fprintf(a,"\n");
        }
}

void leerMatrizenArchivo(int **m, int r, int c){

    FILE * a = fopen("matriz.txt", "r");
    int num=0;
        //while(fscanf(a,"%d;\n",&num)!= EOF){
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                fscanf(a,"%d;",&num);
                printf("%d", num);
                m[i][j]=num;
            }
            fscanf(a,"\n");

       }
}

void leerMatrizenArchivo(int * v, char nombreArch[20]){

    FILE * a = fopen(nombreArch, "r");
    int j=0;
    int num = 0;
    while(fscanf(a,"%d;\n",&num)!= EOF){
        //fgets(num,5, a);
        int posdelimitador=-1;
        for (int i=0; i<5; i++){
            if(num[i]== ';'){
                posdelimitador = i;
                i=50;}}
        char numAux[5] = "";
        for (int i=0; i<(posdelimitador); i++){
                numAux[i] = num[i];}
        v[j] = num;
        j++;}

    fclose(a);
}
*/
void liberarMatriz(int ** m, int r){

    for (int i=0; i<r; i++){
        free(m[i]);
    }
    free(m);
}

int buscarElemento(int ** matriz, int filas, int columnas){
    int objetivo=0;
    printf("\nIngrese el numero que  desea buscar:\n");
    scanf("%d", & objetivo);

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] == objetivo) {
                // Si se encuentra el elemento, devuelve su posición
                printf("\nNumero %d encontrado en la fila %d, columna %d\n", objetivo,i, j);
                return 1;
            }
        }
    }
    printf("\nNo se encontro el numero %d\n", objetivo);
    // Si el elemento no se encuentra, devuelve 0
    return 0;
}

void sumaReglon(int ** m, int r, int c){
    printf("\n------ Mostrar Suma Reglon ------\n");

    for (int i=0; i<r; i++){
        int suma = 0;
        for (int j=0; j<c; j++){
           suma = suma + m[i][j];
        }
        printf("\nSuma fila %d: [%d]\n",i, suma);
    }
}

void sumaColumna(int ** m, int r, int c){
    printf("\n------ Mostrar Suma columnas ------\n");

    for (int i=0; i<c; i++){
        int suma = 0;
        for (int j=0; j<r; j++){
           suma = suma + m[j][i];
        }
        printf("\nSuma fila %d: [%d]\n",i, suma);
    }
}
