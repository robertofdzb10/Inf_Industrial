#include <stdio.h>
FILE *archivo; //Puntero FILE para apuntar al archivo que se va a leer      

int main(){ 
    archivo = fopen("DatosConfig.txt", "r"); //Esta función devuele un puntero al fichero indicado. El segundo parámetro módo de apertura, r es para lectura
    if (archivo == NULL){
        printf("La apertura del archivo fallo");
    } else{
        printf("La apertura del archivo fue satisfactoría");
    }
    //LeeConfig(archivo);
    fclose(archivo); //Cerrramos el archivo
    return 0;
}

void* LeeConfig(char *fichero){ //*void, puntero genérico, es decir que la función puede devolver cualquier tipo de puntero

}