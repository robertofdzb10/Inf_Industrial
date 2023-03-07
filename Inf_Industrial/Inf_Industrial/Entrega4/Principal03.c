#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



void* cargaDatos(int* dim);

typedef struct micampodebits
{
    long v1 : 4;                //1 long
    unsigned long v2 : 16;
    unsigned long v3 : 12;
    long v3grande : 4;          //2 long
    long v4 : 2;
    unsigned long v5 : 26;
    unsigned long v5grande : 6; //3 long
    unsigned long v6 : 26;
    long v6grande : 6;          //4 long
    unsigned long v7 : 1;
    unsigned long v8 : 16;
    long v9 : 9;
}Campo;

int main()
{
    int dim;
    long cero = 0;
    Campo* camp = cargaDatos(&dim);
    long v3final = (camp->v3 | cero) | ((camp->v3grande | cero) << 12);
    long v5final = (camp->v5 | cero) | ((camp->v5grande | cero) << 26);
    long v6final = (camp->v6 | cero) | ((camp->v6grande | cero) << 26);
    
    FILE* f = fopen("fichero.txt", "a");
    if (!f)
    {
        printf("Error al abrir el fichero");
    }
    
    fprintf(f, "v1: %d\n", camp->v1);
    fprintf(f, "v2: %u\n", camp->v2);
    fprintf(f, "v3: %ld\n", v3final);
    fprintf(f, "v4: %d\n", camp->v4);
    fprintf(f, "v5: %lu\n", v5final);
    fprintf(f, "v6: %ld\n", v6final);
    fprintf(f, "v7: %u\n", camp->v7);
    fprintf(f, "v8: %u\n", camp->v8);
    fprintf(f, "v9: %d\n", camp->v9);
    fprintf(f, ".......\n");
}