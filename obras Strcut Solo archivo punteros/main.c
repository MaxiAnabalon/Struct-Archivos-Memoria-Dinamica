#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Obra{
    char nombreObra[20];
    char autor[20];
    int precio;
};


typedef struct Obra * ObraPtr;


int contarReglonesArchivo(char nombArchivo[]);
void liberarObra(ObraPtr o[],int t);
ObraPtr cargarObraParametro(char nom[20], char autor[20], int p);
void cargarArraysObras(ObraPtr o[], int t);
void mostrarObra(ObraPtr o);
void mostrarArraysObras(ObraPtr o[], int t);
void ordenarObrasPorNombre(ObraPtr o[], int t);
void buscarObraPorNombre(ObraPtr o[], int t, char busq[20]);
void buscarObraPorPrecio(ObraPtr o[], int t, int p);
void leerArrayObras(ObraPtr array[]);
void guardarArraysObraEnArchivo(ObraPtr o[], int t);
void ordenarObrasPorPrecio(ObraPtr o[], int t);
ObraPtr cargarObraPorTeclado();
/// ABM Agregar nueva obra por Precio
void agregarObra(ObraPtr e[], int t);
int buscarObraVacia(ObraPtr e[], int t, int p);
///Modificar Obra
void modificarObra(ObraPtr  e[], int t,int p);
///Eliminar Obra
void eliminarObra(ObraPtr e[], int t, int p);
void cargarObraPosicion(ObraPtr o[], int t,int pos);//cargar obra por teclado en posicion
void menuVectorAgreagarObraPosicion(ObraPtr o[], int t);///menu  para agreagr obra,  falta mejorar

int main()
{
    //int tam=contarReglonesArchivo("obra.txt");
    int tam=10;
    ObraPtr *ob;
    ob = (ObraPtr *)malloc(sizeof(ObraPtr)* tam);// Asigna memoria para un arrays de obras
    //ObraPtr ob[tam];
    cargarArraysObras(ob, tam);
    //leerArrayObras(ob);
    mostrarArraysObras(ob, tam);
    //ordenarObrasPorNombre(ob, tam);
    //mostrarArraysObras(ob, tam);
    //ordenarObrasPorPrecio(ob, tam);
    //mostrarArraysObras(ob, tam);
    //buscarObraPorPrecio(ob, tam, 230);
    //agregarObra(ob, tam);
    //modificarObra(ob, tam, 0);
    //eliminarObra(ob, tam, 230);
    guardarArraysObraEnArchivo(ob, tam);
    liberarObra(ob, tam);

    printf("\n------------ Reutilizo el arrays de Struct Obras con otro tamanio ----------\n");
    //sleep(2);
    system("pause");
    tam=5;
    ob = (ObraPtr *)malloc(sizeof(ObraPtr)* tam);
    cargarArraysObras(ob, tam);
    mostrarArraysObras(ob, tam);

    return 0;
}

ObraPtr cargarObraPorTeclado(){

    //system("pause");
    //system("cls");
    printf("\nVamos a ingresar un nueva Obra...\n\n");

    ///Obra de mi funciòn
    ObraPtr e = malloc(sizeof(struct Obra));

    printf("Ingrese la Obra:\n");
    fflush(stdin);
    gets(e->nombreObra);

    printf("Ingrese Autor:\n");
    fflush(stdin);
    gets(e->autor);

    printf("Ingrese precio:\n");
    scanf("%d", &e->precio);

    return e;

};
/*
void menuVectorAgreagarObraPosicion(ObraPtr o[], int t){
    int cant=t;
    int aux=-1;
    do{
        printf("\n----Tiene %d obras, elija una posicio para agregar----\n\n");
        scanf("%d",& aux);
        if(aux >= 0 && aux < t){cargarObraPosicion(o,t,aux);
            }
        else{printf("\n****ERROR ingrese un posicio valida****\n");
        menuVectorAgreagarObraPosicion(o, t); break;}
    }while(aux < 0 || aux > t);

}*/

ObraPtr cargarObraParametro(char nom[20], char autor[20], int p){

    ObraPtr o = (ObraPtr) malloc(sizeof(struct Obra));

    strcpy(o->nombreObra, nom);
    strcpy(o->autor, autor);
    o->precio=p;

    return o;
};

void cargarObraPosicion(ObraPtr o[], int t,int pos){
    o[pos]=cargarObraPorTeclado();
};

void cargarArraysObras(ObraPtr o[], int t){

    for(int i=0; i<t; i++){
        o[i]=cargarObraParametro("vacio","vacio", -1);
    }
    o[0]=cargarObraParametro("Noche Estrellada","Van Gogh",230);
    o[1]=cargarObraParametro("El Beso","Gustav Klimt",170);
    o[2]=cargarObraParametro("El Grito","Edvard Munch",110);
};

void mostrarObra(ObraPtr o){
    printf("\n---- Obra ----");
    printf("\nNombre: %s ", o->nombreObra);
    printf("\nAutor: %s " , o->autor);
    printf("\nCosto: %d \n", o->precio);
};

