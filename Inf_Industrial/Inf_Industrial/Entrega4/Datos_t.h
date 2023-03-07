typedef struct { // Estructura proporcionada por el profesor
    long v1 : 4; // Variable long a la cual se le han asignado 4 bits de memoria
    unsigned long v2 : 16;
    long v3 : 16; // Colisión de dos bloques, separar en dos
    long v4 : 2; 
    unsigned long v5: 32; // Colisión de dos bloques, separar en dos
    long v6 : 32; // Colisión de dos bloques, separar en dos
    unsigned long v7 : 1;
    unsigned long v8 : 16;
    long v9 : 9;
} Datos_t;