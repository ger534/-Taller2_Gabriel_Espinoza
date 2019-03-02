#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void saxpy(int n, float a, float x[], float y[])
{
    double start_time, run_time;
    start_time = omp_get_wtime();
    for (int i = 0; i < n; ++i)
    {
        y[i] = a * x[i] + y[i];
    }
    run_time = omp_get_wtime() - start_time;
    printf("serie: %f seconds\n",run_time);
}

void saxpyPar(int n, float a, float x[], float y[])
{
    double start_time, run_time;
    omp_set_num_threads(2);
    start_time = omp_get_wtime();
#pragma omp parallel
    {
        for (int i = 0; i < n; ++i)
        {
            y[i] = a * x[i] + y[i];
        }
    }
    run_time = omp_get_wtime() - start_time;
    printf("paralelo: %f seconds\n",run_time);
}

void llenar(float arr[],int tam){
    for(int i = 0; i < tam; i++){
        arr[i]=i;
    }
}

int main(int argc, char **argv)
{
    int m = 10.0;
    int size = 50;
    float *x =(float*) calloc(size, sizeof(float));
    float *y =(float*) calloc(size, sizeof(float));
    llenar(y,size);
    llenar(x,size);
    saxpy(size,m,x,y);
    saxpyPar(size,m,x,y);
    size = size*m;
    x = (float*) calloc(size, sizeof(float));
    y = (float*) calloc(size, sizeof(float));
    saxpy(size,m,x,y);
    saxpyPar(size,m,x,y);
    size = size*m;
    x = (float*) calloc(size, sizeof(float));
    y = (float*) calloc(size, sizeof(float));
    saxpy(size,m,x,y);
    saxpyPar(size,m,x,y);
}
