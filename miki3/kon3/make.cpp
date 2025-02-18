#include <stdio.h>
#include <iostream>

int main()
{
    int i = 0;
    int j = 0;
    int N = 50; //time
    int M = 100; //x
    int a = 1;
    double h = 2;
    double dt = 1;    
    double u[M][N];
    int cen = M / 2;
    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            u[i][j] = 0;
        }
    }
    double coef = (a * a * dt) / (h * h);
    u[cen][0] = 10000000;
    u[cen-1][0] = 10000000;
    u[cen+1][0] = 10000000; 
//    for(i = 0; i < M; i++) {
//        std::cout <<u[i][10] <<"\n";
//    }
    for(j = 0; j < N - 1; j++) {    //n
        for(i = 1; i < M - 2; i++) {    //m 
            u[i][j+1] =  coef * u[i+1][j] + (1 - 2 * coef) * u[i][j] + coef * u[i-1][j];
            u[0][j+1] = 0;
            u[M - 1][j+1] = 0;
        }
    }    
    for(i = 0; i < M; i++) {
        std::cout <<u[i][49] <<"\n";
    } 
    return 0;
}
