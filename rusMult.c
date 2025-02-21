#include <stdio.h>

int rusMult(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", rusMult(a, b));
    return 0;
}

int rusMult(int a, int b)
{
    printf("%d %d\n", a, b);
    if (b == 1){
        printf("%d\n", a);
        return a;
    }
    int k = rusMult(a * 2, b / 2), c = k;
    if (b % 2 == 1){
        c += a;
    }
    printf("%d %d %d %d\n", k, a, b % 2, c);
    return c;
}