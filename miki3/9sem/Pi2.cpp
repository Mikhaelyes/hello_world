#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{
	double x = 0;
    double s1 = 0;
	int n = 100000000;
	double dx = 1.0 /n;
    double t1 = omp_get_wtime();
	printf("Zoom is %d\n", n);

    for(int i = 0; i < n; i++) {
        x = i * dx;
        s1 += dx * sqrt(1 - x * x);
    }

	s1 = s1 * 4;
	printf("PI is %lf\n", s1);
    double t2 = omp_get_wtime();
    double t3 = t2 - t1;
    printf("Time is %lf\n", t3);
    return 0;
}

