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

typedef struct someArgs_tag {
                int i;
                int n;
                double x;
                double y;
} someArgs_t;

void* HelloWorld(void *args) {
	someArgs_t *arg = (someArgs_t*) args;
	int k;
					//double z1;
					//double z3;
					//double z2[n];
					//z1 = *(x + i * sizeof(double));
	k = (2/(afg->n)) * sqrt(1 - *(arg->x) * *(arg->x));
					//*(y + i*sizeof(double)) = z3;
	return 0;

}

int main(int argc, char* argv[])
{
	int n = argv[1];
	int m = argv[2];
	pthread_t thread[n];
	someArgs_t args[n];
	int status_addr;
	int k = n / m;
	int status;
	int s = 0;
	int i;
	for(i = 0; i < n; i++) {
		x[i] = -1 + i * (2/n);
		args[i].i = i;
		args[i].n = n;
		args[i].x = *x + i * sizeof(double);
		args[i].y = *y + i * sizeof(double);
	}
	for(i = 0; i < n; i++) {
		status = pthread_create(&thread[i], NULL, HelloWorld, (void*) &args[i]);

		status = pthread_join(thread[i], (void**)&status_addr);	
	}
	for(i = 0; i < n; i++)
		s += y[i];
	s = s*2;
	printf("%lf", s);

	return (0);
}
