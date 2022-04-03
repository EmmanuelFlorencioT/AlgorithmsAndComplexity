#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 25

void llenaArr(int arr[], int n, int range);
void imprimeArr(int arr[], int n);
int problema1(int input[], int n);


int main(){
    int arr[SIZE];
    int n=25;

    llenaArr(arr, n, 100);
    imprimeArr(arr, n);
    printf("Dato mayor del arreglo: %d", problema1(arr, n));
}

void llenaArr(int arr[], int n, int range){
    int i;

    srand(time(NULL));
    for(i=0;i<n;i++){
        arr[i]=rand()%range;
    }
}

void imprimeArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
}

int problema1(int input[], int n){
    int i, sMay=input[0];

    for(i=1;i<n;i++)
        if(input[i]>sMay)
            sMay=input[i];

    return(sMay);
}
