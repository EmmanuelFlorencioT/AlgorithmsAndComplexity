#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define RANGE 9
#define SZ 10

typedef struct{
    int currSize;
    int set[SZ];
}SUBSET_A;

int V[SZ];
SUBSET_A A[SZ];

/*Funciones auxiliares para prueba*/
void printArr(int arr[], int n);
void printA(SUBSET_A a[], int n);
void printMat(int mat[SZ][SZ], int nR, int nC);
/*--------------------------------*/

void createGraph(int graph[SZ][SZ], int n);
void printGraph(int graph[SZ][SZ], int n);
int min(int a, int b);
int copy(int origin[], int dest[], int n);
int binCoeff(int n, int k);
void createV(int n);
void createA(int n);

//Algoritmo de combinación
void combinationUtil(int arr[], int n, int r, int index, int data[], int i, int *indexA);

int checkSet(int value, int indexCol);
int findAminusVj(int node, int sizeA, int indexCol);
int minimum(int indexRow, int indexCol, int W[SZ][SZ],int D[SZ][SZ], int *jMin);
void problema1(int n, int W[SZ][SZ], int P[SZ][SZ], int *minlength);

int main(){
    int n = 4, g[SZ][SZ], resP[SZ][SZ], resMinLen;
    createGraph(g, n);
    printf("W:\n");
    printGraph(g, n);
    printf("\n");
    createV(n);
    // printArr(V, n);
    // printf("[CHANGE LINE]\n");
    createA(n);
    // printA(A, n);
    problema1(n, g, resP, &resMinLen);
    printf("\n");
    printf("Optimal tour length is: %d", resMinLen);
}

//Crea un grafo al azar
void createGraph(int graph[SZ][SZ], int n){
    int i, j;

    srand(time(NULL));
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(j == i)
                graph[i][j] = 0;
            else
                graph[i][j] = rand() % RANGE + 1;
}

//Imprime un grafo con formato
void printGraph(int graph[SZ][SZ], int n){
    int i, j;

    printf("  ");
    for(i=0; i<n; i++)
        printf("___%d", i);
    printf("\n");

    for(i=0; i<n; i++){
        printf("%d|", i);
        for(j=0; j<n; j++)
            printf("%4d", graph[i][j]);
        printf("\n");
    }
}

//Funcion de acotación para binCoeff
int min(int a, int b){
    if(a < b)
        return a;
    if(a > b)
        return b;
    return a;
}

//Funcion que copia matrices
int copy(int origin[], int dest[], int n){
    int i;
    for(i=0; i < n; i++)
        dest[i] = origin[i];
}

//Saca el coeficiente binomial o numero de combinaciones
//a partir de n elementos con grupos de k-elementos
int binCoeff(int n, int k){
    int i, j, res[k+1], aux[k+1];

    for(i=0; i <= n; i++){
        for(j=0; j <= min(i, k); j++){
            if(j == 0 || j == i)
                res[j] = 1;
            else
                res[j] = aux[j-1] + aux[j];
        }
        copy(res, aux, min(i, k)+1);
    }
    return res[k];
}

void createV(int n){
    int i;
    for(i=0; i<n; i++){
        V[i] = i;
    }
}

//Algoritmo de combinación
/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index, int data[], int i, int *indexA){
    // La combinación está lista para guardarse
    if (index == r){
        for(int j=0; j<r; j++){
            A[*indexA].set[j] = data [j];
        }
        (*indexA) += 1;
        return;
    }

    if (i >= n)
        return;

    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1, indexA);

    combinationUtil(arr, n, r, index, data, i+1, indexA);
}

//Crea los conjuntos A para cada columna de la matriz D
void createA(int n){
    int i, j, cont = 0; //Contador para llenar A[cont].currSize
    int temp[SZ], auxV[SZ];
    int idxA = 1; //Dentro de A[] el 0 es el conjunto vacío

    for(i=0; i<n-1; i++)
        auxV[i] = V[i+1];

    // Se inicializa el conjunto vacío
    A[cont].currSize = 0;
    A[cont].set[0] = 0;
    cont++;

    for(i = 1; i<n; i++){ //Controla el tamaño del subconjunto A
        combinationUtil(auxV, n-1, i, 0, temp, 0, &idxA);
        for(j = 1; j <= binCoeff((n-1), i); j++){ //Controla el numero de combinaciones
            A[cont].currSize = i; //Controla el currSize
            cont++;
        }
    }
}

