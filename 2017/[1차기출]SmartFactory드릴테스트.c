#include <stdio.h>
#include "drill.h"
/*
 * drill.h에는 아래 함수의 정의가 있다.
	int drill(int x1, int r1, int x2, int r2);
*/

/* [작성 내용] */
/* 1. 테스트 케이스를 아래 배열에 추가하시오 개수는 상관 없음. 배열의 이름은 수정 불가함 */
/* 2. 테스트 케이스 배열 구조 : {x1, r1, x2, r2, 기대 return 값} */ 
int tarr[][5] = { 
	{28,2,34,4,0},
	//====================
	{10,6,30,4,0},
	{10,2,30,6,0},

	{3,2,30,4,0},
	{10,2,47,4,0},

	{10,0,30,4,0},
	{10,2,30,0,0},
	
	{30,2,20,4,0},
};

/* main 함수는 작성한 테스트 케이스 검증용임 */
/* 필요에 따라서 마음대로 변경하어도 무방함 */ 
/* main 함수는 채점과 무관함 */

int main()
{
	int i;

	for(i = 0; i <(sizeof(tarr)/sizeof(tarr[0])); i++)
	{
		printf("[%d] ", i);
		printf("Expected = %d, ", tarr[i][4]);
		printf("Return = %d\n", drill(tarr[i][0], tarr[i][1], tarr[i][2], tarr[i][3]));
	}

	return 0;
}
