#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50
#define RANG_MAX 200

int may[N/2];
int men[N/2];

void fillArr(int input[], int n, int range);
void printArr(int input[], int n);
void problema6(int input[], int n);
void findMayMen(int input[], int n, int *indexMay, int *indexMen);
void erase(int arr[], int n, int index);


int main(){
    int S[N];

    fillArr(S, N, RANG_MAX);
    printArr(S, N);
    problema6(S, N);
    printf("\nThe arrays are:");
    printf("\nA: ");
    printArr(may, N/2);
    printf("\nB: ");
    printArr(men, N/2);
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

void problema6(int input[], int n){
    int i, idMay, idMen, cont = 0;

    for(i = n; i > 0; i-=2){
        findMayMen(input, i, &idMay, &idMen);
        may[cont] = input[idMay];
        men[cont] = input[idMen];
        cont++;
        if(idMay > idMen){
            erase(input, i, idMay);
            erase(input, i-1, idMen);
        }
        else{
            erase(input, i, idMen);
            erase(input, i-1, idMay);
        }
    }
}

void findMayMen(int input[], int n, int *indexMay, int *indexMen){
    int i, sMay, sMen;

    sMay = sMen = input[0];
    *indexMay = *indexMen = 0;
    for(i = 1; i<n; i++){
        if(sMay < input[i]){
            sMay = input[i];
            *indexMay = i;
        }
        if(sMen > input[i]){
            sMen = input[i];
            *indexMen = i;
        }
    }
}

void erase(int arr[], int n, int index){
    int i;

    for(i=index; i<n-1; i++){
        arr[i] = arr[i+1];
    }
}