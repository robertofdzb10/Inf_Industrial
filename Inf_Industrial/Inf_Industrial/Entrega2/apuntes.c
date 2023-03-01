#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char buffer[100];
    char mesIP[20];
    char plcIP[20];
    int numPLCs;
    int codigoPLC;

    fp = fopen("config.txt", "r");

    if (fp == NULL)
    {
        printf("Error al abrir el archivo.");
        return 1;
    }

    // Leer la dirección IP del MES
    fgets(buffer, 100, fp);
    sscanf(buffer, "IP_MES: %s", mesIP);
    printf("Ordenador donde se sitúa el programa MES: %s\n", mesIP);

    // Leer el número de PLCs
    fgets(buffer, 100, fp);
    sscanf(buffer, "N: %d", &numPLCs);

    // Leer la información de cada PLC
    for (int i = 0; i < numPLCs; i++)
    {
        fgets(buffer, 100, fp);
        if (sscanf(buffer, "%d: %s", &codigoPLC, plcIP) == 2)
        {
            printf("Codigo del PLC(%d): %02d, direccion IP: %s\n", i+1, codigoPLC, plcIP);
        }
    }

    fclose(fp);
    return 0;
}


    /*
    char linea[100];
    PLC plcs[100];
    int i = 0;
    while (fgets(linea, 100, archivo) != NULL) //Mientras haya líneas sigue
    // fgets() lee una línea de texto desde un archivo, y la almacena
    // -->Parámeros de la función
    // Puntero a un buffer de carácteres donde se alamcena la línea
    // Tamaño máximo de carácteres que se pueden leer
    // Puntero al archivo desde donde se va a leer la línea.
    {
        PLC plc;
        sscanf(linea, "%s %d", plc.direccionIP, plc.dispositivos); // Convierte los valores leidos a datos
        plcs[i] = plc;
        i++;
        printf("PLC %d: dirección IP = %s, dispositivos = %d\n", i + 1, plcs[i].direccionIP, plcs[i].dispositivos);
    } */