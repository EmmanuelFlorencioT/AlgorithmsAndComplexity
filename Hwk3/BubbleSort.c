#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 75000
#define RAND_RANGE 10000000

void createArray(int array[N]);
void printArray(int arr[N]);
void bubbleSort(int arr[N]);

int main(){
// Array is static so that the compiler can store it beforehand in memory
    static int arr[N];
    // Variables to measure time
    clock_t t_ini, t_end;
    double t_elapsed;

    // Create the array with random elements
    createArray(arr);
    // WARNING: Only print the array for testing purposes and if N is small
    // printf ("\n\nUNSORTED ARRAY:\n");
    // printArray (arr);

    // Check the initial time
    t_ini = clock();
    printf("\n\nInitial time: %f", ((double)t_ini));

    // Start the sorting algorithm
    bubbleSort(arr);

    // Check the final time and calculate the elapsed time
    t_end = clock() - t_ini;
    printf("\nFinal time: %f", ((double)t_end));
    t_elapsed = ((double)t_end) / CLOCKS_PER_SEC;
    printf("\nTotal time: %f segs", t_elapsed);

    // WARNING: Only print the array for testing purposes and if N is small
    // printf ("\n\nSORTED ARRAY:\n");
    // printArray (arr);

    return 0;
}

// ADD HERE YOUR SORTING METHODS
void bubbleSort(int arr[N]){
    int front, back, aux;

    for(back=N-1;back>0;back--)
        for(front=0;front<back;front++)
            if(arr[front]>arr[front+1]){
                aux=arr[front+1];
                arr[front+1]=arr[front];
                arr[front]=aux;
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
