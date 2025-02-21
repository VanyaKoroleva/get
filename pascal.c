#include<stdio.h>

int main(){
    int n, i, j;
    scanf("%d", &n);
    int a[67][100] = {0};
    a[0][0] = 1;
    for(i = 1; i <= n; i ++){
        a[i][0] = 1;
        for(j = 1; j <= i; j ++)
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
    }

    for(i = 0; i <= n; i ++)
        printf("%d ", a[n][i]);
    return 0;
}