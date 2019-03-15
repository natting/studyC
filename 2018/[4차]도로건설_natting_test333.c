#include <stdio.h>
typedef struct pos {
	int x;
	int y;
} pos;
int N;//지도 크기
//char map[110][110];//지도 정보
int map[110][110];//지도 정보 : char 말고 int 로 map 변경
int dist[110][110];//각 지점까지의 최소 거리 저장.
pos queue[110*110];// queue 는 충분히 크게

// 상하좌우
int dir_x[] = {0,0,-1,1};
int dir_y[] = {1,-1,0,0};

void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		for (j = 0; j < N; j++) {
		//scanf("%s", map[i]);
			scanf("%1d", &map[i][j]);
		}
	}
	
	for (i = 0; i < 110; i ++) {
		for (j = 0; j < 110; j++) {
			dist[i][j] = 1000000;//충분히 큰수로 세팅
		}
	}
	dist[0][0] = 0;//start always 0
}

int main(void){
	int ans = -1;
	int rp, wp;
	int nx, ny;
	int temp;
	pos curr, next;
	
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	// init value : 시작지점.
	curr.x = 0; curr.y = 0;
	rp = wp = 0; // queue index 
	queue[wp++] = curr;
	while (rp < wp) {
		curr = queue[rp++];// queue get
		// 상하좌우 체크
		for (int i = 0; i < 4; i++) {
			nx = curr.x + dir_x[i];
			ny = curr.y + dir_y[i];
			printf ("next nx=%d, ny=%d \n", nx, ny);
			if (nx < 0|| nx > N-1 || ny < 0 || ny > N-1)
				continue;
			// 다음 좌표
			next.x = nx; next.y = ny;
			// 이동거리
			printf ("dist = %d \n", dist[curr.x][curr.y]);
			printf ("nx = %d, ny = %d \n", nx, ny);
			temp = dist[curr.x][curr.y] + map[nx][ny];
			if (temp < dist[nx][ny]) {
				dist[nx][ny] = temp;
				queue[wp++] = next;//?????
			}
		}
	}
	
	ans = dist[N-1][N-1]; // N-1, N-1까지의 최소 거리
	
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
