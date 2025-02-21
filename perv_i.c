#include<stdio.h>
#define N 1000

int main(){
    int n, k, A[N], i;
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    for (i=0; i<n; i++){
        if (A[i] == k){
            printf("%d\n", i);
            break;
        } 
    }
    return 0;
}