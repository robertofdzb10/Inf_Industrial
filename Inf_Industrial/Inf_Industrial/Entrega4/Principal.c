#include <stdio.h>
#include <stdlib.h>
#include "Datos_t.h"

void *cargaDatos(int *dim); // Null cuando no puede obterner el conjunto de datos (dim = 0), Algo !Null si obtiene el conjunto de datos (dim = 16)


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
<<<<<<< HEAD
    void *datos = cargaDatos(&dim); // El puntero almacena una dirección, por lo que al meterle un puntero, le estamos introduciendo una dirección, la que esta apuntado, de ahí que introduzcamos &dim.
=======
    void *datos = cargaDatos(&dim); // // El puntero almacena una dirección, por lo que al meterle un puntero, le estamos introduciendo una dirección, la que esta apuntado, de ahí que introduzcamos &dim.
    if (datos == NULL || dim == 0){
        printf("Error al cargar los datos.\n");
        fclose(archivo);
        return 1;
    }

    Datos_t* p_datos = (Datos_t*)datos; // Convertir "datos" (puntero que devuelve cargaDatos()) en un puntero de "Datos_t", lo casteamos ya que el formato que devuelve la función es el de "sDatos_t"
>>>>>>> db3f8de (Update)

    // Imprimir los valores en el archivo de texto
    fprintf(archivo, "v1: %d\n", p_datos->v1);
    fprintf(archivo, "v2: %u\n", p_datos->v2); // %u especifican un entero sin signo
    fprintf(archivo, "v3: %d\n", p_datos->v3);
    fprintf(archivo, "v4: %d\n", p_datos->v4);
    fprintf(archivo, "v5: %u\n", p_datos->v5);
    fprintf(archivo, "v6: %d\n", p_datos->v6);
    fprintf(archivo, "v7: %u\n", p_datos->v7);
    fprintf(archivo, "v8: %u\n", p_datos->v8);
    fprintf(archivo, "v9: %d\n", p_datos->v9);
    fprintf(archivo, "....\n");

    fclose(archivo); // Cerramos el archivo
    free(datos); // Librerar la memoria reservada
    
    return 0;
}


