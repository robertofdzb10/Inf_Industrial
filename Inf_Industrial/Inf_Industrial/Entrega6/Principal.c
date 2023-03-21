//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unistd.h> // Para usar el sleep() en mac 

//int leeCelulaFotoelectrica(void);
//int leeCodigoBarras(void* datos);

int main()
{
    while(1){ // Búcle principal
        printf("Hola");
        sleep(5);
    }

    //Preparación del archivo 
    FILE *archivo;
    archivo = fopen("codigoBarras.txt", "a");
    if (archivo == NULL){
        printf("La apertura del archivo fallo");
        return 1;
    }

    //Escritura de datos en el archivo


    // Librerar memoria y cerrar archivos
    fclose(archivo);

    return 0;
}

