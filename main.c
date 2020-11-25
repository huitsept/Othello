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
	int x = 3, y = 1; //첫 시도때 canflip이 0을 반환하지 않기위해
	extern int cw, ce, cn, cs, cnw, cne, csw, cse;
	int wc = 0, wb = 0;
	init_othello(gameboard); //게임 초기화

	while (1) {
		printf_othello();
		printf("\n");
		check_result();

	   if (canplace(gameboard) == 0 || isGameEnd(gameboard, turn) == 0) { break; } //두 플레이어 모두 배치가 불가능하면 반복문을 빠져나감 또는 플레이어 한명이 배치불가능한 경우 다음플레이어 턴으로 넘어감
		cn = 0, cs = 0, ce = 0, cw = 0, cne = 0, cnw = 0, cse = 0, csw = 0; //카운트 초기화 isGameEnd에 canflip함수가 실행되면서 카운트가 올라가므로 초기화

        //배치할 좌표 입력 받기
		printf("\n");
		if (turn % 2 == 0) {
			printf("put a new white othello : ");
		} 
		else if (turn % 2 == 1) {printf("put a new black othello : ");}
		scanf("%d %d", &x, &y);
	
		//유효한 좌표일 경우 오셀로를 뒤집고 결과출력
		if (gameboard[x][y] == ' ' && canflip(gameboard, x, y, turn) == 1) {
			
			printf("  White has flipped %d othellos!\n", cw + ce + cn + cs + cnw + cne + csw + cse);
			flip(gameboard, x, y, turn);
			
			printf(" :: flip result ::\n");
			printf("  W:%d E:%d N:%d S:%d NW:%d NE:%d SW:%d SE:%d\n", cw, ce, cn, cs, cnw, cne, csw, cse);
			if (turn % 2 == 0) {
				printf("  White has flipped %d othellos!\n", cw + ce + cn + cs + cnw + cne + csw + cse);
			} else if (turn % 2 == 1){ printf("  Black has flipped %d othellos!\n", cw + ce + cn + cs + cnw + cne + csw + cse); }
				
		}
		//좌표가 유효하지 않을 경우 재입력
		else { printf("wrong input\n"); continue; } 

		// 입력받은 좌표에 오셀로 배치
		if (turn % 2 == 0) {gameboard[x][y] = 'O';}
		else if (turn % 2 == 1) {gameboard[x][y] = 'X';}
		
		turn++; //턴 바꿈
		cn = 0, cs = 0, ce = 0, cw = 0, cne = 0, cnw = 0, cse = 0, csw = 0; //카운트 초기화
		printf("\n");
	}

	winner(wc, wb); //승리 플레이어 출력
}