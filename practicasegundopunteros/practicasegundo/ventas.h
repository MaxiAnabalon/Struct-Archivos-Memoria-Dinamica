#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED


struct Ventas{
    int anio;
    int unidadesV;
};

typedef struct Ventas * VentasPtr;
void leerVentasDesdeArchivo(VentasPtr v[]);
void mostrarVentasTotales(VentasPtr v[]);
void mostrarVentas(VentasPtr v[]);
void buscarDelimitador (VentasPtr v[], char aux[3],int contador);
int contarReglonesArchivo(char nombArchivo[]);



#endif // VENTAS_H_INCLUDED
