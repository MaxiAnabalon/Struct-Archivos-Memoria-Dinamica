#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

///Archivos
void crearoBorrarArchivo(char nombre[20]);
void guardarVectorenArchivo(int * v, int tam, char nombreArch[20]);
void leerVectordeArchivo(int * v, char nombreArch[20]);
int contadorDatosArchivos(char nombreArch);
int contarReglonesArchivo(char nombArchivo[]);



#endif // ARCHIVOS_H_INCLUDED
