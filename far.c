#include <stdio.h>

float fahr(int cel){
    return (cel * 1.8) + 32;
}

int main()
{
    int cel;    // градусы Цельсия
    float f;    // градусы Фаренгейта

    scanf("%d", &cel);
    f = fahr(cel);
    printf("%.2f\n", f);    // .2f - печатать с точностью до 2 знаков после .

    return 0;
}