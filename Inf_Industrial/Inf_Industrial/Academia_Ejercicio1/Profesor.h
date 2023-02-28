#define MAX 30 //Todo loque lleva # sin punto y coma al final

typedef struct {
    char nombre[MAX];
    char materia[MAX];   
} Profesor;

Profesor createProfesor(void); //En el .h definimos estructuras e inicializamos las funciones que tenga nuestro .c