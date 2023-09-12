#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jugador {
    char nombre[50];
    char apellido[50];
    int camiseta;
    float promedio_goles;
    char equipo[50];
};

typedef struct Jugador * JugadorPtr;


int contarReglonesArchivo(char nombArchivo[]);
void leerArrayJugadores(JugadorPtr array[]);
void mostrarJugador(JugadorPtr o);
void mostrarArraysJugadores(JugadorPtr o[], int t);
void guardarArraysJugadoresEnArchivo(JugadorPtr o[], int t);
void ordenarJugadorPorProm(JugadorPtr o[], int t);


int main()
{
    int tam=contarReglonesArchivo("jugador.txt");
    //int tam=5;
    JugadorPtr * jug;
    jug = (JugadorPtr *)malloc(sizeof(JugadorPtr)* tam);// Asigna memoria para un arrays de jugadores
    //JugadorPtr jug[tam];
    leerArrayJugadores(jug);
    mostrarArraysJugadores(jug, tam);
    ordenarJugadorPorProm(jug, tam);
    mostrarArraysJugadores(jug, tam);
    guardarArraysJugadoresEnArchivo(jug, tam);


    return 0;
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
void leerArrayJugadores(JugadorPtr array[]){

    FILE * archivo = fopen ("jugador.txt", "r");

        if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");}

        int j = 0;
        char nombreAux[50] = "";
        char apellAux[50] = "";
        int camiAux = 0;
        float promAux = 0;
        char equipoAux[50] = "";


        while (!feof(archivo)){

        fscanf(archivo, "%[a-zA-Z];%[a-zA-Z];%d;%f;%[a-zA-Z]\n", nombreAux, apellAux, &camiAux, &promAux ,equipoAux);

        //printf("\n---%s ----\n", apellAux);

        JugadorPtr aux = (JugadorPtr) malloc(sizeof(struct Jugador));

        strcpy(aux->nombre, nombreAux);
        strcpy(aux->apellido, apellAux);
        aux->camiseta = camiAux;
        aux->promedio_goles = promAux;
        strcpy(aux->equipo, equipoAux);
        array[j] = aux;

        j++;}
        fclose(archivo);
};


void ordenarJugadorPorProm(JugadorPtr o[], int t){

    JugadorPtr aux ;

    for ( int i = 0; i < t; i++){
        for ( int j = 0; j< t-1; j++){
            //ObraPtr aux = (ObraPtr) malloc(sizeof(struct Obra));
            if (o[j]->promedio_goles < o[j+1]->promedio_goles){
                aux = o[j];
                o[j] = o[j+1];
                o[j+1] = aux;
            }
        }
    }
    //sleep(5);
    system("pause");
    system("cls");

}

void guardarArraysJugadoresEnArchivo(JugadorPtr o[], int t){

    FILE * a = fopen("ordenado.txt", "w");

    for(int i=0; i<t; i++){
        fprintf(a,"%s;%s;%d;%f;%s\n", o[i]->nombre, o[i]->apellido, o[i]->camiseta, o[i]->promedio_goles, o[i]->equipo);
        }
    fclose(a);
}

void mostrarJugador(JugadorPtr o){
    printf("\n---- Jugador ----");
    printf("\nNombre: %s ", o->nombre);
    printf("\nApellido: %s " , o->apellido);
    printf("\nCamiseta: %d \n", o->camiseta);
    printf("\nPromedio de Goles: %.2f \n", o->promedio_goles);
    printf("\nEquipo: %s \n", o->equipo);
};

void mostrarArraysJugadores(JugadorPtr o[], int t){
    for(int i=0; i<t; i++){
        mostrarJugador(o[i]);
    }
}
