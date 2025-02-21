#include<stdio.h>

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    if (y >= -2 && y <= 3 - x && y <= 3 + x)
        printf("YES");
    else
        printf("NO");
    return 0;
}