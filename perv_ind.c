#include<stdio.h>
#define N 1000

int main(){
    int n, k, A[N], i;
    int res = -1;
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &k);
    for (i=0; i<n; i++){
        if (A[i] == k){
            res = i;
            break;
        } 
    }
    printf("%d\n", res);
    return 0;
}