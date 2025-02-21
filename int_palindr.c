#include<stdio.h>

int main(){
    int x, xdub, y;
    scanf("%d", &x);
    xdub = x;
    y = 0;
    while (xdub != 0) {
        y = y * 10 + xdub % 10;
        xdub /= 10;
    }
    if (y == x) 
        printf("YES");
    else
        printf("NO");

    return 0;
}