#include<stdio.h>

int cmp_int(const void * p1, const void * p2){
    int x = *(int *)p1;
    int y = *(int *)p2;

    return (x > y) - (x < y);

}

int main()
{
    int x, y, res;
    scanf("%d%d", &x, &y);

    res = cmp_int(&x, &y);

    if (res < 0)
        res = '<';
    else if (res > 0)
        res = '>';
    else
        res = '=';

    printf("%c\n", res);

    return 0;
}