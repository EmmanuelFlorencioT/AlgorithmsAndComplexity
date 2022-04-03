#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define RANG_MAX 10000

void fillArr(int input[], int n, int range);
void printArr(int input[], int n);
void swap(int *izq, int *der);
void qSort(int arr[], int izq, int der);
void quickSort(int arr[]);
int problema2(int input[], int low, int high, int x);

int main(){
    int arr[N], res, num;
    fillArr(arr, N, RANG_MAX);
    quickSort(arr);
    printArr(arr, N);
    num = 8759;
    res = problema2(arr, 0, N-1, num);
    printf("\nThe location of the number %d is %d\n", num, res);
}

void swap(int *izq, int *der)
{
    int aux;
    aux=*izq;
    *izq=*der;
    *der=aux;
}

void quickSort(int arr[])
{
    qSort(arr, 0, N-1);
}

void qSort(int arr[], int izq, int der)
{
    int i=izq, d=der, piv;
    piv=arr[(i+d)/2];
    while(i<=d)
    {
        while(arr[i]<piv) i++;
        while(arr[d]>piv) d--;
        if(i<=d)
        {
            swap(&arr[i], &arr[d]);
            i++;
            d--;
        }
    }
    if(izq<d)
        qSort(arr, izq, d);
    if(i<der)
        qSort(arr, i, der);
}

void fillArr(int input[], int n, int range){
    int i;
    for(i = 0; i < n; i++)
        input[i] = rand() % range;
}

void printArr(int input[], int n){
    int i;

    for(i=0;i<n;i++)
        printf("%4d\t", input[i]);
    printf("\n");
}

int problema2(int input[], int low, int high, int x){
    int mid;
    mid=floor((high+low)/2);
    if(x == input[mid])
        return mid;
    if(x < input[mid])
        return problema2(input, low, mid-1, x);
    return problema2(input, mid+1, high, x);
}