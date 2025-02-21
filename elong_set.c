#include <stdio.h>
#define N 100


typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x){
    unsigned int i;
    for (i = 0; i <= x.n; i ++)
        printf("%d", x.a[x.n - i]);
    printf("\n");
    
}

void elong_set(Decimal * res, const char str[ ]){
    int i, j;
    for (i = 0; str[i] != '\0'; i++) ;
    res->n = i - 1;
    for (j = 0; j <= i; j ++)
        res->a[j] = str[i - 1- j] - 48;
    res->n = i - 1;
}
int main(){
    Decimal res;
    elong_set(&res, "12345678901234567890");  // res = 12345678901234567890
    elong_print(res);                         // print 12345678901234567890
    printf("%d", res.n);

    return 0;
}