#include <stdio.h>

int N;//LED 수
int S[100000 + 10];//LED 상태
int pat[100000 + 10];//pattern 구간

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &S[i]);
	}
}

int main(void){
	int ans = -1;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	int cnt = 0;
	int seq = 1;
	for (int i = 0; i < N; i++) {
		if (S[i] == S[i+1]) {
			pat[cnt++] = seq;
			seq = 1;
		} else {
			seq++;
		}
	}
	
#if 1
	for (int j = 0; j < cnt; j++) {
		printf ("%d ", pat[j]);
	}
	printf ("\n");
	printf ("cnt = %d \n", cnt);
#endif
	
	int max = 0;
	int sum = 0;
	max = pat[0] + pat[1] + pat[2];
	if (cnt < 3)
		max = pat[0] + pat[1] + pat[2];
	else {
		for (int i = 3; i < cnt; i++) {
			sum = pat[i-2] + pat[i-1] + pat[i];
			if (sum > max) max = sum;
		}
	}
	
	printf("%d\n", max);		//	정답 출력
	return 0;
}
