#include <stdio.h>
#include "gameboard.h"

void winner(int wc, int wb) 
{
	if (wc = wb) { printf("무승부입니다.\n"); } //돌의 수로 판 

	printf("%s\n", (wc > wb) ? "승자는 White Player입니다." : "승자는 Black Player입니다.");

	
}
