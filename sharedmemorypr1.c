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
	//Store data into variables
	ptr->value=20;
	ptr->ch='A';
	printf("Data Copied to shared memory sucessfully\n");
	shmdt(ptr);
	
}
