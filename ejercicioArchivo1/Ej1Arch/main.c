#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"

int main()
{
    int cantidad = 100;
    ProductoPtr productos [cantidad];

    cargarProductos(productos,cantidad);
    mostrarProductos(productos,cantidad);

    ProductoPtr p1 = crearProductoPorTeclado();
    ProductoPtr p2 = crearProductoPorTeclado();

    agregarProductos(productos, p1, cantidad);
    agregarProductos(productos, p2, cantidad);
    ordenarProductos(productos, cantidad);
    mostrarProductos(productos, cantidad);

    guardarProductos(productos,cantidad);

    return 0;
}
