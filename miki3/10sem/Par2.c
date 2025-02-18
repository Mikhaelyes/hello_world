#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv) {

	MPI_Init(&argc, &argv);
    double t1 = MPI_Wtime();
	int rank = 0; 
	int size = 0;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0)
	{
		int x[100];
        for(int i = 0; i < 100; i++) {
            x[i] = i;
        }
		MPI_Bcast(x, 100, MPI_INT, 0, MPI_COMM_WORLD);
	}
	if(rank != 0)
    {
        int x[100];
        MPI_Bcast(x, 100, MPI_INT, 0, MPI_COMM_WORLD);
        printf("%d: %d\n", rank, x[1]);
    }
    double t2 = MPI_Wtime();
	MPI_Finalize();
    t2= t2 - t1;
    printf("%f\n", t2);

	return 0;
}

