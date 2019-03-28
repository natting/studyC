#include <stdio.h>

#define MAX_N (95)
int matrix[MAX_N][MAX_N];

// 작성할 함수
void Make_Magic_Square(int N)
{
	int center = N/2;
	int cx = 0; int cy = 0;
	matrix[0][center] = 1;
	cx = center; cy = 0;
	for (int i = 2; i <= N*N; i++) {
		//Print_Complete_Matrix2(N);
		if (i < N) {
			// 윗행의 왼쪽열
			if (cy == 0) cy = N;
			if (cx == 0) cx = N;
			matrix[cy-1][cx-1] = i;
			cx = cx-1; cy = cy -1;
		} else {
			if ((i-1) % N == 0) {
				//N의 배수 : 아래행 같은열
				if (cy+1 >= N) {
					//printf ("1111 : i = %d \n", i);
					cy = 0;
				} else {
					//printf ("2222 : i = %d\n", i);
					cy++;
				}
				//printf ("%d, %d = %d\n", cy, cx, i);
				matrix[cy][cx] = i;
			} else {//바로윗행 왼쪽열
				//printf ("i = %d \n", i);
				if (cy == 0) {
					cy = N-1;
				} else {
					cy--;
				}
				if (cx == 0)
					cx = N-1;
				else 
					cx--;
				matrix[cy][cx] = i;
				//if (i==5) printf ("%d, %d = %d\n", cy, cx, i);
			}
		}
	}
}

void Print_Complete_Matrix(int N)
{
	int r, c;
	for (r=0;r<N;r++)
	{
		for (c=0;c<N;c++)
		{
			printf("%d ",matrix[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	int N;
	
	// 입력 받는 부분
	scanf("%d", &N);

	// 마방진 완성 코드
	Make_Magic_Square(N);

	// 마방진 출력
	Print_Complete_Matrix(N);
	
	return 0;
}

void Print_Complete_Matrix2(int N)
{
	int r, c;
	printf ("=======================\n");
	for (r=0;r<N;r++)
	{
		for (c=0;c<N;c++)
		{
			printf("%d ",matrix[r][c]);
		}
		printf("\n");
	}
	printf ("=======================\n");
}
