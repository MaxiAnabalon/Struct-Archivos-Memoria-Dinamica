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
    //mostrarEstudiantes(m->listaEstudiantes,TAM);


};

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

        fscanf(archivo, "%d,%[a-zA-Z],%f,%[a-zA-Z]\n",
            &(materia->listaEstudiantes[pos]->legajo),
            materia->listaEstudiantes[pos]->nombre,
            &(materia->listaEstudiantes[pos]->promedio),
            materia->listaEstudiantes[pos]->apellido);

        pos++;


    }
    fclose(archivo);
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

void cargarArrysMaterias(MateriaPtr m[],int t){

    for( int i = 0; i<t; i++){

        m[i]=cargarMateriaTeclado();}
}

void mostrarArrysMaterias(MateriaPtr m[],int t){
    for( int i = 0; i<t; i++){
        mostrarMateria(m[i]);}

}

void guardarDatosMateria(MateriaPtr m[],int t){

    FILE *archivo  = fopen("materias.txt","w");

        for( int i = 0; i<t; i++){

            fprintf(archivo,"%s,%d,%c\n", m[i]->nombreMateria, m[i]->codigo ,m[i]->turno);

    }

    fclose(archivo);
}

