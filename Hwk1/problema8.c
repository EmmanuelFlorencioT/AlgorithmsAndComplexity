#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

void imprimeArr(int arr[], int n);
void may_men(int input[], int n, int *may, int *men);

int main(){
    int a[]={16, 71, 13, 69, 34, 12, 98, 65, 83, 23, 54, 33, 66, 90, 31};
    int n=15, mayor, menor;

    printf("Conjunto de elementos\n");
    imprimeArr(a, n);
    may_men(a, n, &mayor, &menor);
    printf("Mayor: %d\n", mayor);
    printf("Menor: %d\n", menor);
}

void imprimeArr(int *arr, int n){
    int i;

    for(i=0;i<n;i++)
        printf("%d\t", *(arr+i));
    printf("\n");
}

void may_men(int input[], int n, int *may, int *men){
    int i, j=n, cont=0;
    int gde[SIZE], peq[SIZE];

    /*Se separa el arreglo en dos uno gde y otro peq,
    comparando elementos dentro del mismo arreglo input*/
    for(i=0;i<=j;i++){
        j--;
        if(input[i]>input[j]){
            gde[i]=input[i];
            peq[i]=input[j];
        }
        else{
            gde[i]=input[j];
            peq[i]=input[i];
        }
        cont++;
    }
    /*Se busca el maximo del arreglo de 'grandes'*/
    *may=gde[0];
    for(i=1;i<cont;i++)
        if(gde[i]>*may)
            *may=gde[i];
    /*Se busca el maximo del arreglo de 'pequeños'*/
    *men=peq[0];
    for(i=1;i<cont;i++)
        if(peq[i]<*men)
            *men=peq[i];
}