#include <stdio.h>
int main(){
    int m[3][3] = {};
    int i, j, res = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &m[i][j]);
            res += m[i][j];
        }
    }
    printf("%d", res);

    return 0;
}