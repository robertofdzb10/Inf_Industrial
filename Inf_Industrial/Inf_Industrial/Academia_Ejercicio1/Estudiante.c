#include <stdio.h>
#include "Profesor.h"
#define MAX 30

typedef struct {
    char nombre[MAX];
    int grupo;
    int nota;
    Profesor profesor;
} Estudiante;

