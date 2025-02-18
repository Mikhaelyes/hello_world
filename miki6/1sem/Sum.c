#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if(argc > 2) {
        printf("Error too many arguments\n");
        exit(1);
    }

    int V, n, i, k, l, K0, K1;
    int commsize, my_rank;
//    scanf("%d", &V);

    int N = atoi(argv[1]);

    if( N <= 0) {
        printf("Error invalid value\n");
        exit(2);
    }  
 
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &commsize);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Status status;

    float S[commsize];
    float S0;
    S0 = 0;

    n = (int) N / commsize;

   for(i = 0; i < commsize; i++) {
        S[i] = 0;

        if(i == my_rank) {
            if(i == 0) {
                K0 = 1;
            }
            else {
                K0 = i * n; 
            }
            if(i == commsize - 1) {
                K1 = N + 1 ;
            }
            else {
                K1 = n + i * n;
            }

            for(k = K0; k < K1; k++) {
                S[my_rank] += (float) 1/k;
//                printf("ff %d %f \n", i, S[my_rank]);
            }
//            printf("dd  %f \n", S[my_rank]);

            if(my_rank != 0) {
                MPI_Send(&S[my_rank], 1, MPI_FLOAT, 0, 1, MPI_COMM_WORLD);
            }
            else {
                for(l = 1; l < commsize; l++) {
                    MPI_Recv(&S[l], 1, MPI_FLOAT, l, 1, MPI_COMM_WORLD, &status);
                    printf("%f \n", S[l]);
                }
                for(l = 0; l < commsize; l++) {
                    S0 += S[l];
                }
                printf("Num: %f \n", S0);
            }
        }
    }

    MPI_Finalize();
    printf("1\n");
}
