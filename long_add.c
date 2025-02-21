#include<stdio.h>

#define N 100
typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

Decimal add (Decimal x, Decimal y){
    Decimal res = {{0}, 0};
    int i = 0, k = 0;
    int s1 = x.a[0], s2 = y.a[0];
    if (s1 + s2 == 0){
        return res;
    }
    while (s1 + s2 + k != 0){
        res.a[i] = (s1 + s2 + k) % 10;
        k = (s1 + s2 + k) / 10;
        i++;
        s1 = (i <= x.n) ? x.a[i] : 0;
        s2 = (i <= y.n) ? y.a[i] : 0;
    }
    res.n = i - 1;
    return res;
}

void elong_print(Decimal x){
    int i;
    printf("%d: ", x.n);
    for (i = 0; i <= x.n; i ++)
        printf("%d", x.a[x.n - i]);
    printf("\n");
}

int main(){
    Decimal x = {{0}, 0}; 
    Decimal y = {{0}, 0}; 
    Decimal res;

    //res = add(x, y);             // res = x+y = 147+13 = 160
    elong_print(x);            // print 160

    return 0;
}
