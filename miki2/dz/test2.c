#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int dec(void* buf, int* pipefd)
{
        int count = 0;
        int n = 500;
        int k = 0;
        char* s = (void*) buf;
        char* s1 = malloc(500);
        for(int i = 0; i < sizeof(buf); i++)
        {
                n = strcspn(s, "|");
                if(n != strlen(s) && strlen(s) > 3)
                {
                        strncpy(s1, s, n - 1);
                        count = dec1(s1, pipefd, count);
                        s = s + (n + 2);
                        s1 = s1 + (n + 2);
                }
        }
        strncpy(s1, s, n);
        count = dec1(s1, pipefd, count);
        return count;
}

int dec1(char* s1, int* pipefd, int count)
{
        int n = 500;
        char* s2 = malloc(500);
        for(int i = 0; i < sizeof(s1); i++)
       {
                n = strcspn(s1, " ");
                if(n != strlen(s1) && strlen(s1) > 3)
                {
                        strncpy(s2, s1, n);
                        if(strcmp(s2, "  ") != 0) {
                                write(pipefd[1], s2, 50);
                        }
                        s1 = s1 + (n + 1);
                        s2 = s2 + (n + 1);
                }
        }
        strncpy(s2, s1, n);
        write(pipefd[1], s2, 50);
        char* x = malloc(50);
        strncpy(x, "NULL", 50);
        write(pipefd[1], x, 50);
        count++;
        return count;
}


int main(int argc, char* argv[])
{
        int pipefd[2];
        pipe(pipefd);
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
        read(fd, buf, size);
        int count = dec(buf, pipefd);

	//int* pipes = (int*)malloc(count * 2 * sizeof(int));
//	for( int i = 0; i < count; i++)
//	{
//		pipe(pipes + i * 2);
//	}
        int p = getpid();
        int j;
        int i;
	char** a = (char**)malloc(10 * 50);
        char* x = malloc(50);
        strncpy(x, "NULL", 50);
        printf("%d\n", count);
        for(j = 0; j < count; j++)
  	{
		i = 0;
                fork();
                if(getpid() != p)
                {
                        while(i < 10)
                        {
                                read(pipefd[0], a + i * sizeof(char**), 50);
				printf("%s %d\n", a + i * sizeof(char**), i);
				if (strspn(a + i * sizeof(char**), x) == 4) {
					i = 9;
				}
                                i++;
                        }
			printf("%s\n", a);
			execvp(a, a);
		}
        }
	wait();
	//for(i = 0; i < 1; i++)
	//{
	//	close(pipes[i]);
	//	close(pipes[i + 1]);
	//}
	close(pipefd[1]);
	close(pipefd[0]);
        return 0;

}

