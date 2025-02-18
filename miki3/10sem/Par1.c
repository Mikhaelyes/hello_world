#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {

	MPI_Init(&argc, &argv);
    double t1 = MPI_Wtime();
	int rank = 0; 
	int size = 0;
    MPI_Request request;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0)
	{
        int x[100];
		for(int i = 0; i < 100; i++) {
            x[i] = i;
        }
        for(int j = 0; j < 12; j++) {
		    MPI_Isend(x, 100, MPI_INT, j, 1, MPI_COMM_WORLD, &request);
            }
	}
	if(rank != 0)
    {
        int x[100];
        MPI_Irecv(x, 100, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &request);
        MPI_Wait(&request, MPI_STATUS_IGNORE);
        printf("%d: %d\n", rank, x[1]);
    }
    double t2 = MPI_Wtime();
    t2 -= t1;
    printf("%f\n", t2);
	MPI_Finalize();
    

	return 0;
}
