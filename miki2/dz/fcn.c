#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

int dec(int fd, int k1, int k2)
{
        lseek(fd, (long) k1, 0);
        void* buf = malloc(10);
        int s = 0;
        int k = 1;
        int t = 501;
        int v = 0;
        int v1 = 0;
        for(int i = 0; i < (k2 - k1); i++)
        {
                read(fd, buf, 1);
                char* y = (char*) buf;
                k = t;
                t = *y;
                if(t == 32 || t == 10 || t == 9)
                        t = 48;
                t = t - 48;
                if(t > 9)
                        v = 1;
                s += t;
        }
        if(v == 1) {
                ris(fd, ft, k1, k2);
                v1 = 1;
        }
        if(s % 3 == 0 && s != 0 && (k == 0 || k == 5) && v != 1) {
                v1 = 1;
                bizbaz(ft);
        }
      else {

                if(s % 3 == 0 && s != 0 && v != 1) {
                        v1 = 1;
                        biz(ft);
                }
                if((k == 0 || k == 5) && v != 1) {
                        v1 = 1;
                        baz(ft);
                }
        }
        if (v1 == 0)
                ris(fd, ft, k1, k2);
        return(0);

}

int main(int argc, char* argv[])
{
        if (argc < 2)
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
  	void* buf = malloc(1);
        int k1 = 0;
        int k2 = 0;
        for(int i = 0; i < size; i++)
        {
                read(fd, buf, 1);
                char* y = (char*) buf;
                char t = *y;
		if(t =="|") {
                        k1 = k2;
                        k2 = i;
                dec(fd, k1, k2);
                }
        }
        dec(fd, k2, size);
        close(fd);
        close(ft);
        return(0);

