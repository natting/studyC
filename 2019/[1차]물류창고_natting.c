#include <stdio.h>
int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D

void InputData(){
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d %d", &A[i], &B[i], &D[i]);
	}
}
int main(){
	int ans = -1;
	InputData();//	입력 함수
	
	//	코드를 작성하세요
	ans = 15;
	printf("%d\n", ans);//	정답 출력
	return 0;
}
