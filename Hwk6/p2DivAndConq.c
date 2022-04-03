#include <stdio.h>
#include <math.h>
#include <time.h>

double p2DivAndConq(int n, int k);

int main(){
    time_t tPrev, tPost;
    int duration, n, k;
    double coeff;
    n = 39;
    k = 19; //For this computer, this is the limit
    tPrev = clock();
    coeff = p2DivAndConq(n, k);
    tPost = clock();
    duration = tPost - tPrev;
    printf("Binomial Coefficient for n = %d & k = %d is %.0f\n", n, k, coeff);
    printf("The duration for values n = %d & k = %d is %d ms\n", n, k, duration);
}

double p2DivAndConq(int n, int k){
    if(k == 0 || k == n)
        return 1;
    else
        return p2DivAndConq(n - 1, k) + p2DivAndConq(n - 1, k - 1);
}