#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
struct send_mesg
{
	int value;
	char ch;
}s;
int main()
{
	//Creating a unique key
	key_t key=ftok("sharedmemeorypr1",65);
	//To get shared memory id
	int shmid=shmget(key,sizeof(struct send_mesg),0666|IPC_CREAT);
	//To attach the pointer to an address of shared memory
	struct send_mesg *ptr=(struct send_mesg*)shmat(shmid,(void*)0,0);
	//Data recieved from shared memory
	printf("Data recieved from shared memory value:%d ch=%c\n",ptr->value,ptr->ch);
	shmdt(ptr);
	shmctl(shmid,IPC_RMID,NULL);
	
}
