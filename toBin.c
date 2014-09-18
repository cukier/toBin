/*
 * toBin.c
 *
 *  Created on: 27/07/2013
 *      Author: cuki
 */
#include<stdio.h>
#include<string.h>

unsigned char decToBcd(unsigned char val) {
	return ((val / 10 * 16) + (val % 10));
}

unsigned char bcdToDec(unsigned char val) {
	return ((val / 16 * 10) + (val % 16));
}

char *toBin(unsigned char val, char *s) {
	unsigned char cont = 0, aux = 0;

	for (aux = 128, cont = 0; cont < 8; aux >>= 1, cont++) {
		s[cont] = (val & aux) ? '1' : '0';
	}
	s[cont] = '\0';
	return s;
}

int main(void) {

	unsigned char valor = 12, aux;
	char str[9];

//	toBin(valor, str);

	printf("%d : %s\n", valor, toBin(valor, str));

	aux = decToBcd(valor);
	toBin(aux, str);

	printf("%d : %s", aux, str);

	return 0;

}
