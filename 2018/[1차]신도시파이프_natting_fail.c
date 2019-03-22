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

int main(void){
	int ans = -1;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	// 시작점
	queue[wp].r = X; queue[wp].c = Y;
	wp++;
	visit[X][Y] = 1;
	int next;
	while (rp < wp) {
		struct Q dir = queue[rp++];
		for (int i = 0; i < 4; i ++) {
			int nr = dir.r + rr[i];
			int nc = dir.c + cc[i];
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
			if (i == 0) {
				//상으로 갈때 Next 가 하가 있는지 2,3,4,7,8,11
				if (next==2||next==3||next==4||next==7||next==9||next==11)
					visit[nr][nc] = 1;
			} else if (i == 1) {
				// 하로 갈때 next 가 상이있는지 2,5,6,7,9,10,11
				if (next==1||next==5||next==6||next==7||next==9||next==10||next==11)
					visit[nr][nc]=1;
			} else if (i == 2) {
				// 좌로 갈때 next 가 우가있는지 1,3,6,7,8,10,11
				if (next==1||next==3||next==6||next==7||next==8||next==10||next==11)
					visit[nr][nc] = 1;
			} else if (i == 3) {
				// 우로 갈때 next 가 좌가있는지 1,4,5,8,10,11
				if (next==1||next==4||next==5||next==8||next==10||next==11)
					visit[nr][nc] = 1;
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
