#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

struct Empleado{
    char nombreYApellido[40];
    int diasTrabajados;
    int sueldoDiario;
    int SueldoMes;

};
typedef struct Empleado * EmpleadoPtr;

void cargarEmpleadosEnCero(EmpleadoPtr e[], int tam){

for(int i=0;i<tam;i++){
    EmpleadoPtr e=malloc(sizeof(struct Empleado));
    strcpy(e->nombreYApellido, "n");
    e->diasTrabajados=-1;
    e->sueldoDiario=-1;
    e->SueldoMes=-1;
}
};

int cargarEmpleadoPorTeclado(){

EmpleadoPtr aux = (EmpleadoPtr) malloc(sizeof(struct Empleado));
        printf("\nEscribir el Nombre y apellido del empleado:\n");
        fflush(stdin);
        gets(aux->nombreYApellido);

        printf("Dias trabajados:\n");
        scanf("%d",&aux->diasTrabajados);

        printf("Sueldo diario:\n");
        scanf("%d",&aux->sueldoDiario);

        printf("Sueldo Mensual:\n");
        scanf("%d",&aux->SueldoMes);
return aux;
};
//int buscarLugarVacio(EmpleadoPtr e,int tam){
//int lugarVacio=-5;
//for(int i=0;i<100;i++){
//    if(e->nombreYApellido==""){
 //       lugarVacio=i;
 //       i=101;
 //   }
//}
//return lugarVacio;
//};

void imprimirEmpleado(EmpleadoPtr e){

    if(e->nombreYApellido!=""){
        printf("\n====Nombre y apellido====:%s\n",e->nombreYApellido);
        printf("Dias trabajados:%d\n", e->diasTrabajados);
        printf("Sueldo diario:%d\n",e->sueldoDiario);
        printf("Sueldo Mensual:%d\n",e->SueldoMes);

}
};
void imprimirEmpleados(EmpleadoPtr e[], int tam){
for(int i=0;i<tam;i++){
        imprimirEmpleado(e[i]);
}
};

void cargarEmpleadosPorTeclado(EmpleadoPtr e[],int tam){
for(int i=0;i<tam;i++){
        e[i]=cargarEmpleadoPorTeclado();
}
};
