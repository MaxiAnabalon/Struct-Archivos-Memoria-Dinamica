#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

struct Estudiante{

    int legajo;
    char nombre[15];
    float promedio;
    char apellido[15];


};

typedef struct Estudiante * EstudiantePtr;

void mostrarEstudiante(EstudiantePtr est);

EstudiantePtr cargarEstudianteTeclado();
EstudiantePtr cargarEstudiante(int l, float p, char n[15], char a[15]);

///Arreglo de estructuras
void cargarEstudiantes( EstudiantePtr e[], int t);
void mostrarEstudiantes( EstudiantePtr e[], int t);


///Ordenar los estudiantes
void ordenarEstudiantesLegajo( EstudiantePtr e[], int t);
void ordenarEstudiantesApellido( EstudiantePtr e[], int t);

///Buscar un estudiante
int buscarEstudiante( EstudiantePtr e[], int t, int l );

///Clase nueva Anidar Struct
EstudiantePtr cargarEstudianteNulo();
void cargarEstudiantesNulos( EstudiantePtr e[], int t);

///Elimina estudiante por legajo
void eliminarEstudiante(EstudiantePtr  e[], int t, int l );
void modificarEstudiante(EstudiantePtr  e[], int t, int l );


#endif // ESTUDIANTE_H_INCLUDED
