#include<stdio.h>

long long int ipow(long long int a, unsigned int n, unsigned * depth)
{
    long long int k;
    if (a == 0){
        return 0;
    }
    if (n == 0) {
        *depth = 1;
        return 1;
    }
    if (n == 1) {
        *depth = 1;
        return a;
    }
    if (n % 2 == 0) {
         k = ipow(a, n / 2, depth);
         *depth += 1;
         return k * k;
    }
    k = ipow(a, n - 1, depth);
    *depth += 1;
    return a * k;
}

int main()
{
    unsigned int a, n, d = 666;
    long long int res;
    scanf("%d%d", &a, &n);
    res = ipow(a, n, &d);
    printf("%llu %d", res, d);

    return 0;
}