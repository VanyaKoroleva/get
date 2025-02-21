#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 48

typedef struct{
    char *dig;  // массив для хранения числа:
                // a[0] * 100^0 + a[1] * 100^1 + .. + a[n - 1] * 100^(n-1)
    int n;      // размер числа в разрядах
    char sign;  // знак числа
} LongN;

void print_longN(LongN x){
    char * p;
    for(p = x.dig + x.n; p >= x.dig; --p){
        printf("%d", *p);
    }
}

LongN getLongN(char * s){
    LongN res;
    if (s[0] == '-'){
        res.sign = '-'; 
        memmove(s, s + 1, strlen(s + 1) + 1);
    }
    else if (s[0] == '+'){
        res.sign = '+';
        memmove(s, s + 1, strlen(s + 1) + 1);
    }
    else {
        res.sign = '+';
    }

    printf("12");

    if(s[0] == '0'){
        res.n = 0;
        res.dig = malloc(res.n + 1);  //если 0
        res.dig[0] = 0;
        return res;
    }

    res.n = 0;
    int size = 400;        // выделяю память
    res.dig = malloc(size);
    unsigned int i;
    for (i = 1; i <= strlen(s); i += 2, ++ res.n){
        if (strlen(s) - i >= 1){
                //заполняю массив
            printf("%d\n", (s[strlen(s) - i] - N) + (s[strlen(s) - i - 1] - N) * 10);
            res.dig[res.n] = (s[strlen(s) - i] - N) + (s[strlen(s) - i - 1] - N) * 10;
        }
        else{
            printf("%d\n", (s[strlen(s) - i] - N));
            res.dig[res.n] = (s[strlen(s) - i] - N);
        }
    }

    res.n --;
    size = res.n + 1;
    res.dig = realloc(res.dig, size);

    return res;
}

int main(){
    LongN x = getLongN("-12345");
    printf("%c", x.sign);
    print_longN(x);
}

