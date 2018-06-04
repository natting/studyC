#include <stdio.h>

int N;						//	문화재의 개수
int area;					//	면적

typedef struct {
	int loc;
	int height;
} DATA;
DATA input[1010];

// loc 으로 오름차순 정리
void reorder(void)
{
	int i, j;
	DATA temp;
	
	for(i = 0; i < N-1; i++) {
		for(j = 0; (j + i) < N-1; j++) {
			if(input[j].loc > input[j + 1].loc) {
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}
}

//현재 위치에서 다음에 있는 자기보다 높은 기둥있는지 check
// return : 0=없음. 1~N : 높은 기둥 index
int checkHigher(int index)
{
	int higher, level;
	int i;
	level = input[index].height;
	higher = 0;
	
	for (i = index+1; i < N; i++) {
		if (input[i].height >= level) {
			higher = i;
		}
	}

	return higher;
}

int nextMax(int index)
{
	int tempMax, maxIndex;

	tempMax = input[index+1].height;
	for (int i = index+1; i < N; i++) {
		if (input[i].height >= tempMax) {
			tempMax = input[i].height;
			maxIndex = i;
		}
	}
	return maxIndex;
}
// 현재 인덱스에서 다음 max값
int nextMaxVal(int index)
{
	int tempMax;

	tempMax = input[index].height;
	for (int i = index+1; i <= N; i++) {
		if (input[i].height >= tempMax) {
			tempMax = input[i].height;
		}
	}
	return tempMax;
}
int main(void){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &input[i].loc, &input[i].height);
	}
	// loc 으로 오름차순 정리.
	reorder();

	//	코드를 작성하세요
	int next, max_Index, curr_max, limit;
	max_Index = nextMax(1);
	area = 0;
	limit = 0;
	for (int i = 1; i <= N; i++) {
		//printf ("==== START %d ====\n", i);
		if (i <= max_Index) {	//올라가는중
			if (limit < input[i].height) {
				limit = input[i].height;
			}
			if (i == max_Index) {
				area += limit;
			} else {
				area += limit*(input[i+1].loc - input[i].loc);
			}
		} else {
			// 현재 max : 내려가는중..더이상 올라갈수 없음. max 막대기 다음 max 찾아서 더해주기
			limit = nextMaxVal(i);
			area += limit*(input[i].loc - input[i-1].loc);
		}
	}
	
	printf("%d", area);
	return 0;
}
