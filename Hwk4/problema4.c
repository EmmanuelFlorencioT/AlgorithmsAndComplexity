#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 100
#define RANG_MAX 105


void fillArr(int input[], int n, int range);
void printArr(int input[], int n);
void swap(int *izq, int *der);
void qSort(int arr[], int izq, int der);
void quickSort(int arr[]);
int problema4(int input[], int low, int high, int x);

int main(){
    int res, num, arr[N];
    srand(time(NULL));
    num = rand()%RANG_MAX;
    fillArr(arr, N, RANG_MAX);
    quickSort(arr);
    res = problema4(arr, 0, N, num);
    printArr(arr, N);
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

int problema4(int input[], int low, int high, int x){
    int midl, midh;

    if((high-low)<3) //Casos base
        switch(high-low){
            case -1: //Se desfasaron los indices
                return -1;

            case 0: //Se tiene 1 elemento
                if(x == input[low])
                    return low;
                return -1;

            case 1: //Se tienen 2 elementos
                if(x == input[low])
                    return low;
                else
                    if(x == input[high])
                        return high;
                    return -1;

            case 2: //Se tienen 3 elementos
                if(x == input[low])
                    return low;
                else
                    if(x == input[high])
                        return high;
                    else
                        if(x == input[low+1])
                            return low+1;
                        return -1;
        }
    else{ //Solamente se pueden dividir grupos de 4 o más elementos
        midl = low + floor((high-low)/3);
        midh = low + 2 * floor((high-low)/3);
        if(x == input[midl])
            return midl;
        else
            if(x < input[midl])
                return problema4(input, low, midl-1, x);
            else
                if(x == input[midh])
                    return midh;
                else
                    if(x > input[midh])
                        return problema4(input, midh+1, high, x);
                    else
                        return problema4(input, midl+1, midh-1, x);
    }
}