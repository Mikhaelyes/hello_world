#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


//structure that sends to thread
struct task {
    long double x1;
    long double x2;
    unsigned nsegm;
    
    long double dx;
};

//integrated functions
long double f1(long double x) {
    return x;
}

long double f(long double x) {
    return sin(1/x);
}

//function to thread that calculates integral for segment
void* integrate(void* arg) {
    struct timespec startTime, endTime;
    double elapsed;
    clock_gettime(CLOCK_REALTIME, &startTime);

	struct task* task = (struct task*) arg;

    long double X1 = task->x1;
    long double X2 = task->x2;

    long double dx = task->dx;

    unsigned nsegm = task->nsegm;
//    long double dx = (X2 - X1) / (long double)nsegm;

    //integrating by sum (f1 + f2)/2 * dx
    long double res = 0.0, f1, f2, x1, x2;
    unsigned i;
    for (i=0, x1=X1, x2=x1+dx; i < nsegm; x1=x2, x2=x2+dx, ++i) { 
        f1 = f(x1);
        f2 = f(x2);
        res += (f1 + f2) * dx / 2.0;
    }

    task->x1 = res;

    clock_gettime(CLOCK_REALTIME, &endTime);
    elapsed = endTime.tv_sec - startTime.tv_sec;
    elapsed += (endTime.tv_nsec - startTime.tv_nsec) / 1000000000.0;
    printf("Thread working time: %lf\n", elapsed);
	return NULL;
}

int main(int argc, char ** argv) 
{
    if (argc < 4) {
        fprintf(stderr, "Please enter T:number of threads, N: number of segment parts, dx precision\n");
        return -1;
    }

    struct timespec startTime, endTime;
    double elapsed;
    clock_gettime(CLOCK_REALTIME, &startTime);

    unsigned th_number = strtol(argv[1], NULL, 10);
    unsigned N = strtol(argv[2], NULL, 10);
    th_number = th_number > N ? N : th_number;
    double x1 = 0.015;  //strtod(argv[3], NULL);
    double x2 = 1;   //strtod(argv[4], NULL);
    double E = strtod(argv[3], NULL);
    printf("%lf\n", E);
    double x;

    unsigned const th = th_number;
    unsigned const n = N;
    unsigned i, sent, prev, leftpoint, rightpoint;
    printf("Number of threads: %ld\n", th_number);
    printf("Number of segment parts: %ld\n", N);
    printf("Integrate on segment [%lf , %lf]\n", x1, x2);


    //allocate memory for threads and for their input/output
    pthread_t * threads = malloc(sizeof(pthread_t) * th_number);
	struct task* results = malloc(sizeof(struct task) * th_number);

    //send all threads function with appropriate segment to integrate(see task struct)
//    long double dx = (x2 - x1) / (long double)N;
    long double dx;

	for (i = 0, sent = 0, prev = 0; th_number; --th_number, ++i, N -= sent) {
        unsigned div = N / th_number;
        struct task* task = (struct task*) (results + i);
        leftpoint = i ? prev : 0;
        rightpoint = th_number != 1 ? leftpoint + div: n;

        x = x1 + i * (x2-x1)/th_number;
        dx = sqrt((12 * E * x*x*x*x) / (0.25 * (1+2*x)));
 
        prev = rightpoint;
        sent = rightpoint - leftpoint;

        task->x1 = leftpoint * dx + x1;
        task->x2 = task->x1 + sent * dx;
        task->nsegm = sent;
        task->dx = dx;
        printf("%lf\n", dx);
		pthread_create(threads + i, NULL, integrate, task);
	}

    //calculate whole sum for integral
    long double res = 0;
    int j;
	for (j = 0; j != th; ++j) {
		pthread_join(threads[j], NULL);
		res += results[j].x1;
	}
    free(threads);
    free(results);

    clock_gettime(CLOCK_REALTIME, &endTime);
    elapsed = endTime.tv_sec - startTime.tv_sec;
    elapsed += (endTime.tv_nsec - startTime.tv_nsec) / 1000000000.0;
    printf("Total time: %lf\n", elapsed);
    printf("Result: %LF\n", res);

    return 0;
}
