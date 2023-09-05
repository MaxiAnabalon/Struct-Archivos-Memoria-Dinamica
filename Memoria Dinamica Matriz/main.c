#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Matrices Dianmicas
int ** crearMatriz(int  r, int c);
void cargarMatrizAleatorio(int ** m, int r, int c);
void mostrarMatriz(int ** m, int r, int c);
void liberarMatriz(int ** m, int r);
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
    cargarMatrizAleatorio(matriz, 3, 4);
    mostrarMatriz(matriz, 3, 4);
    liberarMatriz(matriz, 3);
    printf("\n-------- Matriz  Dinamico reutilizada ------\n");
    matriz = crearMatriz(2, 7);
    cargarMatrizAleatorio(matriz, 2, 7);
    mostrarMatriz(matriz, 2, 7);

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
void liberarMatriz(int ** m, int r){

    for (int i=0; i<r; i++){
        free(m[i]);
    }
    free(m);
}
