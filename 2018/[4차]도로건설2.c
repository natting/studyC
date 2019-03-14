#include <stdio.h>

int N;//지도 크기
char map[110][110];//지도 정보
char visit[110][110];//visit 배열
// 상하좌우
int dir_x[] = {0, 0, -1, 1};
int dir_y[] = {-1, 1, 0, 0};

typedef struct point {
	int x;
	int y;
} point;
point q[1000000];

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%s", map[i]);
	}
}

int main(void){
	int ans = -1;
	Input_Data();		//	입력 함수

	// visit 배열 초기화..큰수로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 100000;
		}
	}
	
	point curr, next;
	int nx, ny;
	int front, rear, temp;
	
	visit[0][0] = 0;// first valut (0,0) 은 시작점이고 가격은 0 으로 지정됨.
	curr.x = 0; curr.y = 0;
	q[rear++] = curr;
	while (front < rear) {
		curr = q[front++];
		printf ("current pos = ");
		// 상하좌우 값 확인
		for (int i = 0; i < 4; i++) {
			nx = curr.x + dir_x[i];
			ny = curr.y + dir_y[i];
			if (nx < 0 || nx > N-1 || ny < 0 || ny > N-1) 
				continue;
			// 값 비교
			temp = visit[curr.x][curr.y] + map[nx][ny];
			if (temp < visit[nx][ny]) { // 최소값 찾아서 visit[][] 에 저장.
				visit[nx][ny] = temp;
				q[rear++] = next;//????
			}
			
			next.x = nx; next.y = ny;
		}
	}
	
	ans = visit[N-1][N-1];// 목적지까지의 최소값
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
