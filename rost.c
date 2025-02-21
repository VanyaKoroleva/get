#include<stdio.h>

int main(){
    int x, k, m;
    k = 0;
    m = 0;
    while (1 == scanf("%d", &x)) {
        k ++;
        if (x > 170)
            m ++;
    }
    printf("%d %d", k, m);
    return 0;
}