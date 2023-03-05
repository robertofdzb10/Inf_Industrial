#include <stdio.h>
#include <stdlib.h>

void *cargaDatos(int *dim); // Null cuando no puede obterner el conjunto de datos (dim = 0), Algo !Null si obtiene el conjunto de datos (dim = 16)

typedef struct { // Estructura proporcionada por el profesor
    long v1 : 4; // Variable long a la cual se le han asignado 4 bits de memoria
    unsigned long v2 : 16;
    long v3 : 16; // Colisión de dos bloques, separar en dos
    long v4 : 2; 
    unsigned long v5: 32; // Colisión de dos bloques, separar en dos
    long v6 : 32; // Colisión de dos bloques, separar en dos
    unsigned long v7 : 1;
    unsigned long v8 : 16;
    long v9 : 9;
} datos_t;

int main()
{
    FILE *archivo; // Puntero al archivo
    archivo = fopen("registro.txt", "a"); // El modo de apertura "w" indica que el archivo se abrirá para escritura, el modo "a" significa que se agregará contenido sin sobrescribir. Si el archivo no existe, se creará.
    if (archivo == NULL)
    {
        printf("La apertura del archivo fallo");
        return 1; // Entra en esta sentencia y acaba el main 
    }

    int dim;
    datos_t *datos = (datos_t *)cargaDatos(dim);
    
    if (datos == NULL)
    {
        printf("La lectura de los datos fallo");
        return 1; // Entra en esta sentencia y acaba el main 
    }

    // Imprimir los valores en el archivo de texto
    fprintf(archivo, "v1: -%d\n", datos->v1);
    fprintf(archivo, "v2: %u\n", datos->v2);
    fprintf(archivo, "v3: -%d\n", datos->v3);
    fprintf(archivo, "v4: -%d\n", datos->v4);
    fprintf(archivo, "v5: %u\n", datos->v5);
    fprintf(archivo, "v6: -%d\n", datos->v6);
    fprintf(archivo, "v7: %u\n", datos->v7);
    fprintf(archivo, "v8: %u\n", datos->v8);
    fprintf(archivo, "v9: -%d\n", datos->v9);
    fprintf(archivo, "....\n");

    fclose(archivo); // Cerramos el archivo
    
    free(datos);
    
    
    return 0;
}
