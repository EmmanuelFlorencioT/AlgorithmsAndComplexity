#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 10000
#define RAND_RANGE 10000000

void createArray(int array[N]);
void printArray(int array[N]);
void merge(int S[], int low, int mid, int high);
void mSort(int S[], int low, int high);
void mergeSort(int arr[]);

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
    mergeSort(arr);

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

//ADD HERE YOUR SORTING METHODS
void merge(int S[], int low, int mid, int high){
    int start2=mid + 1;
 
    // If the direct merge is already sorted
    if (S[mid]<=S[start2]) {
        return;
    }
 
    while (low<=mid && start2<=high) {
        // If element 1 is in right place
        if (S[low]<=S[start2]) {
            low++;
        }
        else {
            int value=S[start2];
            int index=start2;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != low) {
                S[index]=S[index - 1];
                index--;
            }
            S[low]=value;
 
            // Update all the pointers
            low++;
            mid++;
            start2++;
        }
    }
}

void mSort(int S[], int low, int high){
    int mid;
    if(low<high){
        mid=floor((low+high)/2);
        mSort(S, low, mid);
        mSort(S, mid+1, high);
        merge(S, low, mid, high);
    }
}

void mergeSort(int arr[]){
    mSort(arr, 0, N-1);
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
