int N;//지도 크기
char map[110][110];//지도 정보 <--- 입력받는 data들
#define IMP (1<<29)//초기화 위한 큰값..
// 가로 세로 위한 structure
struct Q{
	int r, c;
};
struct Q queue[100*100*100];
int wp, rp;	// Queue 돌기 위한 read point, write point
int visit[110][110];// visit 배열
// 상하좌우(가로/세로) 진행위한 좌표
int rr[] = {-1, 1, 0, 0};
int cc[] = {0, 0, -1, 1};
void main()
{
	Input_Data();// data 입력 받음 : map 배열과 N(크기) 입력받음
	// visit 배열 큰수로 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 10000;// 큰수로 초기화
		}
	}
	// queue 시작 준비
	queue[wp].r = 0; queue[wp].c = 0;//시작점
	wp++;
	visit[0][0] = 0;
	while (rp < wp) {
		struct Q dist = queue[rp++];// Q에서 하나 끄냄.
		//상하좌우 검색
		for (int i = 0; i < 4; i++) {
			// next r,c(가로,세로이동한 위치)
			int nr = dist.r + rr[i];
			int nc = dist.c + cc[i];
			// 이동하는 위치가 범위 벗어났는지 체크
			if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N)) continue;//go to next
			// 최소값 구하기 이므로...작은면 갱신..map[][]이 char 이므로 - '0'
			if (visit[nr][nc] > visit[dist.r][dist.c] + map[nr][nc] - '0') {
				visit[nr][nc] = visit[dist.r][dist.c] + map[nr][nc] - '0';
				queue[wp].r = nr; queue[wp].c = nc; // next queueing
				wp++;// write pointer 증가
			}
		}
	}
	ans = visit[N-1][N-1];
	printf ("%d\n", ans);
}
