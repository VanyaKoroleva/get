#include<stdio.h>

int main(){
    int d, res, k;
    scanf("%d%d", &d, &k);
    printf("%d %d ", d, k);
    while (k != 0) {
        if (k % 10 == d)
            res ++;
        k /= 10;
    }
    printf("%d", res);
    return 0;
}