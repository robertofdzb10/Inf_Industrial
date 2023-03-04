#include <stdio.h>

int main()
{
    int registro_16_bits[16] = {0}; // Inicializamos el array a {0}. Registro de salidas digitales de 16 bits, un int son 4 bytes, es decir, 32 bits
    int num_elementos = sizeof(registro_16_bits) / sizeof(registro_16_bits[0]); // Para obtener el número de elementos de un array, sizeof(mi_array) devuelve el tamaño total del array en bytes, dividir este tamaño por el tamaño de un elemento nos da el número de elementos.
    int num_bucles = 3; // Número de búcles
    int contador = 0; // Contador de búcles

    while(contador != num_bucles){
        for(int i = 0; i<num_elementos; i++){ // Llevamos a cavo todas la interacciones, una por cada elemento del array
                for(int e = 0; e<num_elementos; e++){ // Escribimos en cada una de las interacciones, en cada uno de los elementos del array
                    if (i == e || i == (num_elementos-1-e) ){
                        registro_16_bits[e] = 1;
                    } else {
                        registro_16_bits[e] = 0;
                    }
                    printf("%d ", registro_16_bits[e]);
                }
            printf("\n");
        }
        contador++;
    }

    return 0;
}


