// No copyright. Vladislav Aleinik, 2021
#include <mpi.h>

#include "stdlib.h"
#include "stdio.h"

#include "math.h"

//=====================
// Equation parameters 
//=====================

double initial_condition(double x)
{
	return sin(10.0 * x);
}

double boundary_condition(double t)
{
	return t * sin(2.0 * t);
}

double perturbation(double x, double t)
{
	return 0.00;
}

const double TRANSFER_SPEED = 0.01;

//================================
// Differential scheme parameters 
//================================

const unsigned NUM_T_STEPS = 10000;
const unsigned NUM_X_STEPS = 1000;

const double T_STEP = 0.001;
const double X_STEP = 0.001;

// Rectangle scheme cell computation: 
double compute_cell(double left, double prev, double left_prev, double perturbation)
{
	return (perturbation - (-prev + left - left_prev)/(2 * T_STEP)
	                     - (+prev - left - left_prev)/(2 * X_STEP) * TRANSFER_SPEED) /
	       (1/(2 * T_STEP) + TRANSFER_SPEED/(2 * X_STEP));
}

//==================
// Main computation 
//==================

int main(int argc, char* argv[])
{
	// Print usage:
	if (argc != 1)
	{
		fprintf(stderr, "Usage: transfer_equation\n");
		exit(EXIT_FAILURE);
	}

	//================
	// Initialize MPI 
	//================

	MPI_Init(&argc, &argv);

	// Get MPI node rank:
	int rank = 0;
	if (MPI_Comm_rank(MPI_COMM_WORLD, &rank) != MPI_SUCCESS)
	{
		fprintf(stderr, "Unable to get communication rank\n");
		exit(EXIT_FAILURE);
	}

	// Get number of MPI nodes:
	int num_proc = 0;
	if (MPI_Comm_size(MPI_COMM_WORLD, &num_proc) != MPI_SUCCESS)
	{
		fprintf(stderr, "Unable to get number of MPI processes\n");
		exit(EXIT_FAILURE);
	}

	//====================
	// Allocate resources 
	//====================

	unsigned  left_x_step = NUM_X_STEPS * (rank + 0) / num_proc;
	unsigned right_x_step = NUM_X_STEPS * (rank + 1) / num_proc;

	unsigned num_local_x_steps = right_x_step - left_x_step;
	
	double* local_x_steps_cur  = (double*) calloc(num_local_x_steps, sizeof(double));
	double* local_x_steps_prev = (double*) calloc(num_local_x_steps, sizeof(double));
	if (local_x_steps_cur == NULL || local_x_steps_prev == NULL)
	{
		fprintf(stderr, "Unable to allocate memory for local steps\n");
		exit(EXIT_FAILURE);
	}

	//=============
	// Start timer 
	//=============

	double start = MPI_Wtime();

	//===========================
	// Compute initial condition 
	//===========================

	for (unsigned local_x_step = 0; local_x_step < num_local_x_steps; ++local_x_step)
	{
		local_x_steps_prev[local_x_step] = initial_condition((left_x_step + local_x_step) * X_STEP);
	}

	//====================================
	// Computation && communication cycle 
	//====================================
	
	double boundary_left_prev = initial_condition((left_x_step - ((rank == 0)? 0 : 1) ) * X_STEP);
	double boundary_left_cur  = 0.0;

	for (unsigned cur_t_step = 1; cur_t_step < NUM_T_STEPS; ++cur_t_step)
	{
		// Left boundary condition:
		// (rank == 0) => compute border condition
		// (rank != 0) => recieve cell from left neighbour
		if (rank == 0)
		{
			boundary_left_cur = boundary_condition(cur_t_step * T_STEP);

			local_x_steps_cur[0] = boundary_left_cur;
		}
		else
		{
			MPI_Status status;
			if (MPI_Recv((void*) &boundary_left_cur, 1, MPI_DOUBLE, rank - 1, cur_t_step, MPI_COMM_WORLD, &status) != MPI_SUCCESS)
			{
				fprintf(stderr, "Unable to recieve boundary cell value\n");
				exit(EXIT_FAILURE);
			}
		}

		// Perform computation:
		double left      = boundary_left_cur;
		double left_prev = boundary_left_prev;

		for (unsigned local_x_step = ((rank == 0)? 1 : 0); local_x_step < num_local_x_steps; ++local_x_step)
		{
			// Compute new cell value:
			double prev = local_x_steps_prev[local_x_step];

			double perturb = perturbation((left_x_step + local_x_step + 0.5) * X_STEP, (cur_t_step + 0.5) * T_STEP);

			local_x_steps_cur[local_x_step] = compute_cell(left, prev, left_prev, perturb);

			// Update left cell value:
			left_prev = prev;
			left      = local_x_steps_cur[local_x_step];
		}

		// Right boundary condition:
		// (rank == num_proc - 1) => do nothing
		// (rank != num_proc - 1) => send cell to right neighbour
		if (rank != num_proc - 1)
		{
			double to_send = local_x_steps_cur[num_local_x_steps - 1];

			if (MPI_Bsend((void*) &to_send, 1, MPI_DOUBLE, rank + 1, cur_t_step, MPI_COMM_WORLD) != MPI_SUCCESS)
			{
				fprintf(stderr, "Unable to send boundary cell value\n");
				exit(EXIT_FAILURE);
			}
		}

		// Update time layer:
		{
			double* tmp        = local_x_steps_cur;
			local_x_steps_cur  = local_x_steps_prev;
			local_x_steps_prev = tmp;
		}

		boundary_left_prev = boundary_left_cur;
	}

	//================
	// Gather results 
	//================

	double* results;

	if (rank != 0)
	{
		// Send the results:
		if (MPI_Gather(local_x_steps_prev, num_local_x_steps, MPI_DOUBLE, // send options
		               local_x_steps_prev, num_local_x_steps, MPI_DOUBLE, // recv options
		               0, MPI_COMM_WORLD) != MPI_SUCCESS)
		{
			fprintf(stderr, "Unable to gather the computation results\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (num_proc != 1)
	{
		results = (double*) calloc(NUM_X_STEPS, sizeof(double));
		if (results == NULL)
		{
			fprintf(stderr, "Unable to allocate memory for computation results\n");
			exit(EXIT_FAILURE);
		}

		// Recieve the results:
		if (MPI_Gather(local_x_steps_prev, num_local_x_steps, MPI_DOUBLE, // send options
		                          results, num_local_x_steps, MPI_DOUBLE, // recv options
		               0, MPI_COMM_WORLD) != MPI_SUCCESS)
		{
			fprintf(stderr, "Unable to gather the computation results\n");
			exit(EXIT_FAILURE);
		}
	}
	
	//==============
	// Finish timer 
	//==============

	if (rank == 0)
	{
		double finish = MPI_Wtime();

		printf("The computation took %lf sec\n", finish - start);
	}

	//==================
	// Printout results 
	//==================

	if (rank == 0 && num_proc != 1)
	{
		for (unsigned x = 0; x < (NUM_X_STEPS / num_proc) * num_proc; ++x)
		{
			printf("%f, %f\n", x * X_STEP, results[x]);
		}

		free(results);
	}

	if (rank == 0 && num_proc == 1)
	{
		for (unsigned x = 0; x < (NUM_X_STEPS / num_proc) * num_proc; ++x)
		{
			printf("%f, %f\n", x * X_STEP, local_x_steps_prev[x]);
		}
	}

	//================
	// Free resources 
	//================

	// Shutdown MPI:
	MPI_Finalize();

	// Free allocated memory:
	free(local_x_steps_cur);
	free(local_x_steps_prev);

	return EXIT_SUCCESS;
}
