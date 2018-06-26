// Q4
//

#include <stdio.h>

int N;//건물 수
int H[80010];//건물 높이

int prevN;
int prevH[80010];
int prevD[80010];

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%d", &H[i]);
	}
}

int main(void){
	long long ans = -1;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	/*
	// 테스트셋7 이후 timeout
	long long total = 0;
	for(int i = 0; i < N; ++i) {
		int count = 0;
		for(int j = i + 1; j < N; ++j) {
			if(H[i] <= H[j]) {
				break;
			} else {
				++count;
			}
		}
		total += count;
	}
	*/
	long long total = 0;
	int D = 0;
	int D2 = 0;
	for(int i = N - 2; i >= 0; --i) {
		if(H[i] > H[i+1]) {
			++D;
			D2 = 0;
			for(int j = prevN - 1; j >= 0; --j) {
				if(H[i] > prevH[j]) {
					D2 += (prevD[j] + 1);
				} else {
					break;
				}
			}
		} else {
			prevH[prevN] = H[i + 1];
			prevD[prevN] = D;
			++prevN;
			D = 0;
			D2 = 0;
		}
		//printf("%d \n", D);
		//printf("%d \n", D2);
		total += (D + D2);
	}
	
	ans = total;
	
	printf("%lld\n", ans);		//	정답 출력
	return 0;
}
