#include<stdio.h>

int rusDel(int a, int b);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", rusDel(a, b));
    return 0;
}

int rusDel(int a, int b)
{
    int rem = 0, mult = 2, part;
    if (a == 0){
        return 0;
    }
    if (a % 2 == 1){
        rem = 1, mult = 1;
        a -= b;
    }
    else {
        a /= 2;
    }
    if (a != 0){
        printf("%d %d %d\n", a, mult, rem);
    }
    part = rusDel(a, b);
    int new_part = part * mult + rem;
    if (new_part == 1){
        printf("%d\n", 1);
    }
    else{
        printf("%d * %d + %d = %d\n", part, mult, rem, new_part);
    }
    return new_part;
}