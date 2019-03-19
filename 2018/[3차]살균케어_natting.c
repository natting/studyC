#include <stdio.h>

int y[110];		//	살균대상의 y 좌표 배열
int x[110];		//	살균대상의 x 좌표 배열
int N;				//	필터 한 변의 크기
int L;				//	LED의 범위(길이) 
int M;				//	살균대상의 개수
int sol;			//	정답

// 시작좌표에서 사각형안의 좌표갯수 계산
int calc(int sy, int sx, int w, int h)
{
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (y[i] >= sy && y[i] <= sy+w && x[i] >= sx && x[i] <= sx+h)
			cnt ++;
	}
	return cnt;
}
int main(void){
	int i;

	//	입력 : 전체길이N, 둘레합L, 세균갯수M
	scanf("%d %d %d", &N, &L, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d", &y[i], &x[i]);
	}
	
	int h, w;
	int sx, sy;//start point..
	int count = 0;
	int max = 0;
	// 시작 좌표부터 사각형 그려서 찾는 방법
	// BUT 시작점이 좌표가 아닌 부분은??? 
	for (i = 0; i < M; i++) {
		sy = y[i]; sx = x[i];
		for (w = 1; w < L/2; w++) {
			h = L/2 - w;
			count = calc(sy, sx, w, h);
			if (count > max) max = count;
		}
	}
	sol = max;
	//	정답출력
	printf("%d", sol);
	return 0;
}
