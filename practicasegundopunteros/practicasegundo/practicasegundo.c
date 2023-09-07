#include <stdio.h>
#include <stdlib.h>


int elegirOpciones(){
int opcion=-4;
//while(opcion!=0&&opcion!=1&&opcion!=2&&opcion!=3){
printf("ingrese una opcion\n0:leer desde archivo\n1:pasar a binario\n2:guardar el numero\n3:guardar en binario\ncualquier otro numero:salir\n");
scanf("%d",&opcion);
//}
return opcion;
} ;


void ejecutarOpciones(int o){;
switch(o){
    case 0: leer();break;
    case 1: numeroATransformar(pedirUnNumero());break;
    case 2: guardarNumero();break;
    case 3: guardarNumeroBinario();break;
    default: printf("adios");
}
};

int leer(){
int n=-4;
FILE *archivo;
 archivo=fopen("numero.txt", "r");
 fscanf(archivo,"%d",&n);
 fclose(archivo);
printf("%d",n);
return n;

};


int numeroATransformar(int n){

if(n<2){
    return n;
}else{
    return(n%2+(10*numeroATransformar(n/2)));
}
};

int pedirUnNumero(){
int n;
do{
printf("\nIngresar un numero mayor a cero para transformar en binario:\n");
scanf("%d",&n);

}while(n<0);

return n;
};

void guardarNumero(){
    printf("%d",pedirUnNumero());
};


void guardarNumeroBinario(){
int n=numeroATransformar(pedirUnNumero());
FILE *archivo;
archivo=fopen("numerobinario.txt", "a");
//scanf("%d",&n);
fprintf(archivo,"%d\n",n);
fclose(archivo);


};
