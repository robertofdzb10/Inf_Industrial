#include <stdio.h>
#include <string.h>
#include "Estudiante.c" //En Estudiante ya esta profesor

int main()
{
    Estudiante cincoAprobados[5];
    Estudiante estudiantes[10];
    int contador = 0;
    
    // Inicializar cada estudiante y agregarlo al array
    strcpy(estudiantes[0].nombre, "Juan Perez"); // La función strcpy, permite copiar cadenas de carácteres
    estudiantes[0].grupo = 1;
    estudiantes[0].nota = 90;
    strcpy(estudiantes[0].profesor.nombre, "Maria Garcia");
    strcpy(estudiantes[0].profesor.materia, "Matematicas");

    strcpy(estudiantes[1].nombre, "Ana Rodriguez");
    estudiantes[1].grupo = 2;
    estudiantes[1].nota = 85;
    strcpy(estudiantes[1].profesor.nombre, "Luis Gomez");
    strcpy(estudiantes[1].profesor.materia, "Historia");

    strcpy(estudiantes[2].nombre, "Pedro Sanchez");
    estudiantes[2].grupo = 1;
    estudiantes[2].nota = 70;
    strcpy(estudiantes[2].profesor.nombre, "Ana Perez");
    strcpy(estudiantes[2].profesor.materia, "Biologia");

    strcpy(estudiantes[3].nombre, "Luisa Martinez");
    estudiantes[3].grupo = 3;
    estudiantes[3].nota = 95;
    strcpy(estudiantes[3].profesor.nombre, "Juan Torres");
    strcpy(estudiantes[3].profesor.materia, "Fisica");

    strcpy(estudiantes[4].nombre, "Miguel Diaz");
    estudiantes[4].grupo = 2;
    estudiantes[4].nota = 80;
    strcpy(estudiantes[4].profesor.nombre, "Carlos Ruiz");
    strcpy(estudiantes[4].profesor.materia, "Ingles");

    strcpy(estudiantes[5].nombre, "Sofia Gomez");
    estudiantes[5].grupo = 1;
    estudiantes[5].nota = 75;
    strcpy(estudiantes[5].profesor.nombre, "Ana Perez");
    strcpy(estudiantes[5].profesor.materia, "Biologia");

    strcpy(estudiantes[6].nombre, "David Garcia");
    estudiantes[6].grupo = 3;
    estudiantes[6].nota = 87;
    strcpy(estudiantes[6].profesor.nombre, "Juan Torres");
    strcpy(estudiantes[6].profesor.materia, "Fisica");

    strcpy(estudiantes[7].nombre, "Laura Torres");
    estudiantes[7].grupo = 2;
    estudiantes[7].nota = 92;
    strcpy(estudiantes[7].profesor.nombre, "Carlos Ruiz");
    strcpy(estudiantes[7].profesor.materia, "Ingles");

    strcpy(estudiantes[8].nombre, "Mario Jimenez");
    estudiantes[8].grupo = 3;
    estudiantes[8].nota = 89;
    strcpy(estudiantes[8].profesor.nombre, "Juan Torres");
    strcpy(estudiantes[8].profesor.materia, "Fisica");

    strcpy(estudiantes[9].nombre, "Carla Flores");
    estudiantes[9].grupo = 2;
    estudiantes[9].nota = 78;
    strcpy(estudiantes[9].profesor.nombre, "Carlos Ruiz");
    strcpy(estudiantes[9].profesor.materia, "Ingles");


    for (int i = 0; i < 10; i++)
    {
        if (estudiantes[i].nota >= 50 && strcmp(estudiantes[i].profesor.nombre, "Juan Torres") == 0 && contador < 5) // strcmp compara dos cadenas de carácteres y devuelve 0 si son iguales
        {
            cincoAprobados[contador] = estudiantes[i];
            // Imprimimos por pantalla los estudiantes elegidos
            printf("Estudiante %d\n", i + 1);
            printf("Nombre: %s\n", cincoAprobados[contador].nombre);
            printf("Grupo: %d\n", cincoAprobados[contador].grupo);
            printf("Nota: %d\n", cincoAprobados[contador].nota);
            printf("Profesor: %s, %s\n", cincoAprobados[contador].profesor.nombre, cincoAprobados[contador].profesor.materia);
            printf("\n");
            contador++;
        }
    }

    return 0;
}
