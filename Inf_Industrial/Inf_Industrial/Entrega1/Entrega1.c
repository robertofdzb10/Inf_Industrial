int leeValor(void);
#include <stdio.h>

int main() {

	int array1[100];
	int array2[100];
	int contador = 0;
	int contador1 = 0;
	int contador2 = 0;
	int valor;
	int* selecciona_array = &array1;

	while (contador < 100) {
		valor = leeValor();

		if (valor == -1) {
			selecciona_array = array1;
		}
		else if (valor == -2) {
			selecciona_array = array2;
		}
		else if (valor >= 0) {
			if (selecciona_array == &array1) {
				*(array1 + contador1) = valor; //Un array se almacena en memoria de forma continua
				contador1++;

			}
			else { //Sino apunta al primer array apunta al segundo
				*(array2 + contador2) = valor;
				contador2++;
			}
		}

		contador++;
		return 0;
	}

	printf("Los elementos del array 1 son (%d):\n", contador1);
	for (int i = 0; i < contador1; i++) {
		printf("%d ", *(array1 + i));
	}

	printf("\n\n");

	printf("Los elementos del array 2 son (%d):\n", contador2);
	for (int i = 0; i < contador2; i++) {
		printf("%d ", *(array1 + i));
	}
}