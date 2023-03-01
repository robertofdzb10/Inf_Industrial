#include "Dispositivo.h"
#define MAX 15

typedef struct {
    char direccionIP[MAX]; // Dirección IP del equipo donde se ejecuta cierta aplicación MES
    int dispositivos; // Número de dispositivos que se conectan a la aplicación MES
    Dispositivo dispostivo;
} PLC;