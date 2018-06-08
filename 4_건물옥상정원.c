#include <stdio.h>

int N;//건물 수
int H[80010];//건물 높이

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%d", &H[i]);
	}
}

int main(void){
	long long ans = -1;
	int std;
	int cnt = 0;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	for (int i = 0; i < N; i++) {
		std = H[i];
		for (int j = i+1; j < N; j++) {
			if (std > H[j]) cnt ++;
			else 
				break;
		}
	}	
	ans = cnt;
	printf("%lld\n", ans);		//	정답 출력
	return 0;
}
