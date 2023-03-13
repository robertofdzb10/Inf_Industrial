typedef struct { // Estructura proporcionada por el profesor
    long v1 : 4; // Variable long a la cual se le han asignado 4 bits de memoria
    unsigned long v2 : 16;
    unsigned long v3_1 : 12;
    long v3_2 : 4; // La segunda parte del long no precisa de signo
    long v4 : 2; 
    unsigned long v5_1 : 26;
    unsigned long v5_2 : 6;
    unsigned long v6_1 : 26; 
    long v6_2 : 6;
    unsigned long v7 : 1;
    unsigned long v8 : 16;
    long v9 : 9;
} Datos_t;