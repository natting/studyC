
/* [작성 내용] */
/* 1. 테스트 케이스를 아래 배열에 추가하시오 개수는 상관 없음. 배열의 이름은 수정 불가함 */
/* 2. 테스트 케이스 배열 구조 : { 부하량 갯수 N, 부하량1, ..., 부하량N } */
/*  예를 들어, { 4, 1600, 2010, 1900, 1501 }는 부하량이 1600, 2010, 1900, 1501 순으로 감지됨을 의미한다. */
int testParameters[][10] = {
	{ 4, 1600, 2010, 1900, 1501, },
	// TODO: 항목 1-1, 1-2, 1-3. 테스트 입력을 추가하시오.
	{ 7, 500, 2100, 1600, 0, 1900, 1801, 2000 },// 부하 가중치의 합산이 9
	{ 7, 500, 2100, 1600, 0, 1900, 1600, 2100 },// 부하 가중치의 합산이 10
	{ 7, 500, 2100, 1600, 0, 1900, 1900, 2100 },// 부하 가중치의 합산이 11
};

#include "detector.h"
/*
* detector.h에는 아래 함수의 정의가 있다.

int detectOverload()
{
	static int count = 0;
	int value = getCurrentLoad();

	if (value > 2000)
	{
		count += 5;
	}
	else if (value > 1800)
	{
		count += 3;
	}
	else if (value > 1500)
	{
		count += 2;
	}
	else
	{
		count = 0;
	}

	return (count > 10) ? 1 : 0;
}
*/

// TODO :
// current 값을 fake로 전달하기 위해
static int fakeCurrent;
// current 값으로 fakeCurret 세팅
static void setFakeCurrentLoad(int current)
{
	fakeCurrent = current;
}

int getCurrentLoad()
{
	// TODO: 원하는 부하량을 전달할 수 있도록 fake/stub을 구현하시오.
	//return 0; // FIXME: 필요한 코드로 대체하시오.
	return fakeCurrent;
}


void test_2_1()
{
	// TODO: 항목 2-1. 
	// 전류 부하가 1900, 1600, 0, 2100 순으로 감지되는 경우를 재현하는 코드를 작성하시오.
	setFakeCurrentLoad(1900);
	detectOverload();

	setFakeCurrentLoad(1600);
	detectOverload();

	setFakeCurrentLoad(0);
	detectOverload();

	setFakeCurrentLoad(2100);
	detectOverload();
}

void test_2_2()
{
	// TODO: 항목 2-2. 
	// 전류 부하가 0, 1900, 1600, 2100, 1600 순으로 감지되는 경우를 재현하는 코드를 작성하시오.
	setFakeCurrentLoad(0);
	detectOverload();

	setFakeCurrentLoad(1900);
	detectOverload();

	setFakeCurrentLoad(1600);
	detectOverload();

	setFakeCurrentLoad(2100);
	detectOverload();

	setFakeCurrentLoad(1600);
	detectOverload();
}

/* main 함수는 작성한 테스트 케이스 검증용임 */
/* 필요에 따라서 마음대로 변경하어도 무방함 */
/* main 함수는 채점과 무관함 */
int main()
{
	printTestResults();  // testParameter에 기록한 테스트 입력으로 실행한 결과를 출력해준다. (수험자 확인용)

	test_2_1();

	test_2_2();

	return 0;
}
