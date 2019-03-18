#include <stdio.h>
int N = 100;
int data[N];

void swap(int *i, int *j) {
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}
// =========================================
// sorting LAST
int sorting (void) {
	int i,j,N;
	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			if (a > b) // or a < b
				swap(a,b);
		}
	}
}
// =========================================
// 오름차순 정리 in array
int rise_up(void) {
	int i, j, temp;
	for (i = 0; i < N; i++) {
		for (j = i; j < N-1; j++) {
			if (data[j] > data[j+1]) {
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
}
int sorting (void)
{
	int i, j, temp;
	for (i = 0; i < N; i++) {
		for (j = i; j < N-1; j++) {
			if (data[j] > data[j+1]) {
				// swap
				temp  = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
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
