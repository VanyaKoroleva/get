#include<stdio.h>
#define N 100

struct _Decimal {
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

int is_div11 (Decimal a){
    int res = 0, znak;
    unsigned int i;
    for (i = 0; i <= a.n; i++){
        znak = (i % 2 == 0) ? -1 : 1;
        res += znak * a.a[i];
    }
    return (res % 11 == 0) ? 1 : 0;
}

int main(){
    Decimal a = {{3, 4, 1}, 2};  // 143 (делится на 11)
    Decimal b = {{3, 1}, 1};     // 13 (не делится на 11)

    int res;
    res = is_div11(a);           // res = 1
    printf("%d\n", res);
    
    res = is_div11(b);           // res = 0
    printf("%d\n", res);
    
    return 0;
}