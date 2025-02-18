#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int dec(off_t size, int pipefd) 
{
	void* baf = malloc(size);
	read(pipefd[0], baf, size);
	printf("%s\n", baf);
	return 0;
}

int create_pipe()
{
	int* pipefd = (int*)malloc(2 * sizeof(int));
	for( i = 0; i < 2; i++)
	{
		pipe(pipefd + i * 2)
	}
	return pipefd;
}

int main(int argc, char* argv[])
{
	int* pipefd = create_pipe();
        if (argc < 1)
        {
                printf("Not enough arguments\n");
                return(0);
        }
        int fd = open(argv[1], O_RDONLY);
        if (fd < 0)
        {
                printf("Error\n");
                return(2);
        }
	struct stat* ss = malloc (sizeof(struct stat));
        fstat(fd, ss);
        off_t size = ss->st_size;
        void* buf = malloc(size);
	void* baf = malloc(size);
	read(fd, buf, size);
	write(pipefd[1], buf, size);
	dec(size, pipefd[2]);
	return 0;

}

