#include <stdio.h> 
#include <math.h>

#define N 1000

int main(){
    char a[N];
    int i, k, n, el;
    for (i = 0; i < N; i++)
        a[i] = 1;
    for (k = 2; k < sqrt(N) + 1; k++){
        for (i = 2 * k; i < N; i += k){
            if (i % k == 0)
                a[i] = 0;
        }
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &el);
        if (a[el])
            printf("%d ", el);
    }
    return 0;
}