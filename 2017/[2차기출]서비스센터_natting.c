#include <stdio.h>

int N, Q, sol;
int T[101];
int engineer[6];

void Input_Data(void){
	int i;
	scanf("%d %d",&N,&Q);	// 엔지니어의 수, 고객의 수
	for(i=1;i<=Q;i++){
		scanf("%d",&T[i]);			// 고객의 업무처리 시간
	}
}

int find_min_eng()
{
	int min_v = engineer[1];
	int min_eng=1;
	for (int i = 1; i <= N; i++) {
		//printf ("find_min : engineer[%d]=%d, min_v=%d \n", i, engineer[i], min_v);
		if (engineer[i] < min_v) {
			min_v = engineer[i];
			//printf ("min engineer = %d \n", i);
			min_eng = i;
		}
	}
	//printf ("min engineer = %d, val = %d \n", min_eng, engineer[min_eng]);
	return min_eng;
}

int main(void){
	Input_Data();				// 입력 함수

	//	코드를 작성하세요
	int index = 0;
	for (int i = 1; i <= Q; i++) {
		index = find_min_eng();
		//printf ("engineer[%d] = %d + %d \n", index, engineer[index], T[i]);
		engineer[index] += T[i];
	}
	//sol = find_max_eng();
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (engineer[i] > max)
			max = engineer[i];
	}
	sol = max;
	
	printf("%d\n",sol); 	//	정답 출력

	return 0;
}
