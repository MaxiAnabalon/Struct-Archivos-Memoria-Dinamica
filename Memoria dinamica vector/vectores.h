#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED

///Funciones de Vectores Dinamicos
int * crearVector(int  tam);
void cargarVectorAleatorio(int * v, int tam);
void cargarVectorTeclado(int * v, int tam);
void mostrarVector(int * v, int tam);
void liberarVector(int * v);
int busquedaSecuencialNumeroVector(int * v, int tam);
int busquedaBinariaNumeroVector(int * v, int tam);
void ordenBurbuja(int * v, int tam);
void ordenSeleccion(int * v, int tam);
void ordenInsercion(int * v, int tam);


#endif // VECTORES_H_INCLUDED
