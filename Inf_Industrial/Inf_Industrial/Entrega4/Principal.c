#include <stdio.h>
#include <stdlib.h>
#include "Datos_t.h"

void *cargaDatos(int *dim); // Null cuando no puede obterner el conjunto de datos (dim = 0), Algo !Null si obtiene el conjunto de datos (dim = 16)


int main()
{
    long v3, v6;
    unsigned long v5;

    FILE *archivo; // Puntero al archivo
    archivo = fopen("registro.txt", "a"); // El modo de apertura "w" indica que el archivo se abrirá para escritura, el modo "a" significa que se agregará contenido sin sobrescribir. Si el archivo no existe, se creará.
    if (archivo == NULL)
    {
        printf("La apertura del archivo fallo");
        return 1; // Entra en esta sentencia y acaba el main 
    }

    int dim;
<<<<<<< HEAD
    void *datos = cargaDatos(&dim); // El puntero almacena una dirección, por lo que al meterle un puntero, le estamos introduciendo una dirección, la que esta apuntado, de ahí que introduzcamos &dim.
=======
    void *datos = cargaDatos(&dim); // // El puntero almacena una dirección, por lo que al meterle un puntero, le estamos introduciendo una dirección, la que esta apuntado, de ahí que introduzcamos &dim.
    if (datos == NULL || dim == 0){
        printf("Error al cargar los datos.\n");
        fclose(archivo);
        return 1;
    }

<<<<<<< HEAD
    Datos_t* p_datos = (Datos_t*)datos; // Convertir "datos" (puntero que devuelve cargaDatos()) en un puntero de "Datos_t", lo casteamos ya que el formato que devuelve la función es el de "sDatos_t"
>>>>>>> db3f8de (Update)
=======
    Datos_t* p_datos = (Datos_t*)datos; // Convertir "datos" (puntero que devuelve cargaDatos()) en un puntero de "Datos_t", lo casteamos ya que el formato que devuelve la función es el de "Datos_t"

    v3 = p_datos->v3_2; // Cargamos los 4 primeros bits
    v3 = (v3 << 12); // Desplazamos a la izquierda 12 posiciones, introduciendo 0s
    v3 = (v3 | p_datos->v3_1); // Hacemos un or con v3_1, de manera que los 0 que hemos introducido cambien a uno, para representar a v3_1

    v5 = p_datos->v5_2;
    v5 = (v5 << 26);
    v5 = (v5 | p_datos->v5_1);

    v6 = p_datos->v6_2;
    v6 = (v6 << 26); //Aqui problema, con el 1 primero creo
    v6 = (v6 | p_datos->v6_1);
>>>>>>> 6c59160 (Update)

    // Imprimir los valores en el archivo de texto
    fprintf(archivo, "v1: %d\n", p_datos->v1);
    fprintf(archivo, "v2: %u\n", p_datos->v2); // %u especifican un entero sin signo
    fprintf(archivo, "v3: %ld\n", v3);
    fprintf(archivo, "v4: %d\n", p_datos->v4);
    fprintf(archivo, "v5: %lu\n", v5);
    fprintf(archivo, "v6: %ld\n", v6);
    fprintf(archivo, "v7: %u\n", p_datos->v7);
    fprintf(archivo, "v8: %u\n", p_datos->v8);
    fprintf(archivo, "v9: %d\n", p_datos->v9);
    fprintf(archivo, "....\n");

    fclose(archivo); // Cerramos el archivo
    free(datos); // Librerar la memoria reservada
    
    return 0;
}


