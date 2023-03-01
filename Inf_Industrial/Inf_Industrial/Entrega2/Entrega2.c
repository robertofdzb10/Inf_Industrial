#include <stdio.h>
#include "PLC.h"

void *LeeConfig(char *fichero); // Las clases que se usan en el main hay que declararlas antes de usarlas, sino el main no las reconoce

int main()
{
    LeeConfig("DatosConfig.txt");
    return 0; // En el main si devuelvo 1 indicamos error
}

void *LeeConfig(char *fichero) // *void, puntero genérico, es decir que la función puede devolver cualquier tipo de puntero
{
    FILE *archivo;                 // Puntero FILE para apuntar al archivo que se va a leer
    archivo = fopen(fichero, "r"); // Esta función devuele un puntero al fichero indicado. El segundo parámetro módo de apertura, r es para lectura
    if (archivo == NULL)
    {
        printf("La apertura del archivo fallo");
        return NULL; // Solo puedo devolver punteros o NULL
    }


    char linea[100];
    PLC plcs[100];
    int i = 0;
    while (fgets(linea, 100, archivo) != NULL) //Mientras haya líneas sigue
    // fgets() lee una línea de texto desde un archivo, y la almacena
    // Parámeros de la función
    //  Puntero a un buffer de carácteres donde se alamcena la línea
    //  Tamaño máximo de carácteres que se pueden leer
    //  Puntero al archivo desde donde se va a leer la línea.
    {
        PLC plc;
        sscanf(linea, "%s %d", plc.direccionIP, plc.dispositivos); //Convierte los valores leidos a datos
        plcs[i] = plc;
        i++;
        printf("PLC %d: dirección IP = %s, dispositivos = %d\n", i + 1, plcs[i].direccionIP, plcs[i].dispositivos);
    }

    
    fclose(archivo); // Cerramos el archivo
}