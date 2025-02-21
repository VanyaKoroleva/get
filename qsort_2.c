#include<stdio.h>
#include <stdlib.h>

int cmpInt(const void * p1, const void * p2){
    float x = *(const float *)p1;
    float y = *(const float *)p2;

    return (x > y) - (x < y);
}

int main(){
    int n;
    scanf("%d", &n);
    float a[n];

    int i;
    for (i = 0; i < n; i++)
        scanf("%f", &a[i]);
    
    for (i = 0; i < n; i ++)
        printf("%f ", a[i]);
    printf("\n");
    
    qsort(a, n, sizeof(float), cmpInt);

    for (i = 0; i < n; i ++)
        printf("%.2f ", a[i]);

}