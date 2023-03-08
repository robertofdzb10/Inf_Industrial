#include <stdint.h>
#include <stdio.h>
#define TAMANO 8

unsigned char BigEndian_LittleEndian(unsigned char valor)
{
    unsigned char temporal = 0; // 0 = 0000 0000

    for (int i = 0; i < TAMANO; i++)
    {
        temporal |= ((valor >> i) & 1) << (7 - i);
    }

    return temporal;
}

int main()
{
    unsigned char a = 127;

    a = BigEndian_LittleEndian(a);

    printf("Valor rotado a la izquierda: %u\n", a);

    return 0;
}