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

	// 모델 별 판매수량을 카운트 방법임 : 알아두자....ToDo
	// sold[1]++, sold[3]++, .... 1/2/3 모델들에 대한 판매댓수를 카운팅함. 
	for (i = 0; i < N; i++) {
		sold[TV[i]]++;
	}

#if 0
	// 기존 방법에 의한 인기도 계산 (인기도 = 판매수량)
	for (i = 1; i <= M; i++) {
		score[i] = sold[i];
	}	
#else 
	// 새로운 방법에 의한 인기도 계산 : 연속판매댓수를 얻기위함. same[]에 저장
	cnt = 1;
	same[TV[0]] = 1;
	for (i = 1; i < N; i++) {
		if (TV[i] == TV[i - 1]) 
			cnt++;	// 연속판매됨
		else 
			cnt = 1; // 연속판매 중지: cnt reset

		if (same[TV[i]] < cnt)
			same[TV[i]] = cnt;
	}
	// 연속판매를 곱해서 점수 새로 계산
	for (i = 1; i <= M; i++) {
		score[i] = sold[i] * same[i];
	}
#endif
	// 인기도가 가장 높은 모델번호 찾기
	max = 1;
	for (i = 2; i <= M; i++) {
		if(score[i] > score[max]) max = i;
	}

	// 정답 출력
	printf("%d", max);

	return 0;
}
