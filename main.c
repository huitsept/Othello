#include <stdio.h>
#include "gameboard.h"

void init_othello(char gameboard[N][N]);
int isGameEnd(char gameboard[N][N], int turn);
void printf_othello();
void check_result();
int canplace(char gameboard[N][N]);
int canflip(char gameboard[N][N], int x, int y, int turn);
void flip(char gameboard[N][N], int x, int y, int turn);
void winner(int wc, int wb);

void main()
{
	int turn = 0;
	int x = 3, y = 1; //ù �õ��� canflip�� 0�� ��ȯ���� �ʱ�����
	extern int cw, ce, cn, cs, cnw, cne, csw, cse;
	int wc = 0, wb = 0;
	init_othello(gameboard); //���� �ʱ�ȭ

	while (1) {
		printf_othello();
		printf("\n");
		check_result();

	   if (canplace(gameboard) == 0 || isGameEnd(gameboard, turn) == 0) { break; } //�� �÷��̾� ��� ��ġ�� �Ұ����ϸ� �ݺ����� �������� �Ǵ� �÷��̾� �Ѹ��� ��ġ�Ұ����� ��� �����÷��̾� ������ �Ѿ
		cn = 0, cs = 0, ce = 0, cw = 0, cne = 0, cnw = 0, cse = 0, csw = 0; //ī��Ʈ �ʱ�ȭ isGameEnd�� canflip�Լ��� ����Ǹ鼭 ī��Ʈ�� �ö󰡹Ƿ� �ʱ�ȭ

        //��ġ�� ��ǥ �Է� �ޱ�
		printf("\n");
		if (turn % 2 == 0) {
			printf("put a new white othello : ");
		} 
		else if (turn % 2 == 1) {printf("put a new black othello : ");}
		scanf("%d %d", &x, &y);
	
		//��ȿ�� ��ǥ�� ��� �����θ� ������ ������
		if (gameboard[x][y] == ' ' && canflip(gameboard, x, y, turn) == 1) {
			
			printf("  White has flipped %d othellos!\n", cw + ce + cn + cs + cnw + cne + csw + cse);
			flip(gameboard, x, y, turn);
			
			printf(" :: flip result ::\n");
			printf("  W:%d E:%d N:%d S:%d NW:%d NE:%d SW:%d SE:%d\n", cw, ce, cn, cs, cnw, cne, csw, cse);
			if (turn % 2 == 0) {
				printf("  White has flipped %d othellos!\n", cw + ce + cn + cs + cnw + cne + csw + cse);
			} else if (turn % 2 == 1){ printf("  Black has flipped %d othellos!\n", cw + ce + cn + cs + cnw + cne + csw + cse); }
				
		}
		//��ǥ�� ��ȿ���� ���� ��� ���Է�
		else { printf("wrong input\n"); continue; } 

		// �Է¹��� ��ǥ�� ������ ��ġ
		if (turn % 2 == 0) {gameboard[x][y] = 'O';}
		else if (turn % 2 == 1) {gameboard[x][y] = 'X';}
		
		turn++; //�� �ٲ�
		cn = 0, cs = 0, ce = 0, cw = 0, cne = 0, cnw = 0, cse = 0, csw = 0; //ī��Ʈ �ʱ�ȭ
		printf("\n");
	}

	winner(wc, wb); //�¸� �÷��̾� ���
}