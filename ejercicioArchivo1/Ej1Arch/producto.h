#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

struct Producto{

    char nombre[20];
    float precio;

};

typedef struct Producto * ProductoPtr;

ProductoPtr crearProductoPorTeclado();

void mostrarProducto (ProductoPtr prod);

void iniciarProductos(ProductoPtr prod[], int tam);

int buscarPosDisponible(ProductoPtr prod[], int tam);

void agregarProductos(ProductoPtr prod[],ProductoPtr p, int tam);

void mostrarProductos(ProductoPtr prod[], int tam);

ProductoPtr transformarTextoAProducto(char c[],int tam);

void ordenarProductos(ProductoPtr prod[], int t);

void cargarProductos(ProductoPtr prod[], int tam);

void guardarProductos(ProductoPtr prod[], int tam);

#endif // PRODUCTO_H_INCLUDED
