#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct Venta{
    int anio;
    int ventas;
};

typedef struct Venta * VentaPtr;


VentaPtr cargarVentasTeclado();
VentaPtr crearArrayVentas(int t);
void cargarArraysVentas(VentaPtr v[], int t);
void mostrarVenta(VentaPtr v);
void mostrarArraysVenta(VentaPtr v[], int t);
void guardarVentasEnArchivo(VentaPtr v[], int t);
void liberarArraysVentas(VentaPtr v);
void leerVentasDeArchivo(VentaPtr v[]);
int buscarVentasPorAnio(VentaPtr v[],int t);
void promedioVentasDeTodosLosAnio(VentaPtr v[],int t);
int contarReglonesArchivo(char nombArchivo[]);



#endif // FUNCIONES_H_INCLUDED
