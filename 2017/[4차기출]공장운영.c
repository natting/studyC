#include <stdio.h>

int N;//일
int S;//보관비용
int C[50010];//가격
int Y[50010];//용량

void Input_Data(void){
	int i;
	scanf("%d %d", &N, &S);
	for(i=0 ; i<N ; i++){
		scanf("%d %d", &C[i], &Y[i]);
	}
}

long long solve(void){
	int i;
	long long sum, price;
	price = C[0];
	sum = price * Y[0];
	for(i=1 ; i<N ; i++){
		price += S;
		if(C[i] < price) price = C[i];
		sum += price * Y[i];
	}
	return sum;
}

int main(void){
	long long ans = -1;
	Input_Data();
	ans = solve();
	printf("%lld\n", ans);
	return 0;
}
