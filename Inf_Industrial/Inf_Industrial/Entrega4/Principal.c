#include <stdio.h>

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
    void *datos = cargaDatos(dim);

    // Imprimir los valores en el archivo de texto
    fprintf(archivo, "v1: -%d\n");
    fprintf(archivo, "v2: %u\n");
    fprintf(archivo, "v3: -%d\n");
    fprintf(archivo, "v4: -%d\n");
    fprintf(archivo, "v5: %u\n");
    fprintf(archivo, "v6: -%d\n");
    fprintf(archivo, "v7: %u\n");
    fprintf(archivo, "v8: %u\n");
    fprintf(archivo, "v9: -%d\n");
    fprintf(archivo, "....\n");

    fclose(archivo); // Cerramos el archivo
    
    
    return 0;
}
