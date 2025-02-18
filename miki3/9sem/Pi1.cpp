#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    int j;
    int i1;
    double s1 = 0;
	int n = 10000000;
	double dx = 1.0 / (double) n;
    double t1 = omp_get_wtime();
    int k = 8;
	printf("Zoom is %d\n", n);
    double s[k];
    for(int i = 0; i < k; i++) {
        s[i] = 0;
    }
    omp_set_num_threads(k);
    int n0 = n / k;
    #pragma omp parallel default (none) private (j, i1, x) shared (n0, dx, s) 
    {
        j = omp_get_thread_num();
        for(i1 = j * n0; i1 < (j + 1) * n0; i1++) {
            x = i1 * dx;
            s[j] += dx * sqrt(1 - x * x);
        }
    }
    for(int i = 0; i < k; i++) {
        s1 += s[i];
    }
	s1 = s1 * 4;
	printf("PI is %lf\n", s1);
    double t2 = omp_get_wtime();
    double t3 = t2 - t1;
    printf("Time is %lf\n", t3);
    return 0;
}


