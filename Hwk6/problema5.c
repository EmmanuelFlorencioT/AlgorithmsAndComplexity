#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 9
#define SZ 175

void createGraph(int graph[SZ][SZ], int n);
void printGraph(int graph[SZ][SZ], int n);
void copyMatrix(int origin[SZ][SZ], int dest[SZ][SZ], int n);
int min(int a, int b);
void problema5(int W[SZ][SZ], int D[SZ][SZ], int P[SZ][SZ], int n);

int main(){
    int g[SZ][SZ], res[SZ][SZ], path[SZ][SZ], n = 10, duration;
    time_t tPrev, tPost;

    /* createGraph(g, n);
    printf("W:\n");
    printGraph(g, n);
    printf("\n\n");
    problema5(g, res, path,  n);
    printf("D:\n");
    printGraph(res, n);
    printf("\n\n");
    printf("P:\n");
    printGraph(path, n); */

    createGraph(g, SZ);
    tPrev = clock();
    problema5(g, res, path, SZ);
    tPost = clock();
    duration = tPost - tPrev;
    printf("The duration for Floyd's algorithm for n = %d is %d ms", SZ, duration);
}

void createGraph(int graph[SZ][SZ], int n){
    int i, j;

    srand(time(NULL));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(j == i)
                graph[i][j] = 0;
            else
                graph[i][j] = rand() % RANGE + 1;
}

void printGraph(int graph[SZ][SZ], int n){
    int i, j;

    printf("  ");
    for(i=0; i<n; i++)
        printf("___%d", i);
    printf("\n");

    for(i=0; i<n; i++){
        printf("%d|", i);
        for(j=0; j<n; j++)
            printf("%4d", graph[i][j]);
        printf("\n");
    }
}

void copyMatrix(int origin[SZ][SZ], int dest[SZ][SZ], int n){
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            dest[i][j] = origin[i][j];
}

void problema5(int W[SZ][SZ], int D[SZ][SZ], int P[SZ][SZ], int n){
    int i, j, k;
    //Inicializacion matriz P
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            P[i][j] = 0;
    copyMatrix(W, D, n);
    for(k=0; k<n; k++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(D[i][k] + D[k][j] < D[i][j]){
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
}