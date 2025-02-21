#include<stdio.h>

int main(){
    int s = 0, c;
    char d;
    scanf("%c", &d);
    printf("%c ", d);
    while ((c = getchar()) != EOF) {
        if (c == d)
            s += 1;
        printf("%c", c);
    }
    printf(" %d\n", s);
    return 0;
}