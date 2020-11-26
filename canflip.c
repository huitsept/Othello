#include <stdio.h>
#include "gameboard.h"
//뒤집을 수 있는 상황인지  방향별로 판 

int i, j, cw, ce, cn, cs, cnw, cne, csw, cse;
int west, east, north, south, northwest, southwest, northeast, southeast;

void left(char gameboard[N][N], int x, int y, int turn)
{
	if (y == 0 || y == 1) { west = 0;}
	else { if (turn % 2 == 0) {
				 if (gameboard[x][y - 1] == 'X') {
					 for (i = y - 2; i >= 0; i--) {
						 cw++;
						 if (gameboard[x][i] == ' ') { cw = 0;  break; }
						 if (gameboard[x][i] == 'O') { west = 1; break; }
					 }
				 } else { west = 0; }
		 }
			else if (turn % 2 == 1) {
					if (gameboard[x][y - 1] == 'O') {
						for (i = y - 2; i >= 0; i--) {
							cw++;
							if (gameboard[x][i] == ' ') { cw = 0; break; }
							if (gameboard[x][i] == 'X') { west = 1; break;}
						}
					} else { west = 0; }
			}
	}
	if (west != 1) { cw = 0; }
}

void right(char gameboard[N][N], int x, int y, int turn)
{
	if (y == (N - 2) || y == (N- 1)) { east = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x][y + 1] == 'X') {
					for (i = y + 2; i < 6; i++) {
						ce++;
						if (gameboard[x][i] == ' ') { ce = 0; break; }
						if (gameboard[x][i] == 'O') { east = 1; break;}
					}
				} else { east = 0; }
		}
		else if (turn % 2 == 1) {
				if (gameboard[x][y + 1] == 'O') {
					for (i = y + 2; i < 6; i++) {
						ce++;
						if (gameboard[x][i] == ' ') { ce = 0; break; }
						if (gameboard[x][i] == 'X') { east = 1; break;}
					}
				} else { east = 0; }
		}
	}
	if (east != 1) { ce = 0; }
}
	
void up(char gameboard[N][N], int x, int y, int turn)
{
	if (x == 0 || x == 1) { north = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x - 1][y] == 'X') {
					for (i = x - 2; i >= 0; i--) {
						cn++;
						if (gameboard[i][y] == ' ') { cn = 0; break; }
						if (gameboard[i][y] == 'O') { north = 1; break;}
					}
				} else { north = 0; }
		}
		else if (turn % 2 == 1) {
				if (gameboard[x - 1][y] == 'O') {
					for (i = x - 2; i >= 0; i--) {
						cn++;
						if (gameboard[i][y] == ' ') { cn = 0; break; }
						if (gameboard[i][y] == 'X') { north = 1; break;}
					}
				} else { north = 0; }
		}
	}
	if (north != 1) { cn = 0; }
}

void down(char gameboard[N][N], int x, int y, int turn)
{
	if (x == (N - 2) || x == (N - 1)) { south = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x + 1][y] == 'X') {
					for (i = x + 2; i < 6; i++) {
						cs++;
						if (gameboard[i][y] == ' ') { cs = 0; break; }
						if (gameboard[i][y] == 'O') { south = 1; break; }
					}
				} else { south = 0; }
		}
		else if (turn % 2 == 1) {
				if (gameboard[x + 1][y] == 'O') {
					for (i = x + 2; i < 6; i++) {
						cs++;
						if (gameboard[i][y] == ' ') { cs = 0; break; }
						if (gameboard[i][y] == 'X') { south = 1; break;}
					}
				} else { south = 0; }
		}
	}
	if (south != 1) { cs = 0; }
}

