#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"

char recogeDatos(double *tiempo, int *valores, int *n);

// Valor entero si ha recogido un nuevo bloque 
// -1 si no hay nuevos valores  

// -2 sino devuelve nada y no hay datos de más piezas

// tiempo, intervalo de timepo que ha tardado el fabricantee en el lote actual
// valores, array de enteros (tamaño max. 20) relacionados con las caracterísitcas de la pieza
// n, núemro de posciones del anterior array

int main()
{
    double *tiempo;
    int *valores, *n; // Valores lo hago un puntero por que no se su tamaño
    int contador = 0, imprimirDecimal, enteroCero = 0, mascara;
    unsigned int imprimirDecimalU;

    Datos *datos = (Datos*)malloc(sizeof(Datos));
    if (datos == NULL){
        printf("Error reservando memoria.");
        return 1;
    }


    // TODO borrar
    /*
    double prueba = 1.111111; 
    int prueba_1 = 1;
    tiempo = &prueba;
    valores = &prueba;
    */
    // TODO borrar


    while (recogeDatos(tiempo, valores, n) != -2){ // Mientras haya valores para devolver
        datos[contador].tiempo_d = tiempo; // Puntero con puntero ¿?
        datos[contador].n_d = n;
        if (n < 20){
            printf("Error, se han introducido características de más de la pieza.");
            return 1;
        }
        datos[contador].valores_d = (Datos*)malloc(*n * sizeof(int));
        if (datos == NULL || datos[contador].valores_d == NULL){
            printf("Error reservando memoria.");
            return 1;
        }
        for (int i = 0; i < n; i++){
            datos[contador].valores_d[i] = valores;
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
            fprintf(archivo, "0x%X ", *(valores + e)); // Valores en hexadecimal válidos
        }
        if (datos[i].valores_d[0] != NULL){ // Es NULL o -1 ¿?
            mascara = enteroCero&(00111000); // Rellena el número en binario con ceros a la iquierda ¿?
            imprimirDecimal = datos[i].valores_d[0]&mascara;
            fprintf(archivo, "\n%d\t", imprimirDecimal); 

            // Sino existe el primer valor, no existe el segundo
            if (datos[i].valores_d[1] != NULL){ 
            mascara = enteroCero&(0110);
            imprimirDecimal = datos[i].valores_d[1]&mascara;
            fprintf(archivo, "\n%d\t", imprimirDecimal);
            } else {
                fprintf(archivo, "n\n");
            }

        } else {
            fprintf(archivo, "\t");
            fprintf(archivo, "\n\n");
        }
    }

    // Librerar memoria y cerrar archivos
    fclose(archivo);
    free(datos->valores_d); // Vale con liberar en general valores_d
    free(datos);

    return 0;
}
