#include <stdio.h>
// reculsive function 으로 구현된 것
long long int kimchi(int n){
	if (n <= 3)	return 1;
	else if (n % 3 == 0) return 3 * kimchi(n - 1) - 2 * kimchi(n - 2) - kimchi(n - 3);
	else if (n % 3 == 1) return 3 * kimchi(n - 1) - 2 * kimchi(n - 2) + kimchi(n - 3);
	else return 2 * kimchi(n - 1) - 2 * kimchi(n - 2) + kimchi(n - 3);
}
// factoryR 재귀함수 대신해서 array 사용
long long int kimchi(int n){
	long long int a[100] = { 0, 1, 1, 1 };
	for (int i = 4; i <= n; i++){
		if (i % 3 == 0) {
			a[i] = 3 * a[i - 1] - 2 * a[i - 2] - a[i - 3];
		} else if (i % 3 == 1) {
			a[i] = 3 * a[i - 1] - 2 * a[i - 2] + a[i - 3];
		} else {
			a[i] = 2 * a[i - 1] - 2 * a[i - 2] + a[i - 3];
		}
	}
	return a[n];
}
// Re by natting
long long int kimchi2(int n){
	int i;
	long long int mem[100] = {0, 1, 1, 1,};
	//if (i <= 3) return mem[n];
	for (i = 4; i <= n; i++){
		if (n % 3 == 0)
			mem[i] = 3 * mem[i-1] - 2 * mem[i-2] - mem[i-3];
		else if (n % 3 == 1)
			mem[i] = 3 * mem[i - 1] - 2 * mem[i - 2] + mem[i - 3];
		else
			mem[i] = 2 * mem[i - 1] - 2 * mem[n - 2] + mem[n - 3];
	}
	printf ("mem[%d] = %d \n", i, mem[n]);
	return mem[n];
}

int main(void){
	int T;
	scanf("%d", &T);
	//printf("%lld", kimchi(T));
	printf("%lld", kimchi2(T));
	return 0;
}
