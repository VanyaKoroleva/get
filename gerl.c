#include<stdio.h>

int main(){
    int A[10] = {};
    int n, i, k;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &k);
        A[k] += 1;
    }

    for(i=0; i<n; i++)
        printf("%d %d", i, A[i]);
    
    return 0;
}