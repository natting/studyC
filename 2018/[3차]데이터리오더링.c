#include <stdio.h>

unsigned int Make_Data(unsigned int rcv);

// 작성할 함수
unsigned int Make_Data(unsigned int rcv)
{
	int sol = 0;
	int val = 0;
	// 환경감지2
	val = (rcv >> 26) & 0x3f;
	sol |= val <<18;
	//printf ("val = %d | sol = %d \n", val, sol);
	//안전감지2	
	val = (rcv >> 23) & 0x7;
	sol |= val <<13;
	//printf ("val = %d | sol = %d \n", val, sol);
	// 운전상태
	val = (rcv >> 19) & 0xf;
	sol |= val;
	//printf ("val = %d | sol = %d \n", val, sol);
	// 내부오류
	val = (rcv >> 15) & 0xf;
	sol |= val <<24;
	//printf ("val = %d | sol = %d \n", val, sol);
	// 외부오류
	val = (rcv >> 11) & 0xf;
	sol |= val <<4;
	//printf ("val = %d | sol = %d \n", val, sol);
	//환경1
	val = (rcv >> 9) & 0x3;
	sol |= val <<16;
	//printf ("val = %d | sol = %d \n", val, sol);
	//안전감지1
	val = (rcv >> 4) & 0x1f;
	sol |= val <<8;
	//printf ("val = %d | sol = %d \n", val, sol);
	//장치번호
	val = rcv & 0xf;
	sol |= val <<28;
	//printf ("val = %d | sol = %d \n", val, sol);
	return sol;
}

int main(void)
{
	unsigned int rcv,sol;
	
	// 입력 받는 부분
	scanf("%X",&rcv);
	
	sol = Make_Data(rcv);

	printf("%X\n",sol);
}
