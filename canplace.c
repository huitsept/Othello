#include <stdio.h>
#include "gameboard.h"

int canplace(char gameboard[N][N])
{
	int i, j, space = 0, white = 0, black = 0;

	for (i = 0; i < 6; i ++) {
		for (j = 0; j < 6; j++) {
			if (gameboard[i][j] == ' ') { space++; }
			else if (gameboard[i][j] == 'X') { black++; }
			else if (gameboard[i][j] == 'O') { white++; }
		}
	}

	if (space == 0) { return 0; } // º¸µåÆÇÀÌ °¡µæ Âü
	else if (white == 0 || black == 0) { return 0; } // »ö±òÀÌ ÇÏ³ª·Î ÅëÀÏµÊ
	else { return 1; }
}