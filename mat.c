#include <stdio.h>

void number_mult(int k, int rows, int cols, int a[][cols]){
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j ++)
            printf("%d ", k * a[i][j]);
        printf("\n");
    }
}

int main(){
    int n, m, k;
    scanf("%d%d", &n, &m);
    int a[n][m];
    int i, j;
    for (i = 0; i < n; i ++){
        for (j = 0; j < m; j ++)
            scanf("%d", &a[i][j]);
    }
    scanf("%d", &k);
    number_mult(k, n, m, a);

    return 0;
}