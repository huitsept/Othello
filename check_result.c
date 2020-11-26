#include <stdio.h>
#include "gameboard.h"

void check_result()
{
    int wc = 0,  wb = 0; //wc = 흰돌 수, wb=검은돌  

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (gameboard[i][j] == 'O') { wc++; }
			else if (gameboard[i][j] == 'X') { wb++; }
		}
	}
	
	printf("\n");
	printf(" STATUS - WHITE : %d, BLACK : %d\n", wc, wb);
	printf("\n");
}
