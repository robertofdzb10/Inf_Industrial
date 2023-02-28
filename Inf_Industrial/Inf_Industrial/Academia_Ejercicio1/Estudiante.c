#include <stdio.h>
#define MAX 30
#include "Profesor.c"

typedef struct {
    char nombre[MAX];
    int grupo;
    int nota;
    Profesor profesor;
} Estudiante;

