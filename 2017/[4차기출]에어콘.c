#include <stdio.h>

int N;

// 온도값 범위 변수
int min_temp;
int max_temp;

// 습도값 범위 변수
int min_humidity;
int max_humidity;

// 온/습도 변화량
int Temperature_diff[101];
int Humidity_diff[101];

// 온/습도 범위 초과 flag
int flag_control_temp;
int flag_control_humidity;

// 온/습도 초기 값
#define INIT_TEMPERATURE (20)
#define INIT_HUMIDITY (50)

int Check_Temp_and_Control(int diff)
{
	static int cur_temp = INIT_TEMPERATURE;	// 현재 온도 값
	cur_temp += diff;

	// 범위 벗어났을 경우
	if (cur_temp > max_temp || cur_temp < min_temp)	{
		flag_control_temp = 1;
		cur_temp = INIT_TEMPERATURE;
		return 1;
	}
	else 
		return 0;
}

int Check_Humidity_and_Control(int diff)
{
	static int cur_humidity = INIT_HUMIDITY;// 현재 습도 값
	cur_humidity += diff;

	// 범위 벗어났을 경우
	if (cur_humidity > max_humidity || cur_humidity < min_humidity)	{
		flag_control_humidity = 1;
		cur_humidity = INIT_HUMIDITY;
		return 1;
	}
	else 
		return 0;
}

void Reset_Flag(void)
{
	// flag  초기화
	if (flag_control_temp) flag_control_temp = 0;
	if (flag_control_humidity) flag_control_humidity = 0;
}

void Control_Temp_and_Humidity(void)
{
	int i;

	for (i = 1; i <= N; i++)
	{
		// 온습도 범위 체크 및 제어
		int ret_temp;
		int ret_hudity;
		
		ret_temp = Check_Temp_and_Control(Temperature_diff[i]);
		ret_hudity = Check_Humidity_and_Control(Humidity_diff[i]);
		if (ret_temp || ret_hudity)
		{
			if (flag_control_temp && flag_control_humidity) printf("3\n");
			else if (flag_control_temp) printf("1\n");
			else printf("2\n");

			Reset_Flag();
		}
		else printf("0\n");
	}
}

void Input_Data(void)
{
	int i;
	
	// 전체 동작시간 , 온도/ 습도 범위값 입력
	scanf("%d", &N);
	scanf("%d %d", &min_temp, &max_temp);
	scanf("%d %d", &min_humidity, &max_humidity);

	// 온도 변화량 입력
	for (i = 1; i <= N; i++) {
		scanf("%d", &Temperature_diff[i]);
	}
	
	// 습도 변화량 입력
	for (i = 1; i <= N; i++) {
		scanf("%d", &Humidity_diff[i]);
	}
}

int main(void)
{
	Input_Data();

	Control_Temp_and_Humidity();

	return 0;
}
