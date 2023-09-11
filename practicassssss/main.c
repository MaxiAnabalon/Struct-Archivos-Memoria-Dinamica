#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct museo * museoPtr;

museoPtr cargarMuseoParametros (char n[20], int inau);

museoPtr cargarMuseoTeclado ();

void mostrarMuseo(museoPtr m);

void guardarMuseo (museoPtr m); ///GUARDAR MUSEO EN TEXTO

void guardarArrayMuseo (museoPtr array[], int t); ///GUARDAR ARRAY DE MUSEOS EN TEXTO

void cargarArray (museoPtr array[], int t);

void mostrarArray (museoPtr array[], int t);

museoPtr leerMuseo(); ///LEER UN SOLO MUSEO

void leerArrayMuseo(museoPtr array[]);///LEER UN ARRAY DE MUSEOS

struct museo {

    char nombre[20];
    int inauguracion;

};

int main()
{

/*
    museoPtr array = leerMuseo();

    mostrarMuseo(array);

    */

    /*

    m1 = cargarMuseoParametros("Malas Artes", 2012);

    */

    /*

    m1 = cargarMuseoTeclado();

    mostrarMuseo(m1);

    guardarMuseo(m1);

    */

    /*

    m1 = leerMuseo();

    mostrarMuseo(m1);

    */



/*
    int t = 2;


    museoPtr *array = (museoPtr *)malloc(sizeof(museoPtr) * t);

    cargarArray(array, t);

    mostrarArray(array, t);



    free(array);

*/



///ACA ESCRIBO EN CONSOLA UN ARRAY Y SE ME GUARDA EN TXT ---

int t = 3;

museoPtr * array = (museoPtr *)malloc(sizeof(museoPtr) * t);

cargarArray(array, t);

guardarArrayMuseo(array, t);

mostrarArray(array, t);

free(array);

 ///------------------------------------------------------------------



 /*

///DE ARCHIVOS A LA ESTRUCTURAAAAAAAA--------------------------------

    museoPtr arrayDeMuseos[3];

    leerArrayMuseo(arrayDeMuseos);

    mostrarArray(arrayDeMuseos, 3);

///----------------------------------------------------------------

*/


    return 0;
}


museoPtr cargarMuseoParametros (char n[20], int inau){

    museoPtr m = (museoPtr) malloc (sizeof(struct museo));

    strcpy(m->nombre, n);
    m->inauguracion = inau;

}


museoPtr cargarMuseoTeclado (){

    museoPtr m = (museoPtr) malloc(sizeof(struct museo));

    char aux[20] = " ";

    printf("\n\nMuseo\n");

    printf("\nIngrese el nombre del museo:\n");
    fflush(stdin);
    gets(aux);
    strcpy(m->nombre, aux);

    printf("Ingrese el año de inauguracion:\n");
    scanf("%d",&m->inauguracion);

    return m;
};

void mostrarMuseo(museoPtr m){

    printf("\n\n---- MUSEO ----");
    printf("\nNombre: %s ", m->nombre );
    printf("\nAnio de inauguracion: %d \n" , m->inauguracion);


};

///ASI SE GUARDA ALGO EN UN ARCHIVO DE TEXTO
void guardarMuseo (museoPtr m) {

        FILE * archivo;
        archivo = fopen ("museo.txt", "w");

        fprintf (archivo, "%s;%d\n", m->nombre, m->inauguracion);

        fclose(archivo);

    }

museoPtr leerMuseo(){

    museoPtr mus = (museoPtr)malloc(sizeof(struct museo));

    FILE * archivo = fopen ("museo.txt", "r");

    char nombreAux[50] = "";
    int inauguracionAux = 0;

    while (fscanf(archivo, "%49[^;];%d\n", nombreAux, &inauguracionAux) != EOF){

        strcpy(mus->nombre, nombreAux);
        mus->inauguracion = inauguracionAux;

    }

        fclose(archivo);

       return mus;
};


///CARGAR ARRAY DE MUSEOS
    void cargarArray (museoPtr array[], int t){

        for (int i = 0; i < t; i++){

            array[i] = cargarMuseoTeclado();

    }

    }

///MUESTRO EL ARRAY DE MUSEOS
    void mostrarArray (museoPtr array[], int t){

    for (int i = 0; i < t; i++){

        mostrarMuseo(array[i]);

    }

    }


///GUARDAR UN ARRAY DE MUSEOS
    void guardarArrayMuseo (museoPtr array[], int t){

    FILE * archivo;

        archivo = fopen ("museo.txt", "w");

        for (int i = 0; i<t; i++){

             fprintf (archivo, "%s;%d\n", array[i]->nombre, array[i]->inauguracion);

        }

        fclose(archivo);

    }

    ///LEER UN ARRAY DE MUSEOS
void leerArrayMuseo(museoPtr array[]){

    FILE * archivo = fopen ("museo.txt", "r");

        int j = 0;
        char nombreAux[50] = "";
        int inauguracionAux = 0;


        while (fscanf(archivo, "%49[^;];%d\n", nombreAux, &inauguracionAux) != EOF){

        museoPtr aux = (museoPtr)malloc(sizeof(struct museo));

        strcpy(aux->nombre, nombreAux);
        aux->inauguracion = inauguracionAux;
        array[j] = aux;

        j++;}
        fclose(archivo);
};

