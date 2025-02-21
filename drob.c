#include<stdio.h>

int main(){
    int delimoe, delitel, delprom, s = 0;
    scanf("%d %d", &delimoe, &delitel);
    printf("%d,", delimoe / delitel);
    delimoe %= delitel;
    delprom = delimoe;
    do {
        delprom *= 10;
        s = s  + delprom / delitel;
        delprom %= delitel;
    } while (delprom != 0 && delprom != delimoe);
    if (delprom == 0)
        printf("%d(0)", s);
    else
        printf("(%d)", s);
    return 0;
}