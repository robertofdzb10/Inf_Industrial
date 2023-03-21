//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <unistd.h> // Para usar el sleep() en mac 

//int leeCelulaFotoelectrica(void);
//int leeCodigoBarras(void* datos);

int main()
{
    
    while(1){ // Búcle principal
        printf("Hola\n");
        usleep(500 * 1000); // En vs sería sleep() y dentro de la función pondríamos ms. En mac usamos usleep() que esta en microsegundos por eso múltiplicamos 1000
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

