#include <stdio.h>

void scan_mat(int n, int m, int a[n][m]){
    int i, j;
    for (i = 0; i < n; i ++){
        for (j = 0; j < m; j ++)
            scanf("%d", &a[i][j]);
    }
}

void sum(int rows, int cols, int a[][cols], int b[][cols]){
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j ++)
            printf("%d ", a[i][j] + b[i][j]);
        printf("\n");
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m], b[n][m];
    scan_mat(n, m, a);
    scan_mat(n, m, b);
    sum(n, m, a, b);

    return 0;
}