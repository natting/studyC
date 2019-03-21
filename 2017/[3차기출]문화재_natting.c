#include <stdio.h>

int N;						//	문화재의 개수
int area;					//	면적
int pos, height;
int H[1100];
int maxH;//max 높이
int maxX;//max 높이의 좌표

int main(void){
	int lastX = 0;
	int count = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &pos, &height);
		
		H[pos] = height;
		//printf ("H[%d] = %d \n", pos, H[pos]);
		if (maxH < height) {
			maxH = height;//최고 높이
			maxX = pos;		//최고 높이의 좌표
		}
		if (pos > lastX) lastX = pos;
		count++;
	}

	//printf ("maxX = %d, maxH = %d \n", maxX, maxH);
	int left_sum = 0;
	int current_max = 0;
	H[0] = 0;
	for (int i = 1; i < maxX; i++) {
		if (H[i] > current_max) 
			current_max = H[i];
		left_sum += current_max;
	}
	
	int right_sum = 0;
	current_max = 0;
	//printf ("count = %d, maxX = %d \n", count, maxX);
	for (int i = lastX; i > maxX; i--) {
		if (H[i] > current_max) {
			current_max = H[i];
		}
		right_sum += current_max;
	}
	area = left_sum + right_sum + maxH;
	//printf ("left = %d, right = %d, max = %d, tot = %d\n", 
	//				left_sum, right_sum, maxH, area);
	printf("%d", area);
	return 0;
 }
