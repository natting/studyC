#include <stdio.h>

#define MAX_PROJECT (15) 
typedef struct{
	int start_date; // 시작일 
	int end_date; // 종료일
}DATA;

int		N;// 프로젝트 수
DATA	project_info[MAX_PROJECT]; // 프로젝트 정보
DATA	info2[MAX_PROJECT]; // 프로젝트 정보
DATA	temp;//temp to re-order

void Data_Input(void)
{
	int i;
	scanf("%d", &N); // 프로젝트 수 입력
	
	// 프로젝트 정보 입력
	for (i = 0; i < N; i++) {
		scanf("%d %d", &project_info[i].start_date, &project_info[i].end_date);
	}
}

// project_info re-order
void reorder(void)
{
	int i, j;

	for(i = 0; i < N-1; i++) {
		for(j = 0; (j + i) < N-1; j++) {
			if(project_info[j].start_date > project_info[j + 1].start_date) {
				temp = project_info[j];
				project_info[j] = project_info[j + 1];
				project_info[j + 1] = temp;
			}
		}
	}
}

// start 부터 시작해서 end_date 가 제일 작은 값 찾고 index return
// start_date 는 이전 end_date 보다 커야함.
int find_min_end(int start_index, int prev_end)
{
	int min_index = -1;
	int min = 300;
#if 0	
	printf ("---------------\n");
	printf ("start_index= %d, prev_end=%d\n", start_index, prev_end);
#endif
	for (int i = start_index; i < N; i++) {
		if (project_info[i].start_date > prev_end && project_info[i].end_date <= min) {
			min = project_info[i].end_date;
			min_index = i;
#if 0
			printf ("take it : %d ~ %d, i = %d, min=%d\n",
							project_info[i].start_date, project_info[i].end_date,
							i, min);
#endif
		} 
#if 0
		else {
			printf ("skip : %d ~ %d, i = %d, min=%d\n",
							project_info[i].start_date, project_info[i].end_date,
							i, min);
		}
#endif
	}
#if 0
	printf("found : min_index = %d, %d ~ %d\n", min_index, 
				project_info[min_index].start_date,
				 project_info[min_index].end_date);
#endif
	return min_index;
}

int main(void){
	int sol = 0;
	int ret ; 
	int cnt, max, max_cnt;
	int i, j;
	int curr_end, next, end_min_index, min_end_date;

	Data_Input(); // 입력함수 호출

	//start day 순으로 소팅
	reorder();
#if 0
	printf ("==============\n");
	for(i = 0; i < N; i++) {
		printf ("%2d    %2d \n", project_info[i].start_date, project_info[i].end_date);
	}
	printf ("==============\n");
#endif
	// 시작점 찾기...end_date 가 min인 index 찾기
	min_end_date = 300;
	
	for (i = 0; i < N; i++) {
		if (min_end_date > project_info[i].end_date) {
			min_end_date = project_info[i].end_date;
			end_min_index = i;
		}
	}
	cnt = 1;//시작 찾음.
#if 0	// i 부터 다시 시작.
	printf ("start = %d.\nfind : %d ~ %d \n", end_min_index,
				 project_info[end_min_index].start_date, project_info[end_min_index].end_date);
#endif
	i = end_min_index;
	do {
		ret = find_min_end(i, project_info[i].end_date);
#if 0
		printf ("found index = %d \n", ret);
#endif
		if (ret < 0) break;
		i = ret; // index 로 바로 넘어가자
		cnt ++;
	} while (i < N);
	
	sol = cnt;
	printf("%d\n", sol); // 결과 출력
	return 0;
}
