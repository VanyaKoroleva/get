#include <stdio.h>
#include <string.h>

void print(int * a, int n){
    for (int i = 0; i < n; i ++)
        printf("%d ", a[i]);
    printf("\n");
}

void sdvig(int * a, int i, int j){
    int c = a[j];
    int z = (i > j) - (i < j);
    for(int k = j; k != i; k += z)
        a[k] = a[k + z];
    a[i] = c;
}

int main(){
    int a[7] = {1, 2, 3, 4, 5, 6, 7};
    print(a, 7);
    sdvig(a, 5, 2);
    print(a, 7);
    return 0;
}