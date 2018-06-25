#include <stdio.h>

#define MAX_PROJECT (15) 
typedef struct{
	int start_date; // 시작일
	int end_date; // 종료일
}DATA;

int     N; // 프로젝트 수
DATA    project_info[MAX_PROJECT]; // 프로젝트 정보

void Data_Input(void){
	int i;
	scanf("%d", &N); // 프로젝트 수 입력

	// 프로젝트 정보 입력
	for (i = 0; i < N; i++)	{
		scanf("%d %d", &project_info[i].start_date, &project_info[i].end_date);
	}
}

void Sorting(void){
	int i, j;
	DATA temp;

	// 프로젝트 종료일 기준 오름차순 정렬
	for (i=0;i<N-1;i++){
		for (j=0;j<N-1-i;j++){
			if (project_info[j].end_date > project_info[j + 1].end_date){
				temp = project_info[j];
				project_info[j] = project_info[j + 1];
				project_info[j + 1] = temp;
			}
		}
	}
}

int Solve(void){
	int i, cnt = 0;
	int last_date = -1; // 이전 배정 프로젝트 종료일
	
	// 이전 배정 프로젝트 종료일과 i프로젝트의 시작일 겹치지 않을 경우 배정 선택
	for (i = 0; i < N; i++){
		if (last_date < project_info[i].start_date){
			last_date = project_info[i].end_date;
			cnt++; // 배정된 프로젝트 수 count up
		}
	}
	return cnt;
}


int main(void){
	int sol;

	Data_Input(); // 입력 함수 호출
	Sorting(); // 프로젝트 정렬

	sol = Solve(); // Greedy algorithm으로 최대 배정 수 결정

	printf("%d\n", sol); // 결과 출력
	return 0;
}
