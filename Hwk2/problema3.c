#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 25

void llenaArr(int arr[], int n, int range);
void imprimeArr(int arr[], int n);
void problema3(int input[], int n);

int main(){
    int arr[SIZE];
    int n=20;

    llenaArr(arr, n, 100);
    imprimeArr(arr, n);
    printf("\n");
    problema3(arr, n);
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
    printf("{");
    for(i=0;i<n-1;i++)
        printf("%d, ", arr[i]);
    printf("%d", arr[n-1]);
    printf("}\t");
}

void problema3(int input[], int n){
    int i=0, j, k, l, output[5];
    
    for(i=0;i<n-3;i++){
        output[0]=input[i];
        for(j=i+1;j<n-2;j++){
            output[1]=input[j];
            for(k=j+1;k<n-1;k++){
                output[2]=input[k];
                for(l=k+1;l<n;l++){
                    output[3]=input[l];
                    imprimeArr(output, 4);
                }
            }
        }
    }
}
