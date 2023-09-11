#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "obras.h"
#include "museo.h"
//intentando guardar y leer archivos
void guardarMuseoEnArchivo(MuseoPtr m);
void guardarArraysObraEnArchivo(ObraPtr o[], int t);
void leerMuseoDeArchivo(MuseoPtr o);
///Agregar nueva obra por Precio
ObraPtr cargarObraPorTeclado();
void agregarObra(ObraPtr e[], int t, float p);
int buscarObraVacia(ObraPtr e[], int t, float p);
///Modificar Obra
void modificarObra(ObraPtr e[], int t,float p);
///Eliminar Obra
void eliminarObra(ObraPtr e[], int t, float p);
///Eliminar struct
void liberarMuseo(MuseoPtr e);
///Leer Arrays de Strcut Obras
void leerArrayObras(ObraPtr array[]);

int main()
{
    MuseoPtr m1;
    //leerMuseoDeArchivo(m1);

    m1=cargarMuseoParametro("Bellas Artes",  "Riobanba 1678");
    //leerArrayObras(m1->obras);
    mostrarMuseo(m1);
    //liberarMuseo(m1);
    ///agregar obra por precio o  -1, lo  demas es nulo
    //modificarObra(m1->obras, 10, 23000000);
    //agregarObra(m1->obras, 10, -1);
    //ordenarObrasPorNombre(m1->obras, 10);
    //seleccionMenuABM(m1->obras, 10);
    //eliminarObra(m1->obras, 10, 23000000);
    //buscarObraPorNombre(m1->obras, 10, "Noche Estrellada");
    //buscarObraPorPrecio(m1->obras, 10,230000);
    system("pause");
    //system("cls");
    mostrarMuseo(m1);

    //guardarMuseoEnArchivo(m1);

    return 0;
}

///LEER UN ARRAY DE MUSEOS
void leerArrayObras(ObraPtr array[]){

    FILE * archivo = fopen ("obra.txt", "r");

        int j = 0;
        char nombreAux[50] = "";
        char autorAux[50] = "";
        int precioAux = 0;


        while (fscanf(archivo,"%49[^;];%49[^;];%f;\n", nombreAux, autorAux, &precioAux) != EOF){

        ObraPtr aux = (ObraPtr)malloc(sizeof(struct Obra));

        strcpy(aux->nombreObra, nombreAux);
        strcpy(aux->autor, autorAux);
        aux->precio = precioAux;
        array[j] = aux;

        j++;}
        fclose(archivo);
};


void eliminarObra(ObraPtr e[], int t, float p){

    int resultado = buscarObraVacia(e, t, p);

    if( resultado != -1){
        printf("\n---- [%s] -- OBRA ELIMINADA -----\n\n", e[resultado]->nombreObra);
        e[resultado] = cargarObraParametro("vacio","vacio",-1);
        }
}

void modificarObra(ObraPtr  e[], int t,float p){

    int resultado = buscarObraVacia(e, t, p);

    if( resultado != 1){
        printf("\n---- Modificar Obra -----\n");
        e[resultado] = cargarObraPorTeclado();
    };
};

void agregarObra(ObraPtr e[], int t, float p){

   int posVacio = -1;
   //Busco pos
    posVacio = buscarObraVacia(e, t, p);


   if (posVacio != -1){

        ObraPtr eAgregar = cargarObraPorTeclado();
        e[posVacio]  = eAgregar;
   }
   else{
    printf("\nNo hay cupo!!!\n");
   }
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
    scanf("%f", &e->precio);

    return e;

};

int buscarObraVacia(ObraPtr  e[], int t, float p){

    int resultado = -1;

    for ( int i = 0; i<t; i++){

        if (e[i]->precio == p){

            resultado = i;
        }
    }
    return resultado;
}

void guardarMuseoEnArchivo(MuseoPtr m){

    FILE * a = fopen("museo.txt", "w");

        fprintf(a,"%s;%s;%s;%s;%d\n", m->nombreMuseo, m->direccion, m->dire->nombreDir, m->dire->apellidoDir, m->dire->dni);
        guardarArraysObraEnArchivo(m->obras , 10);

    fclose(a);
}

void liberarMuseo(MuseoPtr e){
    free(e);
}

