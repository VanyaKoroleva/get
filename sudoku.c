#include <stdio.h>

int stroka(int str, int a[9][9]){
    int i;
    int m[9] = {};
    for (i = 0; i < 9; i++){
        if (m[a[str][i] - 1] != 1)
            m[a[str][i] - 1] = 1;
        else
            return 0;
    }
    return 1;
}

int col(int c, int a[9][9]){
    int i;
    int m[9] = {};
    for (i = 0; i < 9; i ++){
        if (m[a[i][c] - 1] != 1)
            m[a[i][c] - 1] = 1;
        else
            return 0; 
    }
    return 1;
}

int cub(int n, int l, int a[9][9]){
    int i, j;
    int m[9] = {};
    for (i = 0; i < 3; i ++){
        for (j = 0; j < 3; j ++){
            if (m[a[n + i][l + j] - 1] != 1)
                m[a[n + i][l + j] - 1] = 1;
            else
                return 0;
        }
    }
    return 1;
}

int proverka(int a[9][9]){
    int i, j;
    for (i = 0; i < 9; i++){
        if (stroka(i, a) == 0 || col(i, a) == 0)
            return 0;
        if (i % 3 == 0){
            for (j = 0; j < 9; j += 3){
                if (cub(i, j, a) == 0)
                    return 0;
            }
        }
    }
    return 1;
}


int main(){
    int i, j;
    int a[9][9];
    for (i = 0; i < 9; i ++){
        for (j = 0; j < 9; j ++)
            scanf("%d", &a[i][j]);
    }

    if (proverka(a))
        printf("YES");
    else
        printf("NO");
    
    return 0;
}