void mostrarArraysObras(ObraPtr o[], int t){
    for(int i=0; i<t; i++){
        mostrarObra(o[i]);
    }
}

void ordenarObrasPorNombre(ObraPtr o[], int t){

    ObraPtr aux ;

    for ( int i = 0; i < t; i++){
        for ( int j = 0; j< t-1; j++){
            //ObraPtr aux = (ObraPtr) malloc(sizeof(struct Obra));
            if ( strcmp(o[j]->nombreObra ,  o[j+1]->nombreObra) == 1){
                aux = o[j];
                o[j] = o[j+1];
                o[j+1] = aux;
            }
        }
    }
    //sleep(5);
    system("pause");
    //system("cls");

}

void ordenarObrasPorPrecio(ObraPtr o[], int t){

    ObraPtr aux ;

    for ( int i = 0; i < t; i++){
        for ( int j = 0; j< t-1; j++){
            //ObraPtr aux = (ObraPtr) malloc(sizeof(struct Obra));
            if (o[j]->precio < o[j+1]->precio){
                aux = o[j];
                o[j] = o[j+1];
                o[j+1] = aux;
            }
        }
    }
    //sleep(5);
    system("pause");
    system("cls");

}

void buscarObraPorNombre(ObraPtr o[], int t, char busq[20]){
    int e=0;
    for(int i=0; i<t; i++){
        if(strcmp(o[i]->nombreObra, busq) == 0){
            printf("\n---- Obra Encontrada ----");
            mostrarObra(o[i]);
            e=1;
            printf("\n--------------------------");
        }
    }
    if (e==0){printf("\nObra no encontrada...\n");}
}

void buscarObraPorPrecio(ObraPtr o[], int t, int p){
    int e=0;
    for(int i=0; i<t; i++){
        if(o[i]->precio == p){
            printf("\n---- Obra Encontrada por precio ----");
            mostrarObra(o[i]);
            e=1;
            printf("--------------------------\n");
        }
    }
    if (e==0){printf("\nObra no encontrada por precio...\n\n");}
}

void leerArrayObras(ObraPtr array[]){

    FILE * archivo = fopen ("obra.txt", "r");

        if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");}

        int j = 0;
        char nombreAux[50] = "";
        char autorAux[50] = "";
        int precioAux = 0;


        while (fscanf(archivo,"%49[^;];%49[^;];%d\n", nombreAux, autorAux, &precioAux) != EOF){

        ObraPtr aux = (ObraPtr)malloc(sizeof(struct Obra));

        strcpy(aux->nombreObra, nombreAux);
        strcpy(aux->autor, autorAux);
        aux->precio = precioAux;
        array[j] = aux;

        j++;}
        fclose(archivo);
};

void guardarArraysObraEnArchivo(ObraPtr o[], int t){

    FILE * a = fopen("obra.txt", "w");

    for(int i=0; i<t; i++){
        fprintf(a,"%s;%s;%d\n", o[i]->nombreObra, o[i]->autor, o[i]->precio);
        }
    fclose(a);
}

void liberarObra(ObraPtr o[], int t){
    for (int i = 0; i < t; i++){
    free(o[i]);}
}

void agregarObra(ObraPtr e[], int t){

    int posVacio = -1;
   //Busco posicion
    posVacio = buscarObraVacia(e, t, -1);


   if (posVacio != -1){
        ObraPtr eAgregar = cargarObraPorTeclado();
        e[posVacio]  = eAgregar;
   }
   else{
    printf("\nNo hay cupo!!!\n");
   }
}


int buscarObraVacia(ObraPtr  e[], int t, int p){

    int resultado = -1;

    for ( int i = 0; i<t; i++){

        if (e[i]->precio == p){
            resultado = i;
            i=t;
            }
    }
    return resultado;
}


void modificarObra(ObraPtr  e[], int t,int p){

    int resultado = buscarObraVacia(e, t, p);

    if( resultado != -1){
        printf("\n---- Modificar Obra -----\n");
        e[resultado] = cargarObraPorTeclado();
    }
    else{printf("\nObra no existe!!!\n");}
};


void eliminarObra(ObraPtr e[], int t, int p){

    int resultado = buscarObraVacia(e, t, p);

    if( resultado != -1){
        printf("\n---- [%s] -- OBRA ELIMINADA -----\n\n", e[resultado]->nombreObra);
        e[resultado] = cargarObraParametro("vacio","vacio",-1);
    }
    else{printf("\nObra no existe!!!\n");}
}

int contarReglonesArchivo(char nombArchivo[]){
    FILE *archivo;
    int contador = 0;
    char caracter;
    archivo = fopen(nombArchivo, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return -1;
    }
    // Recorrer el archivo caracter por caracter y contar las líneas
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') {
            contador++;
        }
    }
    fclose(archivo); // Cerrar el archivo
    return contador;
}

