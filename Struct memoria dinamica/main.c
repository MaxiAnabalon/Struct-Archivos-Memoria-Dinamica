#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    int tam=contarReglonesArchivo("ventas.txt");

    //int tam=2;
    VentaPtr ven[tam];
    //ven=crearArrayVentas(tam);
    //cargarArraysVentas(ven, tam);

    leerVentasDeArchivo(ven);
    mostrarArraysVenta(ven, tam);
    buscarVentasPorAnio(ven, tam);
    promedioVentasDeTodosLosAnio(ven, tam);

    //guardarVentasEnArchivo(ven, tam);


    return 0;
}
