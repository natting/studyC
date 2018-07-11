#include <stdio.h>

void swap(int *i, int *j) {
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

int main() {
	int N;
	int distance[1000] = {0, };
	int id[1000] = {0, };
	int i, j, temp;

	scanf("%d", &N);
	
	for (i = 0; i < N; i++) {
		scanf("%d", &distance[i]);
		id[i] = i + 1;
	}
#if 0// 입력받을때 id 에 저장을 
	for (i = 0; i < N; i++) {
		id[i] = i + 1;
	}
#endif
#if 0//수정 : 오름차순으로
	for (i = N - 1; i > 0; i--) {
		for (j = 1; j < i - 1; j++) {
			if (distance[j] > distance[j+1]) {
				swap(&distance[j], &distance[j+1]);
				swap(&id[j], &id[j+1]);
			}
		}
	}
#else
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - 1; j++) {
			if (distance[j] > distance[j+1]) {
				swap(&distance[j], &distance[j+1]);
				swap(&id[j], &id[j+1]);
			}
		}
	}
#endif

	for (i = 0; i < N; i++) {
		printf("%d ", id[i]);
	}

  return 0;
}
