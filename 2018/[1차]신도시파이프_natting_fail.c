#include <stdio.h>
int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보

//====DFS Template
int visit[20][20];// visit 배열
// 가로 세로 위한 structure
struct Q{
	int r, c;
};
struct Q queue[100*100*100];
int wp, rp;	// Queue 돌기 위한 read point, write point
//int visit[110][110];// visit 배열
// 상하좌우(가로/세로) 진행위한 좌표
int rr[] = {-1, 1, 0, 0};
int cc[] = {0, 0, -1, 1};
//0~0xB : 상,하,좌,우 연결확인
int AA[][4] = {
	{0,0,0,0},//0
	{0,0,1,1},//1
	{1,1,0,0},//2
	{0,1,0,1},//3
	{0,1,1,0},//4
	{1,0,1,0},//5
	{1,0,0,1},//6
	{1,1,0,1},//7
	{0,1,1,1},//8
	{1,1,1,0},//9
	{1,0,1,1},//A
	{1,1,1,1},//B
};
//================

void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			scanf("%1x", &map[i][j]);
		}
	}
}
// down이 연결되어 있나?
#define DOWN(aaa) 	(aaa==2||aaa==3||aaa==4||aaa==7||aaa==9||aaa==11)
#define UP(aaa)		(aaa==1||aaa==5||aaa==6||aaa==7||aaa==9||aaa==10||aaa==11)
#define RIGHT(aaa)	(aaa==1||aaa==3||aaa==6||aaa==7||aaa==8||aaa==10||aaa==11)
#define LEFT(aaa)	(aaa==1||aaa==4||aaa==5||aaa==8||aaa==10||aaa==11)
int main(void){
	int ans = -1;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	// 시작점
	queue[wp].r = Y; queue[wp].c = X;
	wp++;
	visit[Y][X] = 1;
	int next;// next 의 파이프모양
	int curr;// current 의 파이프모양
	while (rp < wp) {
		struct Q dir = queue[rp++];
		for (int i = 0; i < 4; i ++) {
			int nr = dir.r + rr[i];//next Y 좌표
			int nc = dir.c + cc[i];//next X 좌표
			curr = map[dir.r][dir.c];
			// 범위 벗어나는지 체크
			if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= N))
				continue;
			// 이미 방문했는지 체크
			if (visit[nr][nc] == 1)
				continue;
			// 연결되는지 체크 : 상은 하랑,하는 상,좌는 우,우는 좌 랑 연결됨. 
			// 상i=0/하i=1/좌i=2/우i=3
			next = map[nr][nc];
			if (next == 0) continue; //갈곳이 없음.
			// 현재 상하좌우로 갈수 있는 곳만 체크. next 가 연결되는지 체크
			if (i == 0 ) { // 상
				//상으로 갈때 Next 가 하가 있는지 2,3,4,7,8,11 && current 가 상이 있는지
				if (DOWN(next) && UP(curr)) {
					printf ("i = 0 [상], next = %d, nr = %d, nc = %d \n", next, nr, nc);
					visit[nr][nc] = 1;
				}
			} else if (i == 1) {//하.
				// 하로 갈때 next 가 상이있는지 2,5,6,7,9,10,11 && current 가 하가 있는지
				if (UP(next) && DOWN(curr)) {
					printf ("i = 1 [하], next = %d, nr = %d, nc = %d \n", next, nr, nc);
					visit[nr][nc]=1;
				}
			} else if (i == 2) {//좌
				// 좌로 갈때 next 가 우가있는지 1,3,6,7,8,10,11 && current 가 좌가 있는지
				if (RIGHT(next) && LEFT(curr)) {
					printf ("i = 2 [좌], next = %d, nr = %d, nc = %d \n", next, nr, nc);
					visit[nr][nc] = 1;
				}
			} else if (i == 3) {//우
				// 우로 갈때 next 가 좌가있는지 1,4,5,8,10,11 && current 가 우가 있는지
				if (LEFT(next) && RIGHT(curr)) {
					printf ("i = 3 [우], next = %d, nr = %d, nc = %d \n", next, nr, nc);
					visit[nr][nc] = 1;
				}
			}
			//큐 갱신
			queue[wp].r = nr; queue[wp].c = nc;
			wp++;
		}
	}
	
	// 빈칸 체크
	int count = 0;
	for (int i= 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf ("%d ", visit[i][j]);
			if (visit[i][j] == 0)
				count ++;
		}
		printf ("\n");
	}
	
	printf("%d\n", count);		//	정답 출력
	return 0;
}
