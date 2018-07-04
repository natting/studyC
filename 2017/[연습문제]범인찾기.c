#include <stdio.h>

char cstring[500001];
char ystring[1000][100];
int cnt[1000];
int N;
int found = 0;

void Input_Data(void) {
	int i;
	scanf("%s", &cstring);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &ystring[i]);
		cnt[i] = 0;//일치하는 string 갯수 저장하기 위한 버퍼 초기화 
	}
}

// cnt 제일 max 인 string 을 찾기 위해서..
int max_string(void)
{
	int max = cnt[0];
	int ret = 0;

	for (int i = 0; i < N; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			ret = i;
		}
	}
	return ret;
}

// only for Test
void check_result(void)
{
	for (int i = 0; i < N; i++) {
		printf ("%s : found %d \n", ystring[i], cnt[i]);
	}
}

void Find_String()
{
	int i;
	char * start_addr;
	char * find_addr;
	// ystring 1000명을 1번부터 검색
	// cstring 끝까지 몇명인지 검색
	for (i = 0; i < N; i++) {
		start_addr = &cstring[0];
		do {
			find_addr = strstr(start_addr, &ystring[i]);
			if (find_addr) {
				found ++;
				cnt[i]++;
				start_addr = find_addr + 1;//찾은것 다음 주소부터 다시 검색
			} else {
				//printf("DONE searching \n");
				break;
			}
		} while (1);
	}
}

int main() {
	int ret = 0;
	Input_Data();
	Find_String();

	// strstr 에서 한번도 일치된적이 없으면 found = 0
	if (found == 0)
		printf("null\n");
	else {
		ret = max_string();
		printf("%s\n", ystring[ret]);
	}
	return 0;
}
