
/* [작성 내용] */
/* 1. 테스트 케이스를 아래 배열에 추가하시오 개수는 8개 고정. 배열의 이름은 수정 불가함 */
/* 2. 테스트 케이스 배열 구조 : { 미세먼지측정값1, ..., 미세먼지측정값8 } */
/* 예를 들어, { 101, 101, 100, 50, 30, 51, 75, 100 }는 */
/* 미세먼지측정값이 101, 101, 100, 50, 30, 51, 75, 100 순으로 감지됨을 의미한다. */
int testInput_example[8] = { 101, 101, 100, 50, 30, 51, 75, 100 };

int testInput_1_1[8] = { 51, 102, 29, 52, 102, 33, 55, 104}; // TODO: 항목 1-1 터보모드x, total == 27
int testInput_1_2[8] = { 100, 102, 103, 101, 35, 77, 99, 49 }; // TODO: 항목 1-2 터보 1 total = 32
int testInput_1_3[8] = { 102, 103, 104, 52, 31, 49, 51, 55 }; // TODO: 항목 1-3 터보 1+, total=36.

#include "./lib/device.h"
/* device.h에는 대략적으로 아래와 같이 구현된 함수의 정의가 있다.
 * 구현 참고용이므로 본 주석을 풀어서 아래 코드를 사용해서는 안된다.  (device.h에 포함된 내용임)
 * 아래 주석을 해제하여 사용하는 경우 정상적으로 동작하지 않는다.
/*
 *  현재 센서에서 감지한 미세먼지 측정값을 반환하는 인터페이스
 *
int getCurrentPM(); 

/*
 * 바람 세기와 누적 부하량 계산하여 결정한 바람 세기를 반환 (테스트 대상)
 *
int determineWindStrength()
{
	int pm = getCurrentPM(); //미세먼지측정값은 getCurrentPM()함수를 호출해서 얻는다.
	
	int polutionLevel = mapToPolutionLevel(pm); // 미세먼지량에_따른_오염도
	int result = mapToWindStrength(polutionLevel); // 오염도에_따른_바람세기

	if (isTurboModeBeginCondition(polutionLevel))
		turboMode = TRUE;
	else if (isTurboModeEndCondition(polutionLevel))
		turboMode = FALSE;
		
	if (turboMode)
		result = TURBO_MODE;
	
	totalLoad += getLoadOf(result); // 바람 세기에 따른 부하량을 계산하여 누적
	
	return result;
}
*/

int data1[7] = { 110, 108, 80, 	45, 60, 90, 91 };

int getCurrentPM()
{
	// TODO: 원하는 미세먼지측정값을 전달할 수 있도록 fake/stub을 구현하시오.
	//return 0; // FIXME: 필요한 코드로 대체하시오.
	int result;
	
	//result = data1[index];
	
	return result;
}

void test_2_1()
{
	// TODO: 항목 2-1. 
	// 미세 먼지 단계가 (매우 나쁨, 매우 나쁨, 나쁨, 보통, 나쁨, 나쁨, 나쁨) 순으로 7개가 감지되는 경우를 재현하는 코드를 작성하라.
	//int data1[7] = { 110, 			108, 			80, 	45, 	60, 90, 91 };
	determineWindStrength();
}

void test_2_2()
{
	// TODO: 항목 2-2. 
	// 세 먼지 단계가 (매우 나쁨, 나쁨, 나쁨, 매우 나쁨, 나쁨, 좋음, 나쁨, 매우 나쁨, 나쁨, 매우 나쁨, 나쁨) 순으로 11개가 감지되는 경우를 재현하는 코드를 작성하라.
}

/* main 함수는 작성한 테스트 케이스 검증용임 */
/* 필요에 따라서 마음대로 변경하어도 무방함 */
/* main 함수는 채점과 무관함 */

int main()
{
	printTestResults();  // testInput에 기록한 테스트 입력으로 실행한 결과를 출력해준다. (수험자 확인용)

	test_2_1();

	test_2_2();

	return 0;
}
