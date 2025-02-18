#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

main(int argc, char** argv, char** envp)
{
	int p = getpid();
	setenv(argc + 1, 
	execve(argv[1], argv + 1, argv + 2);
	return 0;
}
