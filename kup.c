#include<stdio.h>

int neporovnu(int * A, int n){
    int i = 0;
    for (i = 0; i < n - 1; i ++){
        if (A[i] != A[i + 1])
            return 1;
    }
    return 0;
}

int main(){
    int n, i, s, j, k = 0;
    scanf("%d", &n);

    int A[n];
    for (i = 0; i < n; i ++)
        scanf("%d", &A[i]);

    while(neporovnu(A, n)){
        for(i = 0; i < n; i++){
            j = (i != n - 1) ? i + 1 : 0;
            s = A[i] + A[j];
            k += s % 2;
            A[i] = s / 2;
            A[j] = s / 2;
        }
    }
    printf("%d %d\n", k, A[0]);

    return 0;
}