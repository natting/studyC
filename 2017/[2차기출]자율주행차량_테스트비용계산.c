#include <stdio.h>

int N;			
int h[31];	
int sol;	

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &h[i]);
	}
}

int main(void){
	int i, sum;
	
	Input_Data();

	for (i = 0; i < N; i++){
		if (h[i] < 3)	continue;					
		else if (h[i] <= 6)	sum = 100;		
		else{
			sum = 100 + (h[i] - 6) * 50;		
			if (sum >= 500) sum = 500;
		}
		sol += sum;
	}
	if (sol >= 10000) sol = sol*0.9;		

	printf("%d", sol);

	return 0;
}
