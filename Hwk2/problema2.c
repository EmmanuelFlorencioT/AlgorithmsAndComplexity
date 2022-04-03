#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define SIZE 25

void imprimeArr(int arr[], int n);
int problema2(int input[], int n, int m, int **output);


int main(){
    int arr[]={16, 71, 13, 69, 34, 12, 98, 65, 83, 23, 54, 33, 66, 90, 31};
    int *resp;
    int disc=1, n=15, m=5;

    disc=problema2(arr, n, m, &resp);
    if(disc==1){
        printf("Lista de elementos:\n");
        imprimeArr(arr, n);
        printf("\nLos %d elementos menores son:\n", m);
        imprimeArr(resp, m);
        free(resp);
    }
    else
        printf("Algo salio mal:(");
}

void imprimeArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
}

int problema2(int input[], int n, int m, int **output){
    int res=0, sMen=input[0], i, j;

    *output=(int *)malloc(sizeof(int)*m);
    if(*output){
        /*Se obtiene el 1er elemento para el arreglo output*/
        for(i=1;i<n;i++)
            if(input[i]<sMen)
                sMen=input[i];
        **output=sMen;
        /*Se llena el resto del arreglo output*/
        for(j=1;j<m;j++){
            sMen=INT_MAX;
            for(i=0;i<n;i++)
                if(input[i]<sMen && input[i]>*(*output+(j-1)))
                    sMen=input[i];
            *(*output+j)=sMen;
        }
        res=1;
    }
    return(res);
}
