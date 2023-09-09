#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.h"
#include "materia.h"

void mostrarMateria(MateriaPtr m){

    //system("cls");
    printf("\n\n------MATERIA-----\n");
    printf("NOMBRE: %s\n", m->nombreMateria );
    printf("CODIGO: %d\n", m->codigo );
    printf("TURNO: %c\n\n", m->turno );

    ///Mostrar Estudiantes
    mostrarEstudiantes(m->listaEstudiantes,TAM);


};


void mostrarMaterias(MateriaPtr materias[], int t){

    for ( int i =0 ; i<t; i++){

        mostrarMateria(materias[i]);
    }

}

MateriaPtr cargarMateriaTeclado(){

    MateriaPtr aux = malloc(sizeof(struct Materia));

    printf("\nNombre materia:\n");
    fflush(stdin);
    gets(aux->nombreMateria);

    printf("\nCodigo materia:\n");
    scanf("%d", &aux->codigo );

    printf("\nTurno materia:\n");
    fflush(stdin);
    scanf("%c", &aux->turno );

    cargarEstudiantesNulos(aux->listaEstudiantes, TAM);


    return aux;

};



MateriaPtr cargarMateriaNula(){

    MateriaPtr aux = malloc(sizeof(struct Materia));

   aux->codigo = -1;
   strcpy(aux->nombreMateria, "VACIA");
   aux->turno  = 'V';

    cargarEstudiantesNulos(aux->listaEstudiantes, TAM);


    return aux;

};
void agregarEstudiante(EstudiantePtr e[], int t){

   int posVacia = -1;



   //Busco pos
   posVacia = buscarEstudiante(e, TAM, -1);

   if (posVacia != -1){
        EstudiantePtr eAgregar = cargarEstudianteTeclado();
        e[posVacia]  = eAgregar;
   }
   else{

    printf("\nNo hay cupo!!!\n");
   }



}



void cargarEstudiantesDesdeArchivo(MateriaPtr materia) {

    FILE *archivo;

    archivo = fopen("estudiantes.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;

    while (!feof(archivo)) {

        int codMateria;
        int legajo;
        float promedio;
        char nombre[15];
        char apellido[15];

        fscanf(archivo, "%d,%[a-zA-Z],%f,%[a-zA-Z],%d\n",&legajo,nombre,&promedio,apellido,&codMateria);

        if(codMateria == materia->codigo){ ///Si el estudiante es de la materia lo cargo

            strcpy(materia->listaEstudiantes[pos]->apellido, apellido);
            strcpy( materia->listaEstudiantes[pos]->nombre, nombre);
            materia->listaEstudiantes[pos]->promedio = promedio;
            materia->listaEstudiantes[pos]->legajo = legajo;

            pos++;
        }




    }
    fclose(archivo);
}



void cargarMateriasDesdeArchivo(MateriaPtr materias[]) {

    FILE *archivo;

    archivo = fopen("materias.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int pos = 0;

    while (!feof(archivo)) {



        materias[pos]= cargarMateriaNula();

        fscanf(archivo, "%d,%[a-zA-Z],%c\n",&materias[pos]->codigo, materias[pos]->nombreMateria, &materias[pos]->turno);



            pos++;


    }
    fclose(archivo);



    for (int i = 0 ; i<2; i++){

        cargarEstudiantesDesdeArchivo(materias[i]);

    }


}




void guardarDatos(MateriaPtr m){


    FILE *archivo  = fopen("estudiantes.txt","w");

    for( int i = 0; i<TAM; i++){


        if (m->listaEstudiantes[i]->legajo != -1){

            fprintf(archivo, "%d,%s,%f,%s\n", m->listaEstudiantes[i]->legajo,m->listaEstudiantes[i]->nombre,m->listaEstudiantes[i]->promedio,m->listaEstudiantes[i]->apellido);


        }

    }

    fclose(archivo);



}


