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
	key=ftok("messagequeuepr1",65);
	//Storing data to send
	message.s.value=20;
	message.s.ch='c';
	//To create a message queue or attch to existing message queue
	msgid=msgget(key,0666|IPC_CREAT);
	printf("Mesaage id=%d\n",msgid);
	message.mesg_type=1;
	//Sending data to process 2
	msgsnd(msgid,&message,sizeof(message),0);
	printf("Data sent to queue sucessfully\n");
	return 0;
}
