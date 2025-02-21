#include <stdio.h>
#define CH 42

void pokraska(int i, int j, char cvet, char a[][101], int n){
    if (a[i][j] == CH){
        a[i][j] = cvet;
        if (i + 1 < n)
            pokraska(i + 1, j, cvet, a, n);
        if (i - 1 >= 0)
            pokraska(i - 1, j, cvet, a, n);
        if (j + 1 < n)
            pokraska(i, j + 1, cvet, a, n);
        if (j - 1 >= 0)
            pokraska(i, j - 1, cvet, a, n);
    }
}

int main(){
    int n, i, j;
    scanf("%d", &n);
    char a[101][101];
    char cvet = 0;

    for (i = 0; i < n; i++)
        scanf("%101s", a[i]);

    for (i = 0; i < n; i ++){
        for (j = 0; j < n; j ++){
            if (a[i][j] == CH){
                pokraska(i, j, cvet, a, n);
                cvet ++;
            }
        }
    }
    
    
    printf("%d", cvet);

    return 0;
}