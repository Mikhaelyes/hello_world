#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

const int ISIZE = 1000;
const int JSIZE = 1000;

long int clk()
{
  timespec time;
  clock_gettime(CLOCK_MONOTONIC, &time);
  long int time_ms = time.tv_sec * 1000 + time.tv_nsec / 1000000;
  return time_ms;
}

int main(int argc, char **argv)
{
    double** a = new double*[ISIZE];

    for (int i = 0; i < ISIZE; i++)
    {
        a[i] = new double[JSIZE];
        for (int j = 0; j < JSIZE; j++)
            a[i][j] = 10 * i + j;
    }

    long start_time = clk();

    for (int i = 0; i < ISIZE - 3; i++)
    {
        for (int j = 4; j < JSIZE; j++)
            a[i][j] = sin(0.04 * a[i + 3][j - 4]);
    }

    printf("Linear: %ld mcs\n", clk() - start_time);

    FILE* ff = fopen("result.txt","w");

    for(int i = 0; i < ISIZE; i++)
    {
        for (int j = 0; j < JSIZE; j++)
            fprintf(ff,"%f ",a[i][j]);

        fprintf(ff,"\n");
    }

    fclose(ff);
}
