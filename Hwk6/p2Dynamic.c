#include <stdio.h>
#include <math.h>
#include <time.h>

int min(int a, int b);
double p2Dynamic(int n, int k);

int main(){
    time_t tPrev, tPost;
    int duration, n, k;
    double coeff;
    n = 720;
    k = 359; //For this computer this is the limit
    tPrev = clock();
    coeff = p2Dynamic(n, k);
    tPost = clock();
    duration = tPost - tPrev;
    printf("Binomial Coefficient for n = %d & k = %d is %.0f\n", n, k, coeff);
    printf("The duration for values n = %d & k = %d is %d ms\n", n, k, duration);
}

int min(int a, int b){
    if(a < b)
        return a;
    if(a > b)
        return b;
    return a;
}

double p2Dynamic(int n, int k){
    int i, j;
    double B[n+1][k+1];

    for(i=0; i <= n; i++)
        for(j=0; j <= min(i, k); j++)
            if(j == 0 || j == i)
                B[i][j] = 1;
            else
                B[i][j] = B[i-1][j-1] + B[i-1][j];
    return B[n][k];
}