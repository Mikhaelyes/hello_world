#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int pipeft[2];
	pipe(pipeft);
	char *argc[3];
	int p = getpid();
	char* buf = malloc(100);
	fork();
	if( getpid() != p) {
		argc[0] = "ls";
		argc[1] = "-la";
		argc[3] = "NULL";
		if(argv[3] == "NULL")
			printf("\n1\n");`
		dup2(pipeft[1], 1);
		execlp("ls", "-la", NULL);
	}
	wait();
	dup2(pipeft[0], 0);
	//read(ft, buf, 3);
	//printf("arrara arara arrrra");
	execlp("grep", "grep", "a", NULL);
	close(pipeft[0]);
	close(pipeft[1]);
	return 0;
}
