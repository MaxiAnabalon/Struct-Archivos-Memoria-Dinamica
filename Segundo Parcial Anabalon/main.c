#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos una estructura para representar a un jugador
struct Jugador {
    char nombre[50];
    char apellido[50];
    int camiseta;
    float promedio_goles;
    char equipo[50];
};


int contarReglonesArchivo(char nombArchivo[]);

main{

    // Ordenar los jugadores por promedio de goles
    //qsort(jugadores, num_jugadores, sizeof(struct Jugador), comparar);

    /*// Abrir el archivo para escritura
    archivo = fopen("ordenados.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura\n");
        return 1;
    }

   // Guardar los jugadores ordenados en "ordenados.txt"
    for (int i = 0; i < num_jugadores; i++) {
        fprintf(archivo, "%s;%s;%d;%.2f;%s\n", jugadores[i].nombre,
                                                jugadores[i].apellido,
                                                jugadores[i].edad,
                                                jugadores[i].promedio_goles,
                                                jugadores[i].equipo);
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("Jugadores ordenados y guardados en 'ordenados.txt'\n");*/

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

void leerArrayJugadores(ObraPtr array[]){

    FILE *archivo = fopen("jugador.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    // Leer los jugadores del archivo
    struct Jugador jugadores[100];
    int num_jugadores = 0;

    while (fscanf(archivo, "%[^;];%[^;];%d;%f;%s\n", jugadores[num_jugadores].nombre,
                                                     jugadores[num_jugadores].apellido,
                                                     &jugadores[num_jugadores].camiseta,
                                                     &jugadores[num_jugadores].promedio_goles,
                                                     jugadores[num_jugadores].equipo) != EOF) {
        num_jugadores++;
    }

    // Cerrar el archivo
    fclose(archivo);
}
