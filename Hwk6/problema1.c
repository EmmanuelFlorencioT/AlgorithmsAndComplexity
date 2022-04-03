#include <stdio.h>

int min(int a, int b);
int copy(int origin[], int dest[], int n);
int problema1(int n, int k);

int main(){
    int n, k;
    n = 10;
    k = 5;
    printf("Binomial Coefficient for n = %d & k = %d is %d\n", n, k,  problema1(n, k));
}

int min(int a, int b){
    if(a < b)
        return a;
    if(a > b)
        return b;
    return a;
}

int copy(int origin[], int dest[], int n){
    int i;
    for(i=0; i < n; i++)
        dest[i] = origin[i];
}

int problema1(int n, int k){
    int i, j, res[k+1], aux[k+1];

    for(i=0; i <= n; i++){
        for(j=0; j <= min(i, k); j++){
            if(j == 0 || j == i)
                res[j] = 1;
            else
                res[j] = aux[j-1] + aux[j];
        }
        copy(res, aux, min(i, k)+1);
    }
    return res[k];
}