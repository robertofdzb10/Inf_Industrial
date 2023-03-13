#include <stdio.h>

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
    int *valores, *n;
    int contador = 0;

    // TODO borrar
    double prueba = 1.111111; 
    int prueba_1 = 1;
    tiempo = &prueba;
    valores = &prueba;
    // TODO borrar

    // recogeDatos(tiempo, valores,n);
    

    FILE *archivo;
    archivo = fopen("datos.text", "a");
    if (archivo == NULL){
        printf("La apertura del archivo fallo");
        return 1;
    }

    fprintf(archivo, "%03d: %8.3f segundos\n", (contador + 1), *tiempo); // 03 rellena con tres 0s, 8.3 imprime 8 carácteres en total 3 de los cuales en la parte decimal
    fprintf(archivo, "0x%X\n", *valores); // Valores en hexadecimal válidos
    fprintf(archivo, "Decimal 1\n");
    fprintf(archivo, "Decimal 2\n\n");

    return 0;
}
