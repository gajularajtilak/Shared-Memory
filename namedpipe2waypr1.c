#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
struct senddata
{
	int value;
	char ch;
}s;
int main()
{
	//Create a new FIFO special file in current directory
	if(mkfifo("fifo1",0777)==-1)
	{
		printf("FIFO file not created\n");
		return 0;
	}
	//FIFO file can be opened as a normal file using open
	int fd=open("fifo1",O_WRONLY);
	//Writing data to FIFO file
	s.value=10;
	s.ch='a';
	write(fd,&s,sizeof(s));
	close(fd);
	//Again open the same file descriptor to read from FIFO file
	fd=open("fifo1",O_RDONLY);
	read(fd,&s,sizeof(s));
	printf("Data recieved from process2 value=%d ch=%c\n",s.value,s.ch);
	close(fd);
	
	
}
