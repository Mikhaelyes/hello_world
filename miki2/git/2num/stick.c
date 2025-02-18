#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <stdint.h>

int* getpipe(int count)
{
	int* pipes = (int*)malloc(count * 2 * sizeof(int));
	for (int i = 0; i < count; i++)
	{
		pipe(pipes + i * 2);
	}
	return pipes;
}

void closepipe(int* pipes, int count)
{
	for (int i = 0; i < count; i++)
		{
			close(pipes[i * 2]); //close input in pipe
			close(pipes[2 * i + 1]); //close output from pipe
		}
}

void do_command(char* str1, int* pipes, int count, int y)
{
	int i = 0;
	int length = strlen(str1);
	if(length == 0) {
		printf("error with command\n");
		exit(0);
	}

	char **arr_subcoms = (char**)malloc(length);
	while ((arr_subcoms[i] = strtok_r(str1, " ", &str1)))
	{
		i++;
	}

	if (y != 0) //not first input
		dup2(pipes[2 * (y - 1)], STDIN_FILENO);
	if (y < (count - 1)) //not last output
		dup2(pipes[2 * y + 1], STDOUT_FILENO);
	
	closepipe(pipes, count);
	
	if(execvp(arr_subcoms[0], arr_subcoms) == -1) {
		printf("Error with exec\n");
		exit(0);
	}
}

int getcount(char *str)
{
	int res = 0;
	char* temp = (char*)malloc(sizeof(str));
	strcpy(temp, str);
	char* token;
	while (token = strtok_r(temp, "|", &temp))
		res++;
	return res;
}

void wait_children (int count)
{
	int temp;
	for (int i = 0; i < count; i++)
		wait(&temp);
}

int main(int argc, char** argv)
{
	int fd;
	if (argc == 2)
        fd = open(argv[1], O_RDONLY);
	else
	{
	    printf("Error with count of arguments\n");
    	    exit(0);
	}
	
	struct stat fd_stat;
        fstat(fd, &fd_stat);
        off_t fd_size = fd_stat.st_size;
        char* str = (char*)malloc(fd_size);
	if(fd_size == 0) {
		printf("No command\n");
		exit(0);
	}
	
        read(fd, (void*)str, fd_size - 1);
        close(fd);

	int count = getcount(str); //count of commands

	int* pipes = getpipe(count);

	char* str1;
	int* pointer = NULL;
	pid_t pid = 0;
	for (int i = 0; i < count; i++)
		{
			str1 = strtok_r(str, "|", &str);
			pid = fork();
			if (pid == 0) //child
				do_command(str1, pipes, count, i);
		}
	
	closepipe(pipes, count);
	wait_children(count);
	return 0;
}
