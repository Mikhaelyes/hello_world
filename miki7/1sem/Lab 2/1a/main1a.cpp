#include <cstdio>
#include <cmath>
#include <omp.h>
#include <iostream>

#define ISIZE 10000
#define JSIZE 10000

void writeArray(double **a, char *name)
{
    FILE *ff;
    ff = fopen(name, "w");
    for (int i = 0; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE; j++)
            fprintf(ff, "%.7e ", a[i][j]);
        fprintf(ff,"\n");
    }
    fclose(ff);
}

void tasK(double **a)
{
    for (int i = 0; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE; j++)
            a[i][j] = 10*i +j;
    }

    for (int i = 1; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE - 1; j++)
            a[i][j] = sin(2 * a[i - 1][j + 1]);
    }
}

void taskParallel(double **a, int nThreads)
{
//#pragma omp parallel for num_threads(nThreads)
    for (int i = 0; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE; j++)
            a[i][j] = 10*i +j;
    }

    for (int i = 1; i < ISIZE; i++)
    {
#pragma omp parallel for num_threads(nThreads)
        for (int j = 0; j < JSIZE - 1; j++)
            a[i][j] = sin(2 * a[i - 1][j + 1]);
    }
}

int main(int argc, char **argv)
{
    double start = 0., finish = 0.;

    double **a = (double **)calloc(ISIZE, sizeof(*a));
    for (int i = 0; i < JSIZE; i++)
        a[i] = (double *)calloc(JSIZE, sizeof(double));

    // Timings
    FILE *ff;
    ff = fopen("times1a.txt", "w");

    // Run not parallel
    start = omp_get_wtime();
    tasK(a);
    finish = omp_get_wtime();
    std::cout << "Sequential, time: " << finish - start << "s.\n";
    fprintf(ff, "%d\t%.4e\n", 1, finish - start);

    // Run parallel programs
    for (int nThreads = 1; nThreads <= 12; nThreads += 1)
    {
        start = omp_get_wtime();
        taskParallel(a, nThreads);
        finish = omp_get_wtime();
        std::cout << "Parallel, nThreads = " << nThreads << ", time: " << finish - start << "s.\n";
        fprintf(ff, "%d\t%.4e\n", nThreads, finish - start);

    }
    fclose(ff);

    for (int i = 0; i < JSIZE; i++)
        free(a[i]);
    free(a);

    return 0;
}
