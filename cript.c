/*
** EPITECH PROJECT, 2017
** 103cipher
** File description:
** cript fonction
*/

#include <stdio.h>
#include <stdlib.h>
#include "103cipher.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void malloc_key(int len, matrice_t *matrice, char **av)
{
	int count = 0;
	int i = 0;
	float result;

	if (len == 1) {
		printf("Key matrix: :\n%.0d", av[2][0]);
		printf("\n\nEncrypted message :\n");
		while (av[1][i] != '\0') {
			result = av[1][i] * av[2][0];
			if (i == 0)
				printf("%.0f", result);
			else
				printf(" %.0f", result);
			i++;			
		}
		printf("\n");
	}
	if (len > 1 && len <= 4) {
		matrice->K = malloc(sizeof(float *) * 3);
		for (count = 0; count < 2; count++)
			matrice->K[count] = malloc(sizeof(float *) * 3);
		matrice2(matrice, av);
	}
	if (len > 4 && len <= 9) {
		matrice->K = malloc(sizeof(float *) * 4);
		for (count = 0; count < 3; count ++)
			matrice->K[count] = malloc(sizeof(float *) * 4);
		matrice3(matrice, av);
	}
	if (len > 9 && len <= 16) {
		matrice->K = malloc(sizeof(float *) * 5);
		for (count = 0; count < 4; count++)
			matrice->K[count] = malloc(sizeof(float *) * 5);
		matrice4(matrice, av);
	}
}

int cript(char **av)
{
	int len;
	matrice_t *matrice = malloc(sizeof(matrice_t));

	len = my_strlen(av[2]);
	if (1 <=len && len <= 16) {
		malloc_key(len, matrice, av);
	}
	free(matrice->K);
	free(matrice);
	return (0);
}
