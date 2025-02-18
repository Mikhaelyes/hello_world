#include <stdio.h>
#include <unistd.h>

int main()
{
		//execl("/bin/ls", "ls -la", (void*)0);
	execvp("3.c", "gcc");

	printf("1\n");
	return(0);

}

