#include <stdio.h>

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보

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
	
	
	
	
	printf("%d\n", ans);		//	정답 출력
	return 0;
}
