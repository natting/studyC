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
		cnt[i] = 0;
	}
}

int max_string()
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

void check_result()
{
	for (int i = 0; i < N; i++) {
		printf ("%s : found %d \n", ystring[i], cnt[i]);
	}
}

int Find_String()
{
	int i, length;
	char * start_addr;
	char * find_addr;
	char * search_addr;
	// ystring 1000명을 1번부터 검색
	// cstring 끝까지 몇명인지 검색
	for (i = 0; i < N; i++) {
		//printf ("search %dth = %s in %s\n", i, ystring[i], cstring);
		start_addr = &cstring[0];
		length = strlen(ystring[i]);
		do {
			//printf ("start=0x%x, str=%s \n", start_addr, ystring[i]);
			find_addr = strstr(start_addr, &ystring[i]);
			if (find_addr) {
				found ++;
				cnt[i]++;
				//printf ("found %s at 0x%x (%dth)\n", ystring[i], find_addr, cnt[i]);
				start_addr = find_addr + 1;//찾은것 다음 주소부터 다시 검색
			} else {
				//printf("DONE searching \n");
				break;
			}
			//start_addr++;
		} while (1);
	}
}

int main() {
	int ret = 0;
	Input_Data();
	ret = Find_String();
	//check_result();
	ret = max_string();
	
	if (found == 0)
		printf("null\n");
	else
		printf("%s\n", ystring[ret]);

	return 0;
}
