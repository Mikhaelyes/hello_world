#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int main(int argc, char* argv[])
{
         if (argc < 2)
        {
                printf("Not enough arguments\n");
                return(0);
        }
        int fd = open(argv[1], O_RDONLY, 0666);
        if (fd < 0)
        {
                printf("Error\n");
                return(2);
        }
        struct stat buffer;
        fstat(fd, &buffer);
        int sz = buffer.st_size;
        printf("%d\n", sz);
        key_t key1 = ftok("/home/mikle/miki2/4sem", 1);
        key_t key = ftok("/home/mikle/miki2/3sem", 1);
        char* str = (char*) malloc(sz);
        char* str1 = (char*) malloc(sizeof(int));
        read(fd, str, sz);
	int idshm = shmget(key, sz, IPC_CREAT | 0666);
        int idshm1 = shmget(key1, sizeof(int), IPC_CREAT | 0666);
        void* uk = shmat(idshm, NULL, 0);
        void* uk1 = shmat(idshm1, NULL, 0);
        memcpy(uk, str, sz);
        memcpy(uk1, &sz, sizeof(int));
        shmdt(uk);
        shmdt(uk1);
        free(str);
        close(fd);
        return 0;
}

