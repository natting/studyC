#include <stdio.h>

int H;		
int W;		
int map[50][50];	
int visit[50][50];		

struct ANS{
	int count;	
	int area;		
};
int hh[] = {0, -1, 0, 1};	
int ww[] = {-1, 0, 1, 0};

int Flood_Fill(int h, int w){
	int i, nh, nw, area = 1;
	visit[h][w] = 1;	
	for(i=0;i<4;i++){
		nh = h + hh[i];
		nw = w + ww[i];
		if((map[h][w]&(1<<i)) != 0) continue;	
		if(visit[nh][nw] == 1) continue;				
		area += Flood_Fill(nh, nw);
	}
	return area;
}

struct ANS Solve(void){
	int i, j, area;
	struct ANS sol = {0, 0};
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			if(visit[i][j] == 0){
				area = Flood_Fill(i, j);
				sol.count++;										
				if(sol.area < area) sol.area = area;	
			}
		}
	}
	return sol;
}

void Input_Data(void){
	int i, j;
	scanf("%d %d", &H, &W);
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

int main(void){
	struct ANS ans = {0, 0};

	Input_Data();		

	ans = Solve();

	printf("%d\n", ans.count);		
	printf("%d\n", ans.area);		
	return 0;
}
