#include <stdio.h>
#include <stdlib.h>
#include <string.h>




    struct persona {

    char nombreP [20];
    int edad;

    };

    struct ciudad {

    char nombreC [20];
    int habitantes;
    struct persona formanparte[3];

    };



    struct persona cargarTeclado (); ///leer datos

    void mostrarPersona (struct persona p);

    void guardarPersona (struct persona p); ///GUARDAR PERSONA

    void cargarPersonas (struct persona array[], int t);

    void mostrarPersonas (struct persona array[], int t);


    struct ciudad cargarPorTeclado();

    void mostrarCiudad (struct ciudad c);

    void guardarCiudad (struct ciudad c); ///GUARDAR CIUDAD


    ///cargar y leer desde archivo

    struct ciudad leerCiudad();



    struct ciudad TransformarTextoACiudades(char c[50]);


int main()
{

/*
        int cant = 2;

        struct persona per[cant];

        for (int i = 0; i < cant; i++){

            per[i] = cargarTeclado();

         }

         ///mostrarlas

         for (int i = 0; i < cant; i++){

            mostrarPersona(per[i]);

         }

         */

         ///struct ciudad c1 = cargarPorTeclado(); ///se lee desde la consola
         ///mostrarCiudad(c1);

         ///guardarCiudad(c1);


         struct ciudad c1 = leerCiudad();

         mostrarCiudad(c1);


    return 0;
}

    ///1 SOLA
    struct persona cargarTeclado(){

        struct persona x;

        printf("\n#########CARGAR NUEVA PERSONA#########\n");
        ///DATOS DE LA ESTRUCTURA PERSONA
        printf("\n\nIngresar el nombre de la persona\n");
        fflush (stdin);
        gets(x.nombreP);

        printf("Ingresar la edad de la persona\n");
        scanf("%d", &x.edad);

     return x;
}


    ///1 SOLA
    ///MOSTRAR PERSONA
    void mostrarPersona (struct persona p){

        printf("\n\n#########PERSONA#########");

        printf("\nNombre de la persona: %s\n Edad: %d", p.nombreP, p.edad);

    }


    ///CARGAR ARRAY DE PERSONAS
    void cargarArray (struct persona array[], int t){

        for (int i = 0; i < t; i++){

            array[i] = cargarTeclado();

    }

    }

    ///MOSTRAR ARRAY DE PERSONAS
    void mostrarArray (struct persona array[], int t){

    for (int i = 0; i < t; i++){

        mostrarPersona(array[i]);

    }

    };


    ///CARGAR CIUDAD

    struct ciudad cargarPorTeclado() {

    struct ciudad c;

    printf("\n#########CARGAR NUEVA CIUDAD#########\n");
        ///DATOS DE LA ESTRUCTURA CIUDAD
        printf("\n\nIngresar el nombre de la ciudad\n");
        fflush (stdin);
        gets(c.nombreC);

        printf("Ingresar la cantidad de habitantes\n");
        scanf("%d", &c.habitantes);

        cargarArray(c.formanparte, 3);

     return c;


    };

    void mostrarCiudad (struct ciudad c){

        printf("\n\n#########CIUDAD#########");

        printf("\nNombre de la ciudad: %s\nNumero de habitantes: %d", c.nombreC, c.habitantes);

        mostrarArray(c.formanparte, 3);

    }


    void guardarCiudad (struct ciudad c) {

        FILE * archivo;
        archivo = fopen ("ciudades.txt", "w");


        fprintf (archivo, "%s;%d\n", c.nombreC, c.habitantes);


        for (int i = 0; i < 3; i++){

            guardarPersona(c.formanparte[i]);

        }


        fclose(archivo);

    }



    void guardarPersona (struct persona p){

    FILE * archivo;
    archivo = fopen ("personas.txt", "a");

    fprintf(archivo, "%s,%d\n", p.nombreP, p.edad);


    fclose(archivo);

    }



struct ciudad leerCiudad(){

        struct ciudad ciu;

            FILE * archivo = fopen ("ciudades.txt", "r");

            //char datos [50] = "";
            char nombreAux [30] = "";
            int habitantesAux = 0;

            while (fscanf(archivo,"%49[^;];%d\n", nombreAux, &habitantesAux) != EOF){
                //fgets(datos, 50, archivo);
                //ciu = TransformarTextoACiudades(datos);
                strcpy(ciu.nombreC, nombreAux);
                ciu.habitantes = habitantesAux;
                }
            fclose(archivo);
        return ciu;
};



struct ciudad TransformarTextoACiudades(char c[50]){

        struct ciudad ciu;

        ///nombre de la ciudad --- habitantes

        ///busqueda del punto y coma
        char nombreAux [40] = "";
        char habitantesAux [7] = "";
        int posDelDelimitador = -1;

        for (int i = 0; i < 50; i++){

            if (c[i] == ';'){

                posDelDelimitador = i;
                i = 100;
            }
        }

        //variable auxiliar



        ///guarda el nombre
        for (int i = 0; i <(posDelDelimitador); i++){

            nombreAux[i] = c[i];

        }

         ///guarda la cantidad de habitantes
         for (int i = posDelDelimitador+1; i < posDelDelimitador + 7; i++){

            habitantesAux[i - posDelDelimitador -1] = c[i];

        }

        ///GUARDARLO EN LA ESTRUCTURA

        strcpy(ciu.nombreC, nombreAux);
        ciu.habitantes = atoi(habitantesAux); ///<---- castear el char a INT



        return ciu;


    };
/*
struct Personas tranformarDatoaPersona(char dato[50]){

    struct Personas persona;

    char nombreaux[15]="";
    char edad[5]= "";
    int posdelimitador=-1;

    for (int i=0; i<50; i++){
            if(dato[i]== ';'){
                posdelimitador = i;
                i=55;
            }
        }
    for (int i=0; i<(posdelimitador); i++){
                nombreaux[i] = dato[i];
        }
    for (int i=(posdelimitador+1); i<(posdelimitador+3); i++){
                edad[i-(posdelimitador+1)]= dato[i];
        }

    strcpy(persona.nombre, nombreaux);
    persona.edad = atoi(edad);

    return persona;
};
*/
/*
///contar Reglones de archivo
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
///
void leerCuidadDesdeArchivo(VentasPtr v[]){

    int contador=0;
    FILE * archivo;
    archivo=fopen("cuidades.txt","r");
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

    }
        fclose(archivo);
};
*/
