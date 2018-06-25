#include <stdio.h>

int N; 			// 이동정보의 개수를 저장하기 위한 변수
double M; 	// 배터리 용량을 저장하기 위한 변수
int S[10010]; 			// 이동속도를 저장하기 위한 배열
double T[10010];	// 이동시간을 저장하기 위한 배열
int L[10010]; 			// 이동거리를 저장하기 위한 배열
double P[10010];	// 배터리 소모량을 저장하기 위한 배열
double R;	// 배터리 잔량을 저장하기 위한 변수

int Cal_ABS(int a){
	if (a > 0) return a;
	return -a;
}

void Input_Data(void){
	int i;

	// 이동정보의 개수와 배터리 용량을 입력 받는 부분
	scanf("%d %lf", &N, &M);
	// N 개의 이동속도와 이동시간을 입력 받는 부분
	for (i = 1; i <= N; i++) {
		scanf("%d %lf", &S[i], &T[i]);
	}
}

int main(void){
	int i;

	Input_Data();
	
	// 이동속도와 이동시간을 이용하여 이동거리를 계산
	for (i = 1; i <= N; i++) {
		L[i] = (int)(S[i] * T[i] + 0.5);
	}

	// 이동거리와 속도팩터를 이용하여 배터리 소모량을 계산
	for (i = 1; i <= N; i++) {
		P[i] = L[i] * (Cal_ABS(S[i] - S[i - 1]) + 1) / 2.0;
	}

	// 배터리 소모량을 이용하여 배터리 잔량의 변화를 계산
	R = M;
	for (i = 1; i <= N; i++) {
		R -= P[i];
	}

	// 배터리 잔량의 최종값을 출력
	printf("%.1f\n", R);

	return 0;
}