void upL(char gameboard[N][N], int x, int y, int turn)
{
	if (x == 0 || x == 1 || y == 0 || y == 1) { northwest = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x- 1][y - 1] == 'X') {
					for (i = x - 2, j = y - 2; i >= 0 && j >= 0; i--, j--) {
						cnw++;
						if (gameboard[i][j] == ' ') { cnw = 0; break; }
						if (gameboard[i][j] == 'O') { northwest = 1; break;}
					}
				} else { northwest = 0; }
		}
		else if (turn % 2 == 1) {
					if (gameboard[x - 1][y - 1] == 'O') {
						for (i = x - 2, j = y - 2; i >= 0 && j >= 0; i--, j--) {
							cnw++;
							if (gameboard[i][j] == ' ') { cnw = 0; break; }
							if (gameboard[i][j] == 'X') { northwest = 1; break;}
						}
					} else { northwest = 0; }
			}
	}
	if (northwest != 1) { cnw = 0; }
}

void downL(char gameboard[N][N], int x, int y, int turn)
{
	if (x == (N - 2) || x == (N - 1) || y == 0 || y == 1) { southwest = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x + 1][y - 1] == 'X') {
					for (i = x + 2, j = y - 2; i < 6 && j >= 0; i++, j--) {
						csw++;
						if (gameboard[i][j] == ' ') { csw = 0; break; }
						if (gameboard[i][j] == 'O') { southwest = 1; break;}
					}
				} else { southwest = 0; }
		}
		else if (turn % 2 == 1) {
					if (gameboard[x + 1][y - 1] == 'O') {
						for (i = x + 2, j = y - 2; i < 6 && j >= 0; i++, j--) {
							csw++;
							if (gameboard[i][j] == ' ') { csw = 0; break; }
							if (gameboard[i][j] == 'X') { southwest = 1; break;}
						}
					} else { southwest = 0; }
			}
	}
	if (southwest != 1) { csw = 0; }
}

void upR(char gameboard[N][N], int x, int y, int turn)
{
	if (x == 0 || x == 1 || y == (N - 2) || y == (N - 1)) { northeast = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x - 1][y + 1] == 'X') {
					for (i = x - 2, j = y + 2; i >= 0 && j < 6; i--, j++) {
						cne++;
						if (gameboard[i][j] == ' ') { cne = 0; break; }
						if (gameboard[i][j] == 'O') { northeast = 1; break;}
					}					
				} else { northeast = 0; }
		}
		else if (turn % 2 == 1) {
					if (gameboard[x - 1][y + 1] == 'O') {
						for (i = x - 2, j = y + 2; i >= 0 && j < 6; i--, j++) {
							cne++;
							if (gameboard[i][j] == ' ') { cne = 0; break; }
							if (gameboard[i][j] == 'X') { northeast = 1; break;}
						}
					} else { northeast = 0; }
			}
	}
	if (northeast != 1) { cne = 0; }
}

void downR(char gameboard[N][N], int x, int y, int turn)
{
	if (x == (N - 2) || x == (N - 1) || y == (N - 2) || y == (N - 1)) { southeast = 0; }
	else {
		if (turn % 2 == 0) {
				if (gameboard[x + 1][y + 1] == 'X') {
					for (i = x + 2, j = y + 2; i < 6 && j < 6; i++, j++) {
						cse++;
						if (gameboard[i][j] == ' ') { cse = 0; break; }
						if (gameboard[i][j] == 'O') { southeast = 1; break;}
					}
				} else { southeast = 0; }
		}
		else if (turn % 2 == 1) {
					if (gameboard[x + 1][y + 1] == 'O') {
						for (i = x + 2, j = y + 2; i < 6 && j < 6; i++, j++) {
							cse++;
							if (gameboard[i][j] == ' ') { cse = 0; break; }
							if (gameboard[i][j] == 'X') { southeast = 1; break;}
						}
					} else { southeast = 0; }
			}
	}
	if (southeast != 1) { cse = 0; }
}

int canflip(char gameboard[N][N], int x, int y, int turn)
{
	left(gameboard, x, y, turn);
	right(gameboard, x, y, turn);
	up(gameboard, x, y, turn);
	down(gameboard, x, y, turn);
	upL(gameboard, x, y, turn);
	downL(gameboard, x, y, turn);
	upR(gameboard, x, y, turn);
	downR(gameboard, x, y, turn);

	if ((west + east + north + south + northwest + southwest + northeast + southeast) > 0)
	{
		return 1;
	}
	else {
		return 0;
	}
}
