#include<stdio.h>
#define N 1000

int main(){
    int n, i;
    int A[N];
    int B[N];

    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d", &A[i]);
    for (i=0; i<n; i++)
        scanf("%d", &B[i]);

    for (i=0; i<n; i++)
        printf("%d ", A[i] + B[i]);
    
    return 0;
}