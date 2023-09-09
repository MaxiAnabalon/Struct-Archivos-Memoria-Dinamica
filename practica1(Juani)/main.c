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

            char datos [50] = "";

            while (!feof(archivo)){

                fgets(datos, 50, archivo);

                ciu = TransformarTextoACiudades(datos);
            }



            fclose(archivo);


        return ciu;
    };



    struct ciudad TransformarTextoACiudades(char c[50]){

        struct ciudad ciu;

        ///nombre de la ciudad --- habitantes

        ///busqueda del punto y coma
        int posDelDelimitador = -1;

        for (int i = 0; i < 50; i++){

            if (c[i] == ';'){

                posDelDelimitador = i;
                i = 100;
            }
        }

        //variable auxiliar

        char nombreAux [35] = "";
        char habitantesAux [15] = "";

        ///guarda el nombre
        for (int i = 0; i < posDelDelimitador; i++){

            nombreAux[i] = c[i];

        }

         ///guarda la cantidad de habitantes
         for (int i = posDelDelimitador+1; i < posDelDelimitador + 12; i++){

            habitantesAux [i - posDelDelimitador -1] = c[i];

        }

        ///GUARDARLO EN LA ESTRUCTURA

        strcpy(ciu.nombreC, nombreAux);
        ciu.habitantes = atoi (habitantesAux); ///<---- castear el char a INT



        return ciu;


    };
