#include <stdio.h>

#define N 4

void iniDisks(int disks[], int n);
void problema7(int n, char start, char aux, char final);

int main(){
    int arr[N];

    iniDisks(arr, N);
    problema7(N, 'A', 'B', 'C');
}

void iniDisks(int disks[], int n){
    int i;

    for(i=0;i<n;i++)
        disks[i]=i+1;
}

void problema7(int n, char start, char aux, char final){
    if(n == 1){
        printf("Disk 1 from %c to %c\n", start, final);
        return;
    } else{
        problema7(n-1, start, final, aux);
        printf("Disk %d from %c to %c\n", n, start, final);
        problema7(n-1, aux, start, final);
    }

}
