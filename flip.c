#include <stdio.h>
#include "gameboard.h"

void flip(char gameboard[N][N], int x, int y, int turn)
{
	int i, j;
	extern int cw, ce, cn, cs, cnw, cne, csw, cse;

	if (turn % 2 == 0) {
		if (cn > 0) {
			for (i = x, j = y; i > (x - cn); i--) {
				gameboard[i - 1][y] = 'O';
			}
		}
	    if (cs > 0) {
			for (i = x, j = y; i < (x + cs); i++) {
				gameboard[i + 1][y] = 'O';
			}
		}
		if (ce > 0) {
			for (i = x, j = y; j < (y + ce); j++) {
				gameboard[x][j + 1] = 'O';
			}
		}
		if (cw > 0) {
			for (i = x, j = y; j > (y - cw); j--) {
				gameboard[x][j - 1] = 'O';
			}
		}
		if (cne > 0) { 
			for (i = x, j = y; i > (x - cne); i--, j++) {
				gameboard[i - 1][j + 1] = 'O';
			}
		}
		if (cnw > 0) {
			for (i = x, j = y; i > (x - cnw); i--, j--) {
				gameboard[i - 1][j - 1] = 'O';
			}
		}
		if (cse > 0) {
			for (i = x, j = y; i < (x + cse); i++, j++) {
				gameboard[i + 1][j + 1] = 'O';
			}
		}
		if (csw > 0) {
			for (i = x, j = y; i < (x + csw); i++, j--) {
				gameboard[i + 1][j - 1] = 'O';
			}
		}
	}
	else if (turn % 2 == 1) {
		if (cn > 0) {
			for (i = x, j = y; i > (x - cn); i--) {
				gameboard[i - 1][y] = 'X';
			}
		}
		if (cs > 0) {
			for (i = x, j = y; i < (x + cs); i++) {
				gameboard[i + 1][y] = 'X';
			}
		}
		if (ce > 0) {
			for (i = x, j = y; j < (y + ce); j++) {
				gameboard[x][j + 1] = 'X';
			}
		}
		if (cw > 0) {
			for (i = x, j = y; j > (y - cw); j--) {
				gameboard[x][j - 1] = 'X';
			}
		}
		if (cne > 0) {
			for (i = x, j = y; i > (x - cne); i--, j++) {
				gameboard[i - 1][j + 1] = 'X';
			}
		}
		if (cnw > 0) {
			for (i = x, j = y; i > (x - cnw); i--, j--) {
				gameboard[i - 1][j - 1] = 'X';
			}
		}
	    if (cse > 0) {
			for (i = x, j = y; i < (x + cse); i++, j++) {
				gameboard[i + 1][j + 1] = 'X';
			}
		}
		if (csw > 0) {
			for (i = x, j = y; i < (x + csw); i++, j--) {
				gameboard[i + 1][j - 1] = 'X';
			}
		}
	}
}