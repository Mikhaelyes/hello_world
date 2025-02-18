#include <fcntl.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printflock(struct flock LL)
{
    	printf("LOCK INFO:\n");
    	printf("Lock type: %d\n", LL.l_type);
    	printf("Whence: %d\n", LL.l_whence);
    	printf("Length: %ld\n", LL.l_len);
    	printf("Pid: %d\n", LL.l_pid);
    	printf("Start offset: %ld\n\n", LL.l_start);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Not enough arguments\n");
		return(0);
	}
	struct flock LL = {0};
	LL.l_whence = SEEK_SET;
	LL.l_len = 0;

	int fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		printf("error with reading");
        	exit(0);
	}
	int ret = fcntl(fd, F_GETLK, &LL);
	if (ret < 0)
	{
        	printf("error\n");
        	close(fd);
    	}
    	printflock(LL);
	printf("Lock type 0 is F_RDLCK \nLock type 1 is F_WRLCK \nLock type 2 is F_UNLCK \n");
    	close(fd);
}
