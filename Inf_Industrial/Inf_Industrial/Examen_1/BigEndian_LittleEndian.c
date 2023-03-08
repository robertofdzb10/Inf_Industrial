#include <stdint.h>
#include <stdio.h>

unsigned char BigEndian_LittleEndian(unsigned char valor)
{
    unsigned char temporal = 0;

    for (int i = 0; i < 8; i++)
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