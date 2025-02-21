#include<stdio.h>
void rotateC(int *x1, int *y1, int *x2, int *y2)
{
    int xc, yc, a, b;
    xc = (*x1 + *x2) / 2;
    yc = (*y1 + *y2) / 2;
    b = (*x2 - *x1) / 2;
    a = (*y1 - *y2) / 2;
    *x1 = xc - a;
    *x2 = xc + a;
    *y1 = yc + b;
    *y2 = yc - b;
}

int main()
{
    int xlt, ylt, xrb, yrb;
    scanf("%d%d%d%d", &xlt, &ylt, &xrb, &yrb);
    rotateC(&xlt, &ylt, &xrb, &yrb);
    printf("%d %d %d %d", xlt, ylt, xrb, yrb);

    return 0;
}