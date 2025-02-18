#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>
#include <malloc.h>

int main (int argc, char *argv[]) {
    int commsize, my_rank;
 
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Status status;

    MPI_Request request;


    int M = 11;
    int M1 = M-1;
    float M2 = (M1);
    int K = 11;
    int K1 = K-1;
    float K2 = (K1);
    int k, m;
    float (*R) = malloc(M * sizeof *R);    //x
    float V[K];    //t
    float (*f)[K] = malloc(M * sizeof *f);
    float (*u)[K] = malloc(M * sizeof *u);
    float dx = 1 / M2;
    float tau = 1 / K2;
    float a = 0.5;

    double Starttime, Endtime, time;


    //Iniitialisation functions
    for(m = 0; m < M; m++) {
        R[m] = m * dx;
    }
    for(k = 0; k < K; k++) {
        V[k] = 0; //k * tau;
    } 
    for(m = 0; m < M; m++) {
        for(k = 0; k < K; k++) {
            f[m][k] = 0; //(m * dx) * (k * tau);
        } 
    }
    for(m = 0; m < M; m++) {
        for(k = 0; k < K; k++) {
            if(m == 0) {
                u[m][k] = V[k];
            }
            if(k == 0) {
                u[m][k] = R[m];
            }
            if((m != 0) && (k != 0)) {
                u[m][k] = 0;
            }
        } 
    }

    
        //core

    if(my_rank == 0) {

        Starttime = MPI_Wtime();

        for(k = 0; k <= K - 2; k++) {
            for(m = 1; m < M; m++) {
                if(m == M - 1) {
                    u[m][k+1] = tau * f[m][k] - (u[m][k] - u[m-1][k]) * a * tau / dx + u[m][k];  
                }
                else {
                    u[m][k+1] = (u[m+1][k] + u[m-1][k])/2 + tau * f[m][k] - (u[m+1][k] - u[m-1][k]) * (a * tau) / (2 * dx);
                }
            }
        }
        Endtime = MPI_Wtime();
    

        //output end
        printf("Result of consistent program\n");
        for(k = K - 1; k >= 0; k--) {
            for(m = 0; m < M; m++) {
                printf("%f  ", u[m][k]);
            }
            printf("\n");
        }
        printf("\n");
    
        time = Endtime - Starttime;
        printf("\nInitial sequential program time is %lf\n\n", time);
    }



    MPI_Finalize(); 
}
