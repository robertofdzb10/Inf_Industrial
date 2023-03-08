#include <stdio.h>
#define TAMANO 8

unsigned char rotarIZD(unsigned char valor, int nPosiciones);
unsigned char rotarDCHA(unsigned char valor, int nPosiciones);

int main()
{
    unsigned char a = 127;
    unsigned char b = 254;

    a = rotarIZD(a,1);
    b = rotarDCHA(b,1);

    printf("Valor rotado a la izquierda: %u\n",a);
    printf("Valor rotado a la derecha: %u\n",b);

    return 0;
}

unsigned char rotarIZD(unsigned char valor, int nPosiciones){
    unsigned char temporal = valor;
    temporal = (valor >> (TAMANO - nPosiciones));
    valor = (valor << nPosiciones);
    valor = valor | temporal;
    return valor;
}

unsigned char rotarDCHA(unsigned char valor, int nPosiciones){
    unsigned char temporal = valor;
    temporal = (valor << (TAMANO - nPosiciones));
    valor = (valor >> nPosiciones);
    valor = valor | temporal;
    return valor;
}