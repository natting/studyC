#include <stdio.h>

char cstring[500001];
char ystring[1000][100];
int cnt[1000];
int N;

void Input_Data(void) {
	int i;
	scanf("%s", &cstring);
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", &ystring[i]);
		cnt[i] = 0;
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
		printf ("search %dth = %s in %s\n", i, ystring[i], cstring);
		start_addr = &cstring[0];
		length = strlen(ystring[i]);
		printf ("%s length = %d \n", &ystring[i], length);
		do {
			find_addr = strstr(start_addr, &ystring[i]);
			if (find_addr) {
				start_addr = find_addr + length;
				cnt[i]++;
				printf ("find_addr = 0x%x, start_addr=0x%x, cnt[i] = %d \n", find_addr, start_addr, cnt[i]);
			}
		} while (start_addr > &cstring[0] + length && !find_addr);
	}
}

int main() {
	int ret = 0;
	Input_Data();
	ret = Find_String();
	
	if (ret ==0)
		printf("null\n");
	else
		printf("1111\n");

	return 0;
}
