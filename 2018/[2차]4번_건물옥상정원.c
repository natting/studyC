#include <stdio.h>

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)
int X[100000 + 10];// T분후 위치
int Z[100000 + 10];// T분후 추월못한 실제 위치

void Input_Data(void){
	int i;
	scanf("%d %d", &N, &T);
	for (i = 0; i < N; i++){
		scanf("%d %d", &P[i], &S[i]);
	}
}

int main(void){
	int ans = -1;
	int cntG = 0;
	int i;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	for (i = 0; i < N; i++) {
		X[i] = P[i] + S[i]*T;
	}
	
	for (i = 0; i < N; i++) {
		if (X[i] >= X[i+1] && i < N-1) {
			Z[i] = X[i+1];
		} else {
			Z[i] = X[i];
			cntG++;
		}
	}
	
	ans = cntG;
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
