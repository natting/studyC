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
	
	int Q[wp++] = 0;//시작점
  
  while (rp < wp) {
    Start = Q[rp++];//Q get
    if (....) {
      Q[wp++] = value;
    }
  }
}
