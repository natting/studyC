#include <stdio.h>

int N, Q, sol;
int T[101];
int engineer[6];

void Input_Data(void){
	int i;
	scanf("%d %d",&N,&Q);   
	for(i=1;i<=Q;i++){	
		scanf("%d",&T[i]);			
	}
}

int Simulation(void){
	int min_idx = 0;
	int i,j;
	int sol=0;

	for(i=1;i<=Q;i++){
		min_idx = 1;

		for(j=2;j<=N;j++){
			if(engineer[min_idx] > engineer[j]) {
				min_idx = j;
			}
		}
		engineer[min_idx]+=T[i];
	}

	for(i=1;i<=N;i++){
		if(sol < engineer[i]) sol = engineer[i];
	}
	return sol;
}

int main(void){
	Input_Data();				

	sol = Simulation(); 	

	printf("%d\n",sol);	

	return 0;
}