//Revisa si se hará un calculo dentro de "problema1()"
int checkSet(int value, int indexCol){
    int i, flag = 0; //Bandera para revisar si encontró el elemento
    for(i = 0; i < A[indexCol].currSize; i++)
        if(A[indexCol].set[i] == value)
            flag = 1;
    return flag;
}

//Encuentra el indice del conjunto A - {Vj}
int findAminusVj(int node, int sizeA, int indexCol){
    int i, j = 0, Aux[sizeA - 1];

    if(sizeA == 1)
        return 0; //Hablamos del conjunto vacio
    
    //Copiamos todos los elementos de A[indexCol].set menos el "node"
    //a un arreglo auxiliar
    for(i = 0; i < sizeA; i++)
        if(A[indexCol].set[i] != node){
            Aux[j] = A[indexCol].set[i];
            j++;
        }
    
    i = 1;
    while((A[i].currSize <= sizeA - 1)){
        if(A[i].currSize == sizeA - 1){
            //Revisamos si A[i].set es igual a Aux
            for(j = 0; j < A[i].currSize; j++)
                if(A[i].set[j] != Aux[j])
                    break;
            //Si es igual, hay que salir del ciclo
            if(j == sizeA - 1)
                break;
        }
        i++;
    }
    //Regresamos el índice que tiene A - {node}
    return i;
}

//Calcula el minimo de (W[i][j] + D[j][A - {Vj}]) para toda j y vj que pertenece a A[indexCol].set
int minimum(int indexRow, int indexCol, int W[SZ][SZ],int D[SZ][SZ], int *jMin){
    int currMin = INT_MAX;
    int j, tempMin;

    for(j = 0; j < A[indexCol].currSize; j++){
        tempMin = W[indexRow][A[indexCol].set[j]] + D[A[indexCol].set[j]][findAminusVj(A[indexCol].set[j], A[indexCol].currSize, indexCol)];
        if((tempMin) < currMin){
            currMin = tempMin;
            *jMin = j;
        }
    }
    return currMin;
}

void problema1(int n, int W[SZ][SZ], int P[SZ][SZ], int *minlength){
    int i, j, k, jMin; //Valor de j que dio el minimo en "minimum()"
    int nColsD = (int)pow(2, n-1);
    int D[SZ][SZ];

    //Inicialización de la matriz D
    for(i = 0; i < n; i++)
        for(j = 0; j < nColsD; j++)
            D[i][j] = 0;

    //Inicialización de la primera columna
    for(i = 1; i < n; i++){
        D[i][0] = W[i][0];
    }

    for(j = 1; j < nColsD - 1; j++) //Maneja las columnas
        for(i = 1; i < n; i++){ //Maneja las filas
            if(!checkSet(i, j)){
                D[i][j] = minimum(i, j, W, D, &jMin);
                P[i][j] = jMin;
            }
        }
    D[0][nColsD-1] = minimum(0, nColsD-1, W, D, &jMin);
    P[0][nColsD-1] = jMin;
    *minlength = D[0][nColsD-1];

    /*PRUEBA DEL CONTENIDO DE D[][]*/
    printf("D:\n");
    printMat(D, n, nColsD);
    /*-----------------------------*/
}


/*Funciones auxiliares para prueba*/
void printArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void printA(SUBSET_A a[], int n){
    int i, j, limitD = 1;
    for(i = 1; i<n; i++)
        limitD += binCoeff((n - 1), i);
    for(i = 0; i<limitD; i++)
        printArr(a[i].set, a[i].currSize);
}

void printMat(int mat[SZ][SZ], int nR, int nC){
    int i, j;

    printf("  ");
    for(i = 0; i < nC; i++)
        printf("__%2d", i);
    printf("\n");

    for(i = 0; i < nR; i++){
        printf("%d|", i);
        for(j = 0; j < nC; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }
}
/*--------------------------------*/