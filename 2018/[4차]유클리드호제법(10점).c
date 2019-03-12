#include <stdio.h>

int GCD(int m, int n);

// 작성해야 할 함수
int GCD(int m, int n)
{
	int rest = 0;
	int temp;
	
	//printf ("11111:  %d \n", m%n);
	// m >= n
	do {
		if (m % n == 0)
			return n;
		m = m%n;
		//printf ("rest = %d \n", m);
		temp = m;
		m = n;
		n = temp;
	} while (1);//while (m % n == 0);
	
	return n;
}

int main(void)
{
	int m, n, r;
	
	// 입력 받는 부분
	scanf("%d %d",&m, &n);
	
	// 큰수를 변수 m에 대입
	if (m < n)
	{
		r = m; m = n; n = r;
	}
	
	if (n == 0)
		r = m;
	else
		r = GCD(m,n);

	printf("%d\n",r);
}
