#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char buffer[1000];
    char **cadenas;
    int i, n;

    cadenas = NULL;
    n = 0;
    printf("Introduzca una cadena en cada lines\n\n");
    while (gets(buffer) != NULL)
    {
        if (strcmp(buffer, "<FIN>") == 0)
        {
            break;
        }
        cadenas = (char **)realloc(cadenas, (n + 1) * sizeof(char *));
        if (cadenas == NULL)
        {
            printf("Error reservando nemoria\n");
            n = 0;
            break;
        }
        cadenas[n] = (char *)malloc(strlen(buffer) + 1);
        if (cadenas[n] == NULL)
        {
            printf("Error reservando nemoria\n");
            break;
        }
        else
        {
            strcpy(cadenas[n], buffer);
            n++;
        }
    }

    printf("Cerrando el programa\n");
    if (cadenas != NULL)
    {
        for (i = 0; i < n; i++)
        {
            if (cadenas[i] != NULL)
            {
                printf("A punto de borrar la cadena: %s\n", cadenas[i]);
                free(cadenas[i]);
            }
        }
        free(cadenas);
    }
    return (0);
}