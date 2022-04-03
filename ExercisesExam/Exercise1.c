#include<stdio.h>

#define N 10

void printArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
}

void keepSeries(int n, int m, int res[]){
    int i;

    for(i=0;i<(m-n)-1;i++)
        res[i]=(n+1)+i;
}

void keepSeriesW(int n, int m, int res[], int w){
    int i;

    for(i=0;i<((m-n)/2)-1;i++){
        res[i]=(n+w)+i*w;
    }
}

int main(){
    int n=5, m=13, w=1,  arr[N];

    keepSeries(n, m, arr);
    printArr(arr, (m-n)-1);
    printf("\n");
    keepSeriesW(n, m, arr, w);
    printArr(arr, (m-n)/w-1);
}