#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
	int packet_no;
	int prior_level;
	struct st *next;
}PACKET;

PACKET buffer;
PACKET *last_packet;

void Input_Packet(PACKET* p)
{
	scanf("%d %d",&p->packet_no,&p->prior_level); // packet_no, prior_level 입력
}

#define SUCCESS				(0)
#define ERROR_PUT_PACKET	(-1)
#define ERROR_BUF_EMPTY		(-2)

int Put_Packet_to_Buffer_spec2(PACKET* p)
{
	PACKET *pac;

	if (p == NULL) return ERROR_PUT_PACKET;

	pac = (PACKET*)malloc(sizeof(PACKET));
	if (pac == NULL) return ERROR_PUT_PACKET;

	*pac = *p;

	if(buffer.next == NULL){
		buffer.next = pac;
		return;
	}

	PACKET *cur;
	PACKET *prev;
	
	cur = buffer.next;
	prev = &buffer;
	
	while(cur){
		if(cur->prior_level < pac->prior_level){
			prev = cur;
			cur = cur->next;
		}
		else if(cur->prior_level == pac->prior_level){
			if(cur->packet_no < pac->packet_no){
				prev = cur;
				cur = cur->next;
			}
			else{
				pac->next = prev->next;
				prev->next = pac;
				return;
			}
		}
		else{
			pac->next = prev->next;
			prev->next = pac;
			return;
		}
	}
	
	prev->next = pac;
		
	return SUCCESS;
}

int Put_Packet_to_Buffer(PACKET* p)
{
	PACKET *pac;

	if (p == NULL) return ERROR_PUT_PACKET;

	pac = (PACKET*)malloc(sizeof(PACKET));
	if (pac == NULL) return ERROR_PUT_PACKET;

	*pac = *p;

	last_packet->next = pac;
	last_packet = pac;

	return SUCCESS;
}

int Get_Packet_from_Buffer(PACKET* p)
{
	if (buffer.next == NULL) return ERROR_BUF_EMPTY;
	*p = *buffer.next;
	free(buffer.next);

	buffer.next = p->next;
	
	return SUCCESS;
}



int main(void)
{
	int i,N;
	PACKET packet;

	scanf("%d", &N);	// 패킷의 수 입력
	
	last_packet = &buffer;
	packet.next = NULL;
	// 패킷의 수신
	for (i = 0; i < N; i++)
	{
		Input_Packet(&packet);
		//Put_Packet_to_Buffer(&packet);
		Put_Packet_to_Buffer_spec2(&packet);
	}
	
	// 패킷 처리순서 출력
	while (Get_Packet_from_Buffer(&packet) == SUCCESS)
	{
		printf("%d ", packet.packet_no);
	}

	return 0;
}
