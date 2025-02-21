#include <stdio.h>
int sum_irow(int a[3][3], int irow){
    int i, res = 0;
    for (i = 0; i < 3; i ++)
        res += a[irow][i];
    return res;
}

int main(){
    int m[3][3] = {};
    int i, j, res = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            scanf("%d", &m[i][j]);
    }

    printf("%d", sum_irow(m, 1));

    return 0;
}