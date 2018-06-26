#include <stdio.h>

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)
long long A[100000 + 10];//예정위치 및 실제위치
void Input_Data(void){
	int i;
	scanf("%d %d", &N, &T);
	for (i = 0; i < N; i++){
		scanf("%d %d", &P[i], &S[i]);
	}
}

int main(void){
	int ans = -1;
	int i = 0;
	Input_Data();		//	입력 함수
	
	ans = 1;
	A[N-1] = P[N-1] + S[N-1]*T;	//예상위치
	//	코드를 작성하세요

	for(i = N-2; i>= 0; i--){
		A[i] = P[i] + S[i]*T;	//예상위치
//		printf("예상 %d ", A[i]);
		if(A[i+1]<A[i]){
			A[i] = A[i+1];//실제위치
//			printf("실제 %d ", A[i]);
		}
		else if(A[i+1]>A[i]){
			ans++;
		}
		else;
//		printf("그룹 %d \n", ans);
	}

	printf("%d\n", ans);		//	정답 출력
	return 0;
}
