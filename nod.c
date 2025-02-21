#include<stdio.h>

int nod(int a, int b)
{
    if (b == 0){
        return a;
    }
    int c = a % b;
    return nod(b, c);
}

int main()
{
    int a, b, n;
    scanf("%d%d", &a, &b);
    if (a > b){
        n = nod(a, b);
    }
    else{
        n = nod(b, a);
    } 
    printf("%d\n", n);
}