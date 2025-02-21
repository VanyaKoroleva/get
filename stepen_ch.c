#include<stdio.h>

long long int ipow(long long int a, unsigned int n)
{
    long long int k;
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    if (n % 2 == 0) {
         k = ipow(a, n / 2);
         return k * k;
    }
    k = ipow(a, n - 1);
    return a * k;
}
int main(){
    int n, k, res, i, b;
    res = 1;
    i = 2;
    scanf("%d%d", &n, &k);
    while (n != 1){
        b = ipow(i, k);
        if (b > n){
            n = 1;
            res = -1;
        }
        else if (n % b == 0){
            res *= i;
            n /= b;
            printf("%d %d\n", i, n);
        i++;
        }       
    }  
    printf("%d", res);
    return 0;
    
}