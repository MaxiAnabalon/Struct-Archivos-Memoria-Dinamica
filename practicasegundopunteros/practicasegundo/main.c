#include <stdio.h>
#include <stdlib.h>
#include "practicasegundo.h"
#include "empleado.h"
#include "ventas.h"


int main()
{

//int opcion=elegirOpciones();
//ejecutarOpciones(opcion);

//int tam=2;
//EmpleadoPtr Empleados[tam];
//cargarEmpleadosPorTeclado(Empleados, tam);
//imprimirEmpleados(Empleados, tam);
char nombreDelArchivoVentas[20]="ventas.txt";
int reglones = contarReglonesArchivo(nombreDelArchivoVentas);
printf("\nCantidad Reglones: -------- %d ----------\n", reglones);
VentasPtr ventas[3];
leerVentasDesdeArchivo(ventas);
//for(int i=0;i<3;i++){
 //       printf("Anio:%d\n",ventas[i]->anio);
 //       printf("Ventas:%d\n",ventas[i]->unidadesV);
  //  }
mostrarVentas(ventas);


    return 0;
}
