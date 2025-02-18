#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	int fd = open(test.c, O_RDONLY);
	int i = read(fd, buf)
	int j = 0;
	if(i == 1)
		goto L1;
	if(i == 2)
		goto L2;
	if(i == 3)
		goto L3;
	fork();
	printf("%d  %d  %d\n", getpid(), getppid(), i);
	wait();
	write(
L1:

	
	return 0;
}

