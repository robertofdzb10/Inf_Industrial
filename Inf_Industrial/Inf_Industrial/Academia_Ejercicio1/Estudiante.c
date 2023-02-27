#include <stdio.h>
#define MAX 30
#include "Profesor.c"

typedef struct {
    char nombre[MAX];
    char grupo[MAX];
    int nota;
    Profesor profesor;
} Estudiante;

