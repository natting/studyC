#include <stdio.h>

int N;			//	문화재의 개수
int area;		//	면적
int arr[1000];

int main(void){
	int i;
	int pos, height;
	int max = 0, local_max = 0;
	int left_area = 0, mid_area = 0, right_area = 0;
	int start = 1000, end = 0;
	int left_end, right_end;

	scanf("%d", &N);	

	//	코드를 작성하세요
	for (i = 0; i < N; i++){
		scanf("%d %d", &pos, &height);
		arr[pos] = height;
		max = max > height ? max : height;
		start = start < pos ? start : pos;
		end = end > pos ? end : pos;
	}
	
	local_max = 0;
	for (i = start; i <= end; i++) {
		local_max = local_max > arr[i] ? local_max : arr[i];
		if(local_max == max){
			left_end = i;
			break;
		}
		left_area += local_max;
	}

	local_max = 0;
	for(i = end; i >= start; i--) {
		local_max = local_max > arr[i] ? local_max : arr[i];
		if (local_max == max) {
			right_end = i;
			break;
		}
		right_area += local_max;
	}
	
	mid_area = (right_end - left_end + 1) * max;
	
	area = left_area + mid_area + right_area;
	
    printf("%d", area);
    return 0;
 }
