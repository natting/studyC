#include <stdio.h>

int M;			// 반복 인정 회수
char S[100000 + 10];	// 조사 문자열

int main(void)
{
	int i, j;	// 문자열 S의 어떤 문자를 지시
	int len;	// 문자열 S의 길이
	char r_char;	// 반복되는 문자
	int r_cnt;	// 반복 회수

	// 데이터 읽기
	scanf("%d", &M);
	scanf("%s", &S[0]);

	// 코드 구현 및 결과 출력
	len = strlen(S);
	//printf ("%d : %s \n", len, S);
	
	r_cnt = 1;
	r_char = S[0]; 
	j = 0;
	for (i = 1; i <= len; i++) {
		//printf ("\n r_char = %c, S[%d] = %c \n", r_char, i, S[i]);
		if (S[i] != r_char) {
			if (r_cnt >= M) {
				printf ("%c(%d)", S[i-1], r_cnt);
			} else {
				for (j = 0; j < r_cnt; j++)
					printf ("%c", S[i-1]);
			}
			r_char = S[i];
			r_cnt = 1;
		} else {
			r_cnt++;
			//printf ("\n r_char = %c, r_cnt = %d \n", r_char, r_cnt);
		}
		//printf ("%c(%d)", S[i], r_cnt);
	}

	return 0;
}
