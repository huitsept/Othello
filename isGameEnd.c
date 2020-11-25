#include <stdio.h>
#include "gameboard.h"

int isGameEnd(char gameboard[N][N], int turn)
{
	int i, j, yesflip1 = 0, yesflip2 = 0;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (gameboard[i][j] == ' ' && canflip(gameboard, i, j, turn) == 1) { yesflip1++; } //��ĭ�� ��� ��ǥ���� ������ �� �ִ��� Ȯ��
		}
	}

	if (yesflip1 == 0) {
		turn++; //���� �÷��̾��� ������ �ѱ�
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 6; j++) {
				if (gameboard[i][j] == ' ' && canflip(gameboard, i, j, turn) == 1) { yesflip2++; }
			}
		}

		if (yesflip2 == 0) { return 0; } //�� �÷��̾� ��� ��ġ �Ұ����� ��� 0�� ��ȯ��
	}
	else { return 1; }

}