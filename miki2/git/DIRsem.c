#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>

main(int argc, char** argv, char** envp)
{
	char* dir = argv[1];
	DIR* dh = opendir(dir);
	struct dirent* file;
	while ((file = readdir(dh))) {
		printf("%s\n", file->d_name);
		}	
	closedir(dh);
	return 0;
}	
