#include <stdio.h>
#include "gameboard.h"

int isGameEnd(char gameboard[N][N], int turn)
{
	int i, j, yesflip1 = 0, yesflip2 = 0;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (gameboard[i][j] == ' ' && canflip(gameboard, i, j, turn) == 1) { yesflip1++; } //빈칸인 모든 좌표에서 뒤집을 수 있는지 확인
		}
	}

	if (yesflip1 == 0) {
		turn++; //다음 플레이어의 턴으로 넘김
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++) {
				if (gameboard[i][j] == ' ' && canflip(gameboard, i, j, turn) == 1) { yesflip2++; }
			}
		}

		if (yesflip2 == 0) { return 0; } //두 플레이어 모두 배치 불가능할 경우 0을 반환함
	}
	else { return 1; }

}