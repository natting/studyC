#include <stdio.h>
#include <string.h>

int N;					//	모델명의 개수
char str[10010][21];	//	모델명 저장

typedef struct _st{
	char modelName[21];
	int cnt;
	int first;
}Data;

// b 모델수가 더 크면 True, or False - qsort 사용하기 위해서..
// 오름차순 or 내림차순 함수로 
int cmp(const void *a, const void *b){
	Data *A = (Data*)a;
	Data *B = (Data*)b;
	
	return A->cnt < B->cnt;
}

int main(void){
	int i, j;

	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%s", str[i]);
	}

	//	코드를 작성하세요
	Data data[10000];
	int num_model = 0;
	
	int next[10000] = {0, };
	int prev = 0;
	
	for (i = 0; i < N; i++){
		if(str[i][0] != 0){
			strcpy(data[num_model].modelName, str[i]);
			data[num_model].cnt = 1;
			data[num_model].first = i;
			prev = i;
			for (j = i + 1; j < N; j++) {
				if (strcmp(str[i], str[j]) == 0) {
					data[num_model].cnt++;
					str[j][0]  = 0;
					next[prev] = j;
					prev = j;
				}
			}
			num_model++;
		}
	}
	// void qsort (void *base, size_t nel, size_t width, int (*compare)(const void *, const void *);
	// base : 정렬하고자 하는 배열의 포인터
	// nel : 배열의 각 원소들의 총 수
	// width : 배열에서 원소 하나의 크기
	// (*compare) : 비교를 수행할 함수 포인터
	qsort(data, num_model, sizeof(data[0]), cmp);

	int sum=0;
	
	for (i = 0; i < num_model; i++){
		int idx = data[i].first;
		
		if (sum == 0 && data[i].cnt == 1) {
			printf("unique\n");
			break;
		}
		else if (sum >= N/2)
			break;
		else
			sum += data[i].cnt;
		
		printf("%s", data[i].modelName);
		while (1) {
			printf(" %d", idx+1);
			idx = next[idx];
			if(idx == 0)
				break;
		}
		printf("\n");
	}

	return 0;
}