void guardarArraysObraEnArchivo(ObraPtr o[], int t){

    FILE * a = fopen("obra.txt", "w");

    for(int i=0; i<t; i++){
        fprintf(a,"%s;%s;%f\n", o[i]->nombreObra, o[i]->autor, o[i]->precio);
        }
    fclose(a);
}

void leerMuseoDeArchivo(MuseoPtr o){

    FILE * archivo = fopen("museo.txt", "r");
    if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");}
    //char a[15];
    char b[15];
    char c[15];
    //char d[15];
    int x=0;
    int j=0;
    while (!feof(archivo)) {
        //MuseoPtr o = malloc(sizeof(struct Museo));
        fscanf(archivo,"%49[^;];%49[^;];%49[^;];%49[^;];%d\n",
               o->nombreMuseo,
               o->direccion,
               b,
               c,
               &x);

        o->dire=cargarDirectorParametro(b, c, x);


    j++;
    }
    fclose(archivo);
}
/*
void leerObrasDeArchivo(MuseoPtr m[]){

    FILE * archivo = fopen("obra.txt", "r");
    if (archivo == NULL) {
        printf("\nNo se pudo abrir el archivo.\n");}
    char a[15];
    char b[15];
    //char c[15];"%49[^;];%49[^;];%f\n"
    //char d[15];"%d,%[a-zA-Z],%f,%[a-zA-Z]\n"
    float x=0;
    int j=0;
    while (!feof(archivo)){
        //MuseoPtr o = malloc(sizeof(struct Museo));
            fscanf(archivo,"%[a-zA-Z];%[a-zA-Z];%f\n",a , b, & x);
              printf("\n\n--- %s  %s   %f----\n\n", a,  b,  x);
              // m[j]->autor,
              // m[j]->nombreObra,
             // &m[j]->precio);
    j++;
    }
    fclose(archivo);
}
*/
/*
void leerObrasDeArchivo(ObraArte *obras, int maxObras, int *numObras) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    *numObras = 0;
    char linea[100];

    while (*numObras < maxObras && fgets(linea, sizeof(linea), archivo) != NULL) {
        if (sscanf(linea, "%49[^;];%49[^;];%lf", obras[*numObras].titulo, obras[*numObras].autor, &obras[*numObras].precio) == 3) {
            (*numObras)++;
        } else {
            printf("Formato de línea incorrecto: %s\n", linea);
        }
    }

    fclose(archivo);
}
*/
/*

void leerVentasDesdeArchivo(VentasPtr v[]){

    int contador=0;
    FILE * archivo;
    archivo=fopen("ventas.txt","r");
    int anioUno=0;
    int unidV=0;

    while(fscanf(archivo,"%d;%d\n",&anioUno,&unidV) != EOF){

    VentasPtr aux = malloc(sizeof(struct Ventas));

    printf("\nPrueba de como lee el archivo ANIO: %d\n", anioUno);
    printf("Prueba de como lee el archivo ANIO: %d\n", unidV);
    printf("HASTA AQUI LA LECTURA POR REGLON\n");//BORRAR ESTOS PRINT CUANDO QUIERAS... ERA SOLO PARA CHEQUEAR, LA STRUCT CARGA BIEN

    //fscanf(archivo,"%d,%d",&
    aux->anio = anioUno;
    aux->unidadesV = unidV;
    v[contador]= aux;
    //char aux[100]="";
    //fgets(aux,100,archivo);
    //buscarDelimitador(v,aux,contador);

    contador++;

}*/
/*
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


*/

/*
//segun el retorno del numero del menu ejecuta funcion
void seleccionMenuABM(ObraPtr m[], int tam){
        int opcion;
        do{
            printf("\n----Elija una Opcion de ALTA, BAJA, MODIFICACION----\n\n");
            printf("1- ALTA. \n2- BAJA. \n3- MODIFICAR. \ n4- Salir\n\nIngrese opcion: ");
            scanf("%d",& opcion);
        while(opcion < 1 || opcion > 4){printf("\n****ERROR ingrese un opcion valida****"); break;
        //int metodoOrden, tipoOrden;
        switch(opcion){
            case (1): {agregarObra(m->obras, 10, -1); break;};

            case (2): {modificarObra(m->obras, 10, 23000000); break;}

            case (3): {eliminarObra(m->obras, 10, 23000000); ;break;}

            case (4): {printf("Salio del programa, presione una tecla para cerrar consola....\n");
                exit("");};
            }
        }while(opcion < 1 || opcion > 4);
}
*/
