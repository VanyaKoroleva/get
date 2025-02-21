#include<stdio.h>
#define N 10000000;
int main(){
    int k, res = 0, a, b, c, ost = -1;
    a = 0;
    b = 1;
    scanf("%d", &k);
    while (ost != 0){
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
        res++;
        ost = c % k;
    }
    printf("\n%d", res);

    return 0;
}