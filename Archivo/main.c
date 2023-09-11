#include <stdio.h>
#include <stdlib.h>

struct Persona{

    int dni;
    char nombre[40];

};

struct Persona pasarCharAStruct(char c[], int tam);

int main()
{
    printf("Archivos\n");


    //abrir nuestro archivo --- Para escribirlo
    //1- Abrir
    FILE * archivoEscribir;

    archivoEscribir = fopen("archivo1.txt", "a" );

    //2 escribir
    fprintf(archivoEscribir,
            "Estoy escribiendo un archivo\n<---deje un renglon\nAhora muestro con entero: %d", 55);

    fprintf(archivoEscribir, "\n\nBasta, ya escribi demasiado" );


    //3- cerrar el archivo
    fclose(archivoEscribir);




    //ahora vamos a leer un archivo
    FILE * archivoLeer;

    archivoLeer = fopen("archivo2.txt", "r" );

    while(!feof(archivoLeer)){


        char aux[40] = " ";
        fgets(aux, 40, archivoLeer);

        printf("----> %s", aux);

    }


    fclose(archivoLeer);





    struct Persona personasVector[50];

    int contador = 0;


    FILE * archivoAStruct;

    archivoAStruct = fopen("personas.txt", "r");

    while(!feof(archivoAStruct)){

        char aux[30] = " ";

        fgets(aux, 30, archivoAStruct);

        //printf("\n---->Linea:      %s", aux);

        personasVector[contador] = pasarCharAStruct(aux, 30);
        contador++;




    }




    fclose(archivoAStruct);


    for ( int i = 0; i<50;i++){

        printf("%s\n", personasVector[i].nombre);

    }





    return 0;
}


struct Persona pasarCharAStruct(char c[], int tam){

    struct Persona p;

    //olvidamos de los archivos

    int posicionPrimerMas = 0;


    char dniChar[10] = " ";
    char nombreChar[20]= " ";

    for ( int i = 0; i<tam; i++){

        //donde esta el +????
        if(c[i]=='+'){

            posicionPrimerMas = i;

        }

    }

     for ( int i = 0; i<posicionPrimerMas; i++){

        dniChar[i]= c[i];

     }



     for ( int i = posicionPrimerMas+1; i<tam; i++){

        nombreChar[i-posicionPrimerMas-1]= c[i];

     }

     strcpy(p.nombre, nombreChar);
     p.dni = atoi(dniChar);


return p;



};
