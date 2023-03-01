#include <stdio.h>
#include "Equipo.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 15

void* LeeConfig(char *fichero); // Las clases que se usan en el main hay que declararlas antes de usarlas, sino el main no las reconoce

int main()
{
    Equipo* equipo = LeeConfig("DatosConfig.txt"); // Creamos un puntero de tipo Equipo, que apunte al equipo creado por LeeConfig()
    printf("Ordenador donde se situa el programa MES: %s\n", equipo->direccionIP);

    for (int i = 0; i < equipo->dispositivos; i++) {
        printf("Codigo del PLC(%d): %d,  direccion IP: %s\n", i+1, equipo->dispositivo[i].codigo, equipo->dispositivo[i].direccionIP);
    }

    free(equipo->dispositivo); // Liberamos la memoria, tras usar memoria dinámica
    free(equipo);

    return 0; // En el main si devuelvo 1 indicamos error
}

void* LeeConfig(char *fichero) // *void, puntero genérico, es decir que la función puede devolver cualquier tipo de puntero
{
    FILE *archivo;    // Puntero FILE para apuntar al archivo que se va a leer
    char buffer[100]; // buffer donde se almacenala líne a leer
    char mesIP[MAX];
    int boolmesIP = 0; // Variable bool (aunque es un entero) para ver si hemos econtrado la IP MES y acostumbrate a incializar las variables
    int numDispositivos;
    int boolnumDispositivos = 0;
    Equipo* equipo = malloc(sizeof(Equipo)); // Crea un puntero a un equipo, con la ventaja de que podemos usar memoría dinámica

    archivo = fopen(fichero, "r"); // Esta función devuele un puntero al fichero indicado. El segundo parámetro módo de apertura, r es para lectura
    if (archivo == NULL)
    {
        printf("La apertura del archivo fallo");
        return NULL; // Solo puedo devolver punteros o NULL
    }

    while (fgets(buffer, sizeof(buffer), archivo)) // Mientras haya líneas, las leemos // fgets() lee una línea de texto desde un archivo, y la almacena // -->Parámeros de la función // Puntero a un buffer de carácteres donde se alamcena la línea // Tamaño máximo de carácteres que se pueden leer // Puntero al archivo desde donde se va a leer la línea.
    {
        if (isspace(*buffer)) // Comprueba si en la línea hay solo espacios tabuladores y saltos de línea, toda línea al final tiene un salto de línea, por lo que si solo hay eso, esta en blanco
        {                     // Si la línea leída es una línea en blanco, salta y continua con la siguiente
            continue;
        }
        // Procesar la línea leída aquí

        // Leer la dirección IP del MES
        if (boolmesIP == 0)
        {                                        // Si no se ha encontrado todavía la mesIP
            sscanf(buffer, "IP_MES: %s", mesIP); // Convierte los valores leidos y almacenados en el buffer a datos
            strcpy(equipo->direccionIP, mesIP); //Al ser equipo un puntero, so es equipo.direccionIP, sino equipo->direccionIP
            //printf("Ordenador donde se situa el programa MES: %s\n", equipo.direccionIP);
            boolmesIP = 1; // Hay que ponerlo al final para que no entre en el siguiente if
        }

        // Almacenar el número de dispositivos
        else if (boolnumDispositivos == 0 && boolmesIP == 1)
        {                                              // Solo se ejecuta si la primera no se ejecuta
            sscanf(buffer, "N: %d", &numDispositivos); // Convierte los valores leidos y almacenados en el buffer a datos, el último parámetro es un puntero a la dirección donde se almacena
            equipo->dispositivos = numDispositivos;
            //printf("Numero de dispositivos que aloja el ordenador: %d\n", equipo.dispositivos);
            boolnumDispositivos = 1;
        }

        // Almacenar cada dispositivo
        else if (boolnumDispositivos == 1)
        {
            equipo->dispositivo = malloc(numDispositivos * sizeof(Dispositivo)); // La función malloc se utiliza para asignar memoria dinámicamente en tiempo de ejecución. Se introduce el espaco que deseamos ocupar, en este caso, lo que ocupa un dispositivo por el número de dispositivos.
            for (int i = 0; i < numDispositivos; i++)
            {
                char dispositivoIP[MAX]; // Lo creamos en cada vuelta del for, una para cada dispositivos
                int codigoDispositivo;
                sscanf(buffer, "%d: %s", &codigoDispositivo, dispositivoIP); // Convierte los valores leidos y almacenados en el buffer a datos, el último parámetro es un puntero a la dirección donde se almacena
                equipo->dispositivo[i].codigo = codigoDispositivo;
                strcpy(equipo->dispositivo[i].direccionIP, dispositivoIP);
                //printf("Codigo del PLC(1): %d,  direccion IP: %s\n", equipo.dispositivo[i].codigo, equipo.dispositivo[i].direccionIP);
            }
        }
    }
    fclose(archivo); // Cerramos el archivo

    return equipo;
}