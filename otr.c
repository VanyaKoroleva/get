#include<stdio.h>

int main(){
    int x;
    scanf("%d", &x);
    printf("%d ", x);
    if (x >= -25 && x < 37)
        printf("YES");
    else
        printf("NO");
    return 0;
}