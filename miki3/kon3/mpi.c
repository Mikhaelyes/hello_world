#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {
 
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
    int m0 = M / argc;
    u[cen][0] = 10000;
    u[cen-1][0] = 10000;
    u[cen+1][0] = 10000; 
    for(j = 0; j < N - 1; j++) {    //n
        MPI_Init(&argc, &argv);
        double t1 = MPI_Wtime();
        int rank = 0; 
        int size = 0;
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        if(rank == 0)
        { 
            int L0 = 0;
            if(rank == 0) L0 = 1;
            for(i = rank * m0 + L0; i < (rank + 1) * m0; i++) {    //m 
                u[i][j+1] =  coef * u[i+1][j] + (1 - 2 * coef) * u[i][j] + coef * u[i-1][j];
                u[0][j+1] = 0;
                u[M - 1][j+1] = 0;
            }
        }

            }
            MPI_Bcast(x, 100, MPI_INT, 0, MPI_COMM_WORLD);
        }
        if(rank != 0)
        {
            int x[100];
            MPI_Bcast(u, 100, MPI_INT, 0, MPI_COMM_WORLD); 
            int L1 = 0;
            int k = omp_get_thread_num();
            if(k == argc) L1 = -2;
            for(i = rank * m0; i < (rank + 1) * m0 + L1; i++) {    //m 
                u[i][j+1] =  coef * u[i+1][j] + (1 - 2 * coef) * u[i][j] + coef * u[i-1][j];
                u[0][j+1] = 0;
                u[M - 1][j+1] = 0;
            }
        }
        double t2 = MPI_Wtime();
        MPI_Finalize();
        t2= t2 - t1;
        printf("%f\n", t2);
    }

    return 0;
}


