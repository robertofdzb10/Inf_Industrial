#include <stdio.h>
#include <assert.h>

int main(){
    LeeConfig("DatosConfig.txt");
    return 0; // En el main si devuelvo 1 indicamos error. 
}

void *LeeConfig(char *fichero){  // *void, puntero genérico, es decir que la función puede devolver cualquier tipo de puntero     
    FILE *archivo; // Puntero FILE para apuntar al archivo que se va a leer                                        
    archivo = fopen(fichero, "r"); // Esta función devuele un puntero al fichero indicado. El segundo parámetro módo de apertura, r es para lectura
    if (archivo == NULL){
        printf("La apertura del archivo fallo");
        return NULL; // Solo puedo devolver punteros o NULL
    }
    fclose(archivo); // Cerrramos el archivo
}