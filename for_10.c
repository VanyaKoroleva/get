#include<stdio.h>

int main(){
    int a, b, f;
    f = 1;
    scanf("%d", &a);
    do {
        b = a % 10;
        a /= 10;
        if (b == 0){
            if (f == 1)
                ;
            else {
                f = 0;
                printf("%d", b)
            }
        }
        else
            if (f == 1)
                f = 0;
            printf("%d", b)
                
    } while (a != 0);
} 