#include <stdio.h>

int N;               // 제품의 개수
int ID[10000 + 10];  // 아이디
int S[10000 + 10];   // 판매수량
int R[10000 + 10];   // 조회회수

// 두 위치의 값을 교환하는 함수
void swap(int x1, int x2)
{
	int temp;

	temp = S[x2];
	S[x2] = S[x1];
	S[x1] = temp;

	temp = R[x2];
	R[x2] = R[x1];
	R[x1] = temp;
	
	temp = ID[x2];
	ID[x2] = ID[x1];
	ID[x1] = temp;
}

void test(int test_num)
{
	//test
	printf ("%d : =================\n", test_num);
	for (int i = 0; i < N; i++) {
		printf("%d %d %d \n", ID[i], S[i], R[i]);
	}
	printf ("%d : =================\n", test_num);
}

int main(void)
{
	int i, j;

	// 입력 읽기
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d %d", &ID[i], &S[i], &R[i]);
	}

	// 선호도 순으로 정렬
	for (i = 0; i < N-1; i++) {
		for (j = i+1; j < N; j++) {
			if (S[j] > S[i]) {
				swap(j, i);
			}
			else if (S[j] == S[i]) {
				if (R[j] > R[i]) {
					swap(j, i);
				} else if (R[j] == R[i]) {
					if (ID[j] > ID[i])
						swap(j, i);
				}
			}
		}
	}

	// 결과 출력
	for (i = 0; i < N; i++) {
		printf("%d ", ID[i]);
	}
	printf ("\n");
			
	return 0;
}
