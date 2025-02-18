#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	if(argc !=2) {
		printf("1\n");
		exit(1);
	}
	printf("Privet %s \n", argv[1]);

	return 0;
}
