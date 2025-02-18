#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>

int main (int argc, char *argv[]) {
    int commsize, my_rank;
 
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Status status;

    MPI_Request request;


    int M = 30000;
    int M1 = M-1;
    float M2 = (M1);
    int K = 3;
    int K1 = K-1;
    float K2 = (K1);
    int k, m;
    float *R  = malloc(M * sizeof(float));    //x
    float V[K];    //t
    float **f = malloc(M * sizeof(float*));
    float **u  = malloc(M * sizeof(float*));

    

    for (int i= 0; i < M; ++i) {
        f[i] = (float*) malloc(K * sizeof(float));
    }

    for (int i = 0; i < M; ++i) {
	u[i] = (float*) malloc(K * sizeof(float));
    }

    float dx = 1 / M2;
    float tau = 1 / K2;
    float a = 2;

    double Starttime, Endtime, time;


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
//                printf("%f  ", u[m][k]);
            }
//            printf("\n");
        }
        printf("\n");
    
        time = Endtime - Starttime;
        printf("\nInitial sequential program time is %lf\n\n", time);
    }


///////////////////////////////////
    //start of paraprog
///////////////////////////////////

    int i, n, K0;
//    float (*U_par)[commsize][K] = malloc (M * sizeof *U_par);
//    float (**U_par)[K] = (float**) malloc (K * sizeof(float));
//    for(i = 0; i < commsize; i++) {
//        U_par[i] = (float*) malloc(K * M * sizeof(float));
//    }

    float ***U_par;
    U_par = (float ***)malloc(commsize * sizeof(float**));
    for(i = 0; i < commsize; i++) {
        U_par[i] = (float **)malloc(M * sizeof(float*));
        for(m = 0; m < M; m++) {
            U_par[i][m] = (float *)malloc(K * sizeof(float));
        }
    }

    for(m = 0; m < M; m++) {
        for(k = 0; k < K; k++) {
            for(i = 0; i < commsize; i++) {
                if(m == 0) {
                    U_par[i][m][k] = V[k];
                    u[m][k] = V[k];
                }
                if(k == 0) {
                    U_par[i][m][k] = R[m];
                    u[m][k] = R[m];
                }
                if((m != 0) && (k != 0)) {
                    U_par[i][m][k] = 0;
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

    Starttime = MPI_Wtime();
    
    //core parprog 
    for(k = 0; k <= K - 1; k++) {
         for(i = 0; i < commsize; i++) {
            if(my_rank == i) {
                for(m = K0; m < K1; m++) {
                    if(m == M - 1) {
                        U_par[i][m][k+1] = tau * f[m][k] - (U_par[i][m][k] - U_par[i][m-1][k]) * a * tau / dx + U_par[i][m][k];  
                    }
                    else {
                        U_par[i][m][k+1] = (U_par[i][m+1][k] + U_par[i][m-1][k])/2 + tau * f[m][k] - (U_par[i][m+1][k] - U_par[i][m-1][k]) * (a * tau) / (2 * dx);
                    }            
                }
                if(i != commsize - 1) {
                    MPI_Send(&U_par[i][K1-1][k+1], 1, MPI_FLOAT, i+1, 2, MPI_COMM_WORLD);
                }
                if(i != 0) {
                    MPI_Recv(&U_par[i][K0-1][k+1], 1, MPI_FLOAT, i-1, 2, MPI_COMM_WORLD, &status);
                }
                if(i != 0) {
                    MPI_Send(&U_par[i][K0][k+1], 1, MPI_FLOAT, i-1, 2, MPI_COMM_WORLD);
                }
                if(i != commsize - 1) {
                    MPI_Recv(&U_par[i][K1][k+1], 1, MPI_FLOAT, i+1, 2, MPI_COMM_WORLD, &status);
                }
            }
        }
    }


    if(my_rank != 0) {
        MPI_Send(&U_par[my_rank][0][0], K * M, MPI_FLOAT, 0, 1, MPI_COMM_WORLD); 
    }

    else {
        for(i = 1; i < commsize; i++) {
            MPI_Recv(&U_par[i][0][0], K * M, MPI_FLOAT, i, 1, MPI_COMM_WORLD, &status);
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
                    u[m][k] += U_par[i][m][k];
                }
            } 
        }
        Endtime = MPI_Wtime();
 
 
        printf("Result of paralell program\n");
        for(k = K - 1; k >= 0; k--) {
            for(m = 0; m < M; m++) {
//                printf("%f  ", u[m][k]);
            }
//            printf("\n");
        }
        printf("\n");
        time = Endtime - Starttime;
        printf("\nInitial parallel program time is %lf\n\n", time);
 
    }
    free(R);
    free(f);
    for(i = 0; i < commsize; i++) {
        for(m = 0; m < M; m++) {
            free(U_par[i][m]);
        } 
        free(U_par[i]);
    }
    free(U_par);
    
    for(i = 0; i < M; i++) { 
        free(u[i]);
    }
 
    free(u);
    MPI_Finalize(); 
}
