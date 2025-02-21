#include<stdio.h>
#define N 100

typedef struct {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
}Decimal;

void elong_print(Decimal x);

int main()
{
    Decimal x = {{7, 4, 1}, 2}; // число 147
    Decimal zero ={{0}, 0};     // число 0 представим как 0 умножить на 10 в степени 0

    elong_print(x);     // 147
    elong_print(zero);  // 0

    return 0;
}

void elong_print(Decimal x){
    int i;
    for (i = 0; i <= x.n; i ++)
        printf("%d", x.a[x.n - i]);
        printf("\n");
}

Decimal add (Decimal x, Decimal y){
    Decimal res;
    int i = 0, k = 0;
    int s1, s2;
    do {
        s1 = (i <= x.n) ? x.a[i] : 0;
        s2 = (i <= y.n) ? y.a[i] : 0;
        res.a[i] = (s1 + s2 + k) % 10;
        k = (s1 + s2 + k) / 10;
        i++
    } while (s1 + s2 + k != 0);
    res.n = i - 1;
    return res;
}


int i = 1, k = 0;
    int s1 = x.a[0], s2 = y.a[0];
    while (s1 + s2 + k != 0){
        res.a[i - 1] = (s1 + s2 + k) % 10;
        k = (s1 + s2 + k) / 10;
        s1 = (i <= x.n) ? x.a[i] : 0;
        s2 = (i <= y.n) ? y.a[i] : 0;
        i++;
    }
    res.n = i - 2;
    return res;