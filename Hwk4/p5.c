#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 1024
#define RANG_MAX 10000

int S[N];

void fillArr(int input[], int n, int range);
void printArr(int input[], int n);
void problema5(int n);
void merge(int low, int mid, int high);

int main(){
    fillArr(S, N, RANG_MAX);
    printArr(S, N);
    problema5(N);
    printf("Array sorted:\n");
    printArr(S, N);
}


void fillArr(int input[], int n, int range){
    int i;
    srand(time(NULL));
    for(i = 0; i < n; i++)
        input[i] = rand() % range;
}

void printArr(int input[], int n){
    int i;

    for(i=0;i<n;i++)
        printf("%4d\t", input[i]);
    printf("\n");
}

void problema5(int n){
    int i, j, low, mid, high;

    //Ciclo que va a determinar el tamaño de los grupos
    for(i=1; i<n; i*=2){
        //Ciclo para ir tomando dos grupos y hacerles merge
        // printf("i = %d\n", i);
        for(j=0; j<n; j+=(2*i)){
            // printf("j = %d\n", j);
            low = j;
            high = j + (2*i) - 1;
            mid = low + i - 1;
            // printf("low %d-esimo = %d\n", j, low);
            // printf("mid %d-esimo = %d\n", j, mid);
            // printf("high %d-esimo = %d\n", j, high);
            merge(low, mid, high);
        }
    }
}

void merge(int low, int mid, int high){
    int i, j, k;
    int tam1 = mid - low + 1;
    int tam2 =  high - mid;
    
    //Arreglos de división
    int U[tam1], V[tam2];
    for (i = 0; i < tam1; i++)
        U[i] = S[low + i];
    for (j = 0; j < tam2; j++)
        V[j] = S[mid + 1+ j];
 
    //Proceso de merge
    i = j = 0;
    k = low;
    while (i < tam1 && j < tam2){
        if (U[i] <= V[j]){
            S[k] = U[i];
            i++;
        }
        else{
            S[k] = V[j];
            j++;
        }
        k++;
    }
    //Merge los elementos restantes
    while (i < tam1){
        S[k] = U[i];
        i++;
        k++;
    }
    while (j < tam2){
        S[k] = V[j];
        j++;
        k++;
    }
}