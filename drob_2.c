#include<stdio.h>

int main(){
    int delimoe, delitel, i, flag, j;
    int s[100] = {};
    scanf("%d %d", &delimoe, &delitel);
    printf("%d,", delimoe / delitel);
    for (i = 0; delimoe != 0; i++){
        s[i] = delimoe %= delitel;
        delimoe = (s[i] * 10) % delitel;
        for (j = 0; j <= i; j++){
            if (s[j] == delimoe){
                flag = j;
                goto A;
            }
        }
    }
    flag = i;
A:  
    for (j = 0; j <= i; j++){
        if (j == flag)
            printf("(");
        printf("%d", s[j] * 10 / delitel);
    }
    printf(")");
    return 0;
}