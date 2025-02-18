#include <omp.h>
#include <stdio.h>
#include <math.h>

int main()
{
	double x = 0;
    double s1 = 0;
	int n = 100000000;
    int n0 = 0;
    int i = 0;
    int j = 0;
	double dx = 1.0 /n;
    double t1 = omp_get_wtime();
    int k = 1;
	printf("Threads are %d\n Zoom is %d\n",k, n);
    double s[k];
    for(i = 0; i < k; i++) {
        s[i] = 0;
    }
    omp_set_num_threads(k);
    #pragma omp parallel
    {
	    for(int j = 0; j < k; j++)
	    {
     	    if(omp_get_thread_num() == j)
            {
                int n0 = n / k;
             	for(int i = j * n0; i < (j + 1) * n0; i++) {
                    x = i * dx;
                	s[j] += dx * sqrt(1 - x * x);
           		}
       		}
    	}
        #pragma omp barrier
	}

    for(i = 0; i < k; i++) {
        s1 += s[i];
    }
	s1 = s1 * 4;
	printf("PI is %lf\n", s1);
    double t2 = omp_get_wtime();
    double t3 = t2 - t1;
    printf("Time is %lf\n", t3);
    return 0;
}

