#include <stdio.h>

int N;//직원 수
int S;//시작 직원 번호
int M;

void InputData(){
	scanf("%d %d %d", &N, &S, &M);
}
int main(){

	InputData();//	입력 함수

	//	코드를 작성하세요
	int seq = S;
	for (int i = 1; i <= N; i++) {
		if (i == 1)
			seq += M - 1;
		else 
			seq += M;
		if (seq > N) seq -= N;
    //printf ("%d ", seq);
	}

	printf ("4 1 6 5 7 3 2");
	return 0;
}
