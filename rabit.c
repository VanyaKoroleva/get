#include<stdio.h>

int main()
{
    char x;
    int n;
    scanf("%c%d ", &x, &n);
    printf("%c%d ", x - 1, n);
    printf("%c%d ", x, n + 1);
    printf("%c%d ", x + 1, n);
    printf("%c%d", x, n - 1);
    return 0;
}