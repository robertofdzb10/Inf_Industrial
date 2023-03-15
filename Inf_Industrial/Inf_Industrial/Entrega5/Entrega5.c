#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"

char recogeDatos(double *tiempo, int *valores, int *n);

int main()
{
    double tiempo; // No hace falta que sean punteros, introduzco su dirección y más fácil
    int valores[20], n;
    int contador = 0, imprimirDecimal, mascara;
    unsigned int imprimirDecimalU;

    Datos *datos = NULL;

    while (1){ //Lo recorre continuamente (¿? Porque lo otro estaba mal)

        char devolucion = recogeDatos(&tiempo, valores, &n);
        if (devolucion == -2){
            break;
        }
        if (devolucion == -1){
            continue;
        }

        datos = (Datos*)realloc(datos,(contador+1)*sizeof(Datos));
        datos[contador].tiempo_d = tiempo;
        datos[contador].n_d = n;
        if (n > 20){
            printf("Error, se han introducido características de más de la pieza.");
            return 1;
        }
        datos[contador].valores_d = (int*)malloc(n * sizeof(int));
        if (datos == NULL || datos[contador].valores_d == NULL){
            printf("Error reservando memoria.");
            return 1;
        }
        for (int i = 0; i < n; i++){
            datos[contador].valores_d[i] = valores[i];
        }
        contador ++;
        
    }

    //Preparación de archivo
    FILE *archivo;
    archivo = fopen("datos.text", "a");
    if (archivo == NULL){
        printf("La apertura del archivo fallo");
        return 1;
    }

    //Escritura de datos en el archivo
    for (int i = 0; i < contador; i++){
        fprintf(archivo, "%03d: %8.3f segundos\n", (i + 1), datos[i].tiempo_d); // 03 rellena con tres 0s, 8.3 imprime 8 carácteres en total 3 de los cuales en la parte decimal
        for (int e = 0; e < datos[i].n_d; e++){
            fprintf(archivo, "%X ", datos[i].valores_d[e]); // Valores en hexadecimal válidos
        }
        if (datos[i].n_d > 0){ // Comprobamos si n = 0, de manera que si es iguala 0 no hay ningun valor para imprimir
            imprimirDecimal = (datos[i].valores_d[0]>>4) & 0x7; // 0111
            fprintf(archivo, "\n%d\t", imprimirDecimal); 

            // Sino existe el primer valor, no existe el segundo
            if (datos[i].n_d > 1){ 
            imprimirDecimal = (datos[i].valores_d[1]>>8) & 0x0000FFFF;
            fprintf(archivo, "%d\n\n", imprimirDecimal);
            } else {
                fprintf(archivo, "\n\n");
            }

        } else {
            fprintf(archivo, "\t");
            fprintf(archivo, "\n\n");
        }
    free(datos[i].valores_d); // Vamos liberando la memoria una a uno
    }

    // Librerar memoria y cerrar archivos
    fclose(archivo);
    free(datos);

    return 0;
}
