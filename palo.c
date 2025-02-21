#include<stdio.h>

int main(){
    int n, k;
    scanf("%d", &n);
    k = ((n - 1) % 4 != 0) ? -1 : n % 4;
    printf("%d", k);
}