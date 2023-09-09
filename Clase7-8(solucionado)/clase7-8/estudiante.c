#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estudiante.h"



void mostrarEstudiante( EstudiantePtr est){


    if ( est->legajo != -1){
        printf("\n------ESTUDIANTE-----\n");
        printf("\nNOMBRE: %s", est->nombre );
        printf("\nAPELLIDO: %s", est->apellido );
        printf("\nPROMEDIO: %f", est->promedio );
        printf("\nLEGAJO: %d\n", est->legajo );

    }

};

 EstudiantePtr cargarEstudianteTeclado(){

    system("pause");
    system("cls");
    printf("Vamos a ingresar un estudiante...\n");

    ///Estudiante de mi funciòn
     EstudiantePtr e = malloc(sizeof(struct Estudiante));

    printf("Ingrese el nombre:\n");
    fflush(stdin);
    gets(e->nombre);

    printf("Ingrese el apellido:\n");
    fflush(stdin);
    gets(e->apellido);

    printf("Ingrese el promedio:\n");
    scanf("%f", &e->promedio);

    printf("Ingrese el legajo:\n");
    scanf("%d", &e->legajo);

    return e;

};


EstudiantePtr  cargarEstudiante(int l, float p, char n[15], char a[15]){


    EstudiantePtr e = malloc(sizeof(struct Estudiante));

    e->legajo = l;
    e->promedio = p;

    //e.nombre = n
    strcpy(e->nombre, n);
    strcpy(e->apellido, a);

    return e;
};



void cargarEstudiantes( EstudiantePtr e[], int t){

    for ( int i = 0 ; i<t; i++){

        e[i] = cargarEstudianteTeclado();

    }


};

void mostrarEstudiantes(EstudiantePtr  e[], int t){


    for ( int i = 0 ; i<t; i++){

        mostrarEstudiante(e[i]);

    }


};



void ordenarEstudiantesLegajo(EstudiantePtr  e[], int t){

    EstudiantePtr  aux;

    for ( int i = 0; i < t; i++){


        for ( int j = 0; j< t-1; j++){


            if ( e[j]->legajo >  e[j+1]->legajo ){

                aux = e[j];
                e[j] = e[j+1];
                e[j+1] = aux;


            }

        }


    }




};



void ordenarEstudiantesApellido(EstudiantePtr  e[], int t){

    EstudiantePtr  aux;

    for ( int i = 0; i < t; i++){


        for ( int j = 0; j< t-1; j++){


            if ( strcmp(e[j]->apellido ,  e[j+1]->apellido) == 1){

                aux = e[j];
                e[j] = e[j+1];
                e[j+1] = aux;


            }

        }


    }




};


int buscarEstudiante(EstudiantePtr  e[], int t, int l ){

    int resultado = -1;

    for ( int i = 0; i<t; i++){

        if ( e[i]->legajo == l){

            resultado = i;
        }


    }

    return resultado;
};


EstudiantePtr  cargarEstudianteNulo(){


    EstudiantePtr  e = malloc(sizeof(struct Estudiante));

    e->legajo = -1;
    e->promedio = -1;

    //e.nombre = n
    strcpy(e->nombre, "VACIO");
    strcpy(e->apellido, "VACIO");


    return e;
};


void cargarEstudiantesNulos(EstudiantePtr  e[], int t){

    for ( int i = 0 ; i<t; i++){

        e[i] = cargarEstudianteNulo();

    }



}


void eliminarEstudiante(EstudiantePtr  e[], int t, int l ){

    int resultado = buscarEstudiante(e,t,l);

    if( resultado != -1){

        e[resultado] = cargarEstudianteNulo();


    };
};



void modificarEstudiante(EstudiantePtr  e[], int t, int l ){

    int resultado = buscarEstudiante(e,t,l);

    if( resultado != 1){

        e[resultado] = cargarEstudianteTeclado();


    };
};





