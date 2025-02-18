#include <omp.h>
#include <stdio.h>

int main()
{
	double t1 = omp_get_wtime();
	int x[100000];
	int y[100000];
	int z[100000];
	int n = omp_get_num_threads();
	printf("%d\n\n", n);
	omp_set_num_threads(3);
	#pragma omp parallel
	{
		if(omp_get_thread_num() == 0)
		{
			for(int i = 0; i < 100000; i++)
			{
                        x[i] = i*3 + i*i/(i + 1);
                }

		}
		if(omp_get_thread_num() == 1)
                {
			for(int i = 0; i < 100000; i++)
                        {
                        y[i] = 1-i;
                }

                }
		if(omp_get_thread_num() == 2)
                {
			for(int i = 0; i < 100000; i++)
			{
                        z[i] = x[i] * y[i]/(x[i] + y[i]);
                }

                }
	}

//
//	for(int i = 0; i < 100000; i++)
//                {
//                        x[i] = i*3 + i*i/(i + 1);
//			y[i] = 1-i;
//			z[i] = x[i] * y[i]/(x[i] + y[i]);
//                }
//
	double t2 = omp_get_wtime();
	double t3 = t2 - t1;
	printf("%lf\n", t3);
	return 0;
}
