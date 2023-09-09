#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#define TAM 200

#include "estudiante.h" ///Nuevo  26-6

struct Materia{

    char nombreMateria[20];
    int codigo;
    char turno;

    ///Muchos estudiantes!!!!
    EstudiantePtr  listaEstudiantes[TAM];


};

typedef struct Materia * MateriaPtr;

void mostrarMateria(MateriaPtr m);

MateriaPtr cargarMateriaTeclado();


void agregarEstudiante( EstudiantePtr e[], int t);


void cargarEstudiantesDesdeArchivo(MateriaPtr materia);

void guardarDatos(MateriaPtr m);
///cargar y mostrar arrays de materias
void cargarArrysMaterias(MateriaPtr m[],int t);
void mostrarArrysMaterias(MateriaPtr m[],int t);

///Guardar Arrayas de Materia en Archivo

void guardarDatosMateria(MateriaPtr m[],int t);


#endif // MATERIA_H_INCLUDED
