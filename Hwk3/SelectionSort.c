#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 15
#define RAND_RANGE 1000

void printArray(int arr[N]);
void createArray(int arr[N]);
void selectionSort(int arr[N]);

int main(){
    // Array is static so that the compiler can store it beforehand in memory
    static int arr[N];
    // Variables to measure time
    clock_t t_ini, t_end;
    double t_elapsed;

    // Create the array with random elements
    createArray(arr);
    // WARNING: Only print the array for testing purposes and if N is small
    printf ("\n\nUNSORTED ARRAY:\n");
    printArray (arr);

    // Check the initial time
    t_ini = clock();
    printf("\n\nInitial time: %f", ((double)t_ini));

    // Start the sorting algorithm
    selectionSort(arr);

    // Check the final time and calculate the elapsed time
    t_end = clock() - t_ini;
    printf("\nFinal time: %f", ((double)t_end));
    t_elapsed = ((double)t_end) / CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs", t_elapsed);

    // WARNING: Only print the array for testing purposes and if N is small
    printf ("\n\nSORTED ARRAY:\n");
    printArray (arr);

    return 0;
}

// ADD HERE YOUR SORTING METHODS
void selectionSort(int arr[N]){
    int pivot, sweep, aux;

    for(pivot=0;pivot<N-1;pivot++)
        for(sweep=pivot+1;sweep<N;sweep++)
            if(arr[sweep]<arr[pivot]){
                aux=arr[pivot];
                arr[pivot]=arr[sweep];
                arr[sweep]=aux;
            }
}

// Prints an array of size N
void printArray(int array[N])
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d, ", array[i]);
    }
}

// Fills an existing array with random values
void createArray(int array[N])
{
    int i;
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < N; i++)
    {
        // NOTE: If N is large try to have large numbers in the array
        // otherwise the array would contain many repeated elements
        array[i] = rand() % RAND_RANGE;
    }
}