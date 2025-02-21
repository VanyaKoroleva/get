#include <stdio.h>
#include <stdlib.h>

void scanf_a(int * a, int n){
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void print_a(int * a, int n){
    int i;
    for (i = 0; i < n; i ++)
        printf("%d ", a[i]);
    printf("\n");
}

int cmt(const void * p1, const void * p2){
    int x = *(const int *)p1;
    int y = *(const int *)p2;
    
    return (x > y) - (x < y);
}

int main(){
    int n, i, j;
    scanf("%d", &n);
    int a[n];  //изначальный массив
    scanf_a(a, n);
    int b[n];  //массив четных чисел
    for (i = 0, j = 0; i < n; i ++){
        if (a[i] % 2 == 0){
            b[j] = a[i];
            a[i] = 0;
            j ++;
        }
    }

    qsort(b, j, sizeof(int), cmt);

    for (i = 0, j =0; i < n; i ++){
        if (a[i] == 0){
            a[i] = b[j];
            j ++;
        }
    }
    
    print_a(a, n);
    
}