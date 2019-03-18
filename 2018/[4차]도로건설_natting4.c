#include <stdio.h>

int N;//지도 크기
int map[110][110];//지도 정보
int dist[110][110];
int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};
int rp, wp;
int test = 0;

typedef struct point{
	int x;
	int y;
}point;
point q[100000];

void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		for(j=0 ; j < N; j++){
			scanf("%1d", &map[i][j]);
		}
	}
	
	for(i = 0 ; i < 110 ; i++){
		for(j = 0 ; j < 110; j++){
			dist[i][j] = 10000000;
		}
	}
	dist[0][0] = 0;
}

int main(void){
	int ans = -1;
	Input_Data();		//	입력 함수
	point cur, next;
	int nx, ny;
	int i,j, temp;
	
	cur.x = 0; cur.y = 0;
	//printf ("[START]Q put : x= %d, y=%d\n", cur.x, cur.y);
	q[wp++] = cur;
	while(rp < wp){
		//printf ("wp = %d, rp = %d \n", wp, rp);
		cur = q[rp++];
		for(i = 0; i < 4; i++){			
			nx = cur.x + dir_x[i];
			ny = cur.y + dir_y[i];
			
			if(nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) {
				//printf ("out of bound: skip \n");
				continue;
			}
			next.x = nx; next.y = ny;
			temp = dist[cur.y][cur.x] + map[ny][nx];
			//printf("nx = %d ny = %d, dist_c = %d, dist_n = %d\n", nx, ny, dist[cur.y][cur.x], temp);
			if (temp < dist[ny][nx]){
				dist[ny][nx] = temp;
				q[wp++] = next;
			}
		}
	}
	ans = dist[N-1][N-1];
	
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
