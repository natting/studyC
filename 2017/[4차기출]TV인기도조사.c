#include <stdio.h>

int N, M;
int TV[100000 + 10];    // 판매된 TV 모델
int sold[100000 + 10];  // 판매수량
int score[100000 + 10]; // 인기도

int same[100000 + 10];  // 연속판매최대수량

int main(void)
{
	int i, max;
	int cnt;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		scanf("%d", &TV[i]);
	}

	// 모델 별 판매수량을 카운트
	for (i = 0; i < N; i++) {
		sold[TV[i]]++;
	}

	// 새로운 방법에 의한 인기도 계산
	cnt = 1;
	same[TV[0]] = 1;
	for (i = 1; i < N; i++) {
		if (TV[i] == TV[i - 1]) cnt++;
		else cnt = 1;
		if (same[TV[i]] < cnt) same[TV[i]] = cnt;
	}

	for (i = 1; i <= M; i++) {
		score[i] = sold[i] * same[i];
	}

	// 인기도가 가장 높은 모델번호 찾기
	max = 1;
	for (i = 2; i <= M; i++) {
		if(score[i] > score[max]) max = i;
	}

	// 정답 출력
	printf("%d", max);

	return 0;
}
