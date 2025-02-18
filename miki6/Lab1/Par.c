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


    int M = 9;
    int M1 = M-1;
    float M2 = (M1);
    int K = 9;
    int K1 = K-1;
    float K2 = (K1);
    int k, m;
    float (*R) = malloc(M * sizeof *R);    //x
    float V[k];    //t
    float (*f)[K] = malloc(M * sizeof *f);
    float (*u)[K] = malloc(M * sizeof *u);
    float dx = 1 / M2;
    float tau = 1 / K2;
    float a = 2;

    double Starttime, Endtime, time, Starttime1, Endtime1, time1;


    //Iniitialisation functions
    for(m = 0; m < M; m++) {
        R[m] = m * dx;
    }
    for(k = 0; k < K; k++) {
        V[k] = k * tau;
    } 
    for(m = 0; m < M; m++) {
        for(k = 0; k < K; k++) {
            f[m][k] = (m * dx) * (k * tau);
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

    

///////////////////////////////////
    //start of paraprog
///////////////////////////////////

    int i, n, K0;
    float (*U_par)[commsize][K] = malloc (M * sizeof *U_par);

    for(m = 0; m < M; m++) {
        for(k = 0; k < K; k++) {
            for(i = 0; i < commsize; i++) {
                if(m == 0) {
                    U_par[m][i][k] = V[k];
                    u[m][k] = V[k];
                }
                if(k == 0) {
                    U_par[m][i][k] = R[m];
                    u[m][k] = R[m];
                }
                if((m != 0) && (k != 0)) {
                    U_par[m][i][k] = 0;
                    u[m][k] = 0;
                }
            }
        } 
    }
 
    
    n = (int) M /commsize;


    for(i = 0; i < commsize; i++) {

        if(i == my_rank) {
            if(i == 0) {
                K0 = 1;
            }
            else {
                K0 = i * n;  
            }

            if(i == commsize - 1) {
                K1 = M ; 
            }
            else {
                K1 = n + i * n;
            }
        }
    }
    if(my_rank == 0) {
        Starttime1 = MPI_Wtime();
    }
    
    //core parprog 
    for(k = 0; k <= K - 1; k++) {
         for(i = 0; i < commsize; i++) {
            if(my_rank == i) {
                for(m = K0; m < K1; m++) {
                    if(m == M - 1) {
                        U_par[m][i][k+1] = tau * f[m][k] - (U_par[m][i][k] - U_par[m-1][i][k]) * a * tau / dx + U_par[m][i][k];  
                    }
                    else {
                        U_par[m][i][k+1] = (U_par[m+1][i][k] + U_par[m-1][i][k])/2 + tau * f[m][k] - (U_par[m+1][i][k] - U_par[m-1][i][k]) * (a * tau) / (2 * dx);
                    }            
                }
                if(i != commsize - 1) {
                    MPI_Send(&U_par[K1-1][i][k+1], 1, MPI_FLOAT, i+1, 2, MPI_COMM_WORLD);
                }
                if(i != 0) {
                    MPI_Recv(&U_par[K0-1][i][k+1], 1, MPI_FLOAT, i-1, 2, MPI_COMM_WORLD, &status);
                }
                if(i != 0) {
                    MPI_Send(&U_par[K0][i][k+1], 1, MPI_FLOAT, i-1, 2, MPI_COMM_WORLD);
                }
                if(i != commsize - 1) {
                    MPI_Recv(&U_par[K1][i][k+1], 1, MPI_FLOAT, i+1, 2, MPI_COMM_WORLD, &status);
                }
            }
        }
    }


    if(my_rank != 0) {
        MPI_Send(&U_par[0][my_rank][0], K * M, MPI_FLOAT, 0, 1, MPI_COMM_WORLD); 
    }

    else {
        for(i = 1; i < commsize; i++) {
            MPI_Recv(&U_par[0][i][0], K * M, MPI_FLOAT, i, 1, MPI_COMM_WORLD, &status);
        }

        for(k = 1; k <= K - 1; k++) {
            for(i = 0; i < commsize; i++) {
                if(i == 0) {
                    K0 = 1;
                }
                else {
                    K0 = i * n;  
                }

                if(i == commsize - 1) {
                    K1 = M ; 
                }
                else {
                    K1 = n + i * n;
                }

                for(m = K0; m < K1; m++) { 
                    u[m][k] += U_par[m][i][k];
                }
            } 
        }
 
        printf("Result of paralell program\n");
        for(k = K - 1; k >= 0; k--) {
            for(m = 0; m < M; m++) {
                printf("%f  ", u[m][k]);
            }
            printf("\n");
        }
        printf("\n");
        Endtime1 = MPI_Wtime();
        time1 = Endtime1 - Starttime1;
        printf("\nInitial parallel program time is %lf\n\n", time1);
 
    }

    MPI_Finalize(); 
}
