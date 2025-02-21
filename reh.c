#include <stdio.h> 
#include <math.h>

#define N 1300000

void printm(int a[], int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d %d\n", i, a[i]);
    printf("\n");

}

int main(){
    char a[N];
    int i, k, n;
    for(i = 0; i < N; i++)
        a[i] = 1;
    for(k = 2; k < sqrt(N) + 1; k++){
        for(i = 2 * k; i < N; i += k){
            if (i % k == 0)
                a[i] = 0;
        }
    }
    scanf("%d", &n);
    int el[n];
    for(i = 0; i < n; i++)
        scanf("%d", &el[i]);
    
    for(i = 0; i < n; i++){
        if(a[el[i]])
            printf("%d ", el[i]);
    }
    return 0;
}