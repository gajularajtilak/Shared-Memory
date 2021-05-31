#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct mesg_buffer
{
	long mesg_type;
	struct sendmesg
	{
		int value;
		char ch;
	}s;
}message;
int main()
{
	key_t key;
	int msgid;
	//To generate a unique key
	key=ftok("messagequeuepr2",6);
	//To create a message queue or attch to existing message queue
	msgid=msgget(key,0666|IPC_CREAT);
	printf("Message id=%d\n",msgid);
	message.mesg_type=1;
	//Sending data to process 2
	msgrcv(msgid,&message,sizeof(message),1,0);
	printf("Data recieved from process1 value=%d ch=%c\n",message.s.value,message.s.ch);
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
