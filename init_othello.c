#include <stdio.h>
#include "gameboard.h"

void init_othello(char gameboard[N][N])
{
	int a = 1;
	int b = 4;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			gameboard[i][j] = ' ';
			if (i == 2 && j == 2) { 
				gameboard[i][j] = 'O'; 
			}

		    if (i == 2 && j == 3) { 
				gameboard[i][j] = 'X'; 
			}

			if (i == 3 && j == 2) { 
				gameboard[i][j] = 'X';
			}

		    if (i == 3 && j == 3) { 
				gameboard[i][j] = 'O'; 
			}
		}
	}
}