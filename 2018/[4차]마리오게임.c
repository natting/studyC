// 예제에서 pattern 을 찾아서 구현함.
// max가 되는 patten 은 이전값보다 커지는 부분만 골라 먹기..
#include <stdio.h>

int N;//버섯 수
int P[150000 + 10];//버섯 값

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &P[i]);
	}
}

int main(void){
	int ans = -1;
	int sum = 0;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	sum = P[0];
	for (int i =1; i < N; i++) {
		if (P[i] > P[i-1]) {
			//printf ("- P[%d] : %d, + P[%d] : %d \n", i-1, P[i-1], i, P[i]);
			sum = sum - P[i-1] + P[i];
		}
	}
	ans = sum;
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
