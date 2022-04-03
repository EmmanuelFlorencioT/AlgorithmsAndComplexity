#include<stdio.h>

#define N 10

void printArr(int arr[], int n);
void separateArr(int arr[], int n, int even[], int nonEven[]);
void separateArrMax(int arr[], int n, int even[], int nonEven[], int *maxEven, int *maxNon);


int main(){
    int n, arr[]={1, 2, 3, 4, 5, 6, 7, 8};
    int even[N], non[N], maxE, maxN;

    separateArrMax(arr, 8, even, non, &maxE, &maxN);
    printf("Even:\n");
    printArr(even, 4);
    printf("\n\n");
    printf("Non:\n");
    printArr(non, 4);
    printf("\n\n");
    printf("Max Even: %d\n", maxE);
    printf("Max Non: %d\n", maxN);
}

/*El tipo de complexidad de ambos algoritmos es everycase, ya que
en ambos casos, se deben hacer recorridos completos del arreglo sin importar
las condiciones*/

void printArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
}

void separateArr(int arr[], int n, int even[], int nonEven[]){
    int i, iEven = 0, iNonEven = 0;

    for(i=0; i<n; i++)
        if(arr[i]%2 == 0){
            even[iEven] = arr[i];
            iEven++;
        } else {
            nonEven[iNonEven] = arr[i];
            iNonEven++;
        }
}

void separateArrMax(int arr[], int n, int even[], int nonEven[], int *maxEven, int *maxNon){
    int i, iEven=0, iNonEven=0;

    for(i=0; i<n; i++)
        if(arr[i]%2 == 0){
            even[iEven] = arr[i];
            iEven++;
        } else {
            nonEven[iNonEven] = arr[i];
            iNonEven++;
        }

    *maxEven = even[0];
    *maxNon = nonEven[0];
    for(i=1; i<=iEven;i++)
        if(even[i] > *maxEven)
            *maxEven = even[i];
    
    for(i=1; i<iNonEven; i++)
        if(nonEven[i]>*maxNon)
            *maxNon = nonEven[i];
}