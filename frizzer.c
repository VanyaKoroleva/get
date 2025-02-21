#include<stdio.h>

void sort2(int * a, int * b){
    int max = (*a > *b) ? *a : *b;
    int min = (*a < *b) ? *a : *b;
    *b = max;
    *a = min;
}

void sort3(int * x, int * y, int * z){
    sort2(x, y);
    sort2(y, z);
    sort2(x, y);
}

int main(){
    int w, h, a, b, c;
    scanf("%d%d%d%d%d", &w, &h, &a, &b, &c);
    sort2(&w, &h);
    sort3(&a, &b, &c);
    if (a <= w && b <= h)
        printf("YES");
    else
        printf("NO");
    return 0;

}