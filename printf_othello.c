#include <stdio.h>
#include "gameboard.h"

void printf_othello()
{
	int i, j;

	printf("  ");
	for (i = 0; i < 6; i++) {
		printf("%d ", i);
	}

	for (i = 0; i < 6; i++) {
		printf("\n");
		printf(" -------------");
		printf("\n");
		printf("%d", i);
		for (j = 0; j < 6; j++) {
			printf("|%c", gameboard[i][j]);
		}
		printf("|");
	}
	printf("\n");
	printf(" -------------");
}