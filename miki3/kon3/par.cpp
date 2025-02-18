#include <stdio.h>
#include <iostream>
#include <omp.h>

int main()
{
    int i = 0;
    int j = 0;
    int N = 50; //time
    int M = 100; //x
    int a = 1;
    double h = 2;
    double dt = 1;    
    double u[M][N];
    double t1 = omp_get_wtime();
    int cen = M / 2;
    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            u[i][j] = 0;
        }
    }
    double coef = (a * a * dt) / (h * h);
    int thr = 4;
    int m0 = M / thr;
    u[cen][0] = 10000;
    u[cen-1][0] = 10000;
    u[cen+1][0] = 10000; 
    for(j = 0; j < N - 1; j++) {    //n
        omp_set_num_threads(thr);
        #pragma omp parallel default (none) private (i) shared (coef, u, j, m0, M)
        {
            int L0 = 0;
            int L1 = 0;
            int k = omp_get_thread_num();
            if(k == 0) L0 = 1;
            if(k == 7) L1 = -2;
            for(i = k * m0 + L0; i < (k + 1) * m0 + L1; i++) {    //m 
                u[i][j+1] =  coef * u[i+1][j] + (1 - 2 * coef) * u[i][j] + coef * u[i-1][j];
                u[0][j+1] = 0;
                u[M - 1][j+1] = 0;
            }
        }
    }    
    for(i = 0; i < M; i++) {
        std::cout <<u[i][N-1] <<"\n";
    }
    double t2 = omp_get_wtime();
    double t3 = t2 - t1;
    std::cout <<"\n" <<"Time is" <<t3 <<"\n";
    return 0;
}

