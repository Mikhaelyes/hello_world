#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) 
{
	if (argc < 2 )
	{
		printf("Not enough arguments\n");
		exit(0);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error with reading\n");
		exit(1);
	}
	int ft = open(argv[2], O_RDWR);
	if (ft >= 0)
		unlink (argv[2]);
	ft = open (argv[2], O_CREAT|O_RDWR, 0666);

	struct stat ss;
	fstat(fd, &ss);
	//printf("%ld\n", ss.st_size);
	off_t size = ss.st_size;
	printf("%ld\n", size);
	void* buffer = malloc(sizeof(ss.st_size));
	read(fd, buffer, 100);
	write(ft, buffer, 100);
	close(fd);
	close(ft);

	return 0;
}
