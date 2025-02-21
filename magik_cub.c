#include <stdio.h>

int sum_irow(int a[3][3], int irow){
    int i, res = 0;
    for (i = 0; i < 3; i ++)
        res += a[irow][i];
    return res;
}

int sum_col(int a[3][3], int icol){
    int i, res = 0;
    for (i = 0; i < 3; i ++)
        res += a[i][icol];
    return res;
}

int sum_diag(int a[3][3]){
    int i, res = 0;
    for (i = 0; i < 3; i ++)
        res += a[i][i];
    return res;
}

int sum_diag2(int a[3][3]){
    int i, res = 0;
    for (i = 0; i < 3; i ++)
        res += a[i][2 - i];
    return res;
}

int main(){
    int a[3][3] = {};
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    }
    
    int m[8] = {sum_diag(a), sum_diag2(a)};
    for (i = 0; i < 3; i ++){
        m[2 + i] = sum_col(a, i);
        m[7 - i] = sum_irow(a, i);
    }
    int f = 1;

    for (i = 0; i < 7; i++){
        if(m[i] != m[i + 1]){
            f = 0;
            break;
        }
    }

    if (f)
        printf("MAGIC");
    else
        printf("NO");

    return 0;
}