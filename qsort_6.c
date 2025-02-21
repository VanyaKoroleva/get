#include <stdio.h>
#include <stdlib.h>

int cmt(const void * p1, const void * p2){
    int x = *(const int *)p1;
    int y = *(const int *)p2;
    if (x % 10 == y % 10){
        x /= 10;
        y /= 10;
        return cmt(&x, &y);
    }

    return (x % 10 >= y % 10) ? 1 : -1;
    
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];

    int i;
    for (i = 0; i < n; i ++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i ++)
        printf("%d ", a[i]);
    printf("\n");

    qsort(a, n, sizeof(int), cmt);

    for (i = 0; i < n; i ++)
        printf("%d ", a[i]);
}
