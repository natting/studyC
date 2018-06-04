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
	}
	
	for (i = 0; i < N; i++) {
		id[i] = i + 1;
	}
	
	// 오름차순 정리
#if 1
	for (i = 0; i < N; i++) {
		for (j = 0; j+i < N-1; j++) {
			if (distance[j] > distance[j+1]) {
				swap(&distance[j], &distance[j+1]);
				swap(&id[j], &id[j+1]);
			}
		}
	}
#else
	for (i = N - 1; i > 0; i--) {
		for (j = 1; j < i - 1; j++) {
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

#if 0
	printf("\n");
	for (i = 0; i < N; i++) {
		printf("%d ", distance[i]);
	}
#endif
  return 0;
}
