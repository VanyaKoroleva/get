#include<stdio.h>

int main(){
    char a, b;
    int a1, b1;
    scanf("%c%d-%c%d", &a, &a1, &b, &b1);
    printf("%c%d-%c%d\n", a, a1, b, b1);
    if (a == b || a1 == b1)
        printf("YES");
    else
        printf("NO");
    return 0;
}