#include <stdio.h>
#include <sting.h>

void * memcpy(void * destination, const void * source, size_t num);
char * strcpy(char * destination, const char * source);
char * strncpy(char * destination, const char * source, size_t num);
char * strcat(char * destination, const char * source);// source를 destination뒤에 붙인다
char * strncat(char * destination, char * source, size_t num);//source에서 destination뒤에 처음 num개의 문자들을 붙인다
int strncmp(const char * str1, const char * str2, size_t num);//str1의 처음 num개의 문자를 str2의 처음 num개의 문자와 비교한다
char * strchr(const char * str, int character);//str에서 처음으로 character와 일치하는 문자의 주소를 반환한다.
size_t strlen(const char * str);//str의 길이를 반환한다.
char * strstr(const char * str1, const char * str2);//str1에서 str2를 검색하여 가장 먼저 나타나는 곳의 위치를 반환한다.
