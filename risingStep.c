#include <stdio.h>

int N;				//	계단의 개수
int P[310];		//	P[i]: i 계단을 밟았을 때 얻는 점수
int sol;				//	정답

int main(void){
	int i, sum, step;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &P[i]);

	//	코드를 작성하세요
	step = 1;
	sum = 0;
	sum = P[0];
	for (i = 1; i < N; i++) {
		//if (i + 2) continue;
		if (step >= 3) {
			step = 1;
			continue;
		}
		sum += P[i];
		printf ("P[%d] = %d, sum = %d \n", i, P[i], sum);
		step++;
	}

	sol = sum;
	printf("%d", sol);	//	정답 출력
	return 0;
}
