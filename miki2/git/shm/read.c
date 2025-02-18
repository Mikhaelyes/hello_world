#include <sys/types.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

int main() {
        key_t key = ftok("/home/mikle/miki2/3sem", 1);
        key_t key1 = ftok("/home/mikle/miki2/4sem", 1);
        int idshm1 = shmget(key1, sizeof(int), 0);
        void* uk1 = shmat(idshm1, NULL, 0);
        int sz;
        memcpy(&sz, uk1, sizeof(int));
        int id = shmget(key, sz, 0);
        void* uk = shmat(id, NULL, 0);
        void* str = malloc(sz);
        memcpy(str, uk, sz);
        printf("%s\n", str);
        shmdt(uk);
        shmdt(uk1);
        free(str);
        shmctl(id, IPC_RMID, NULL);
        shmctl(idshm1, IPC_RMID, NULL);
        return(0);
}

