#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct Empleado;
typedef struct Empleado * EmpleadoPtr;
void cargarEmpleadosEnCero();
void imprimirEmpleados(EmpleadoPtr e[], int tam);
int cargarEmpleadoPorTeclado();
int buscarLugarVacio(EmpleadoPtr e);
void imprimirEmpleado(EmpleadoPtr e);



#endif // EMPLEADO_H_INCLUDED
