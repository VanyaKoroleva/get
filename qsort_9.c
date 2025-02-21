#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    int y;
}Point;

void print_a(Point * a, int n){
    int i = 0;
    for (i = 0; i < n; i ++)
        printf("%d %d\n", a[i].x, a[i].y);
}

int cmt(const void * p1, const void * p2){
    int x1 = ((const Point *)p1)->x;
    int y1 = ((const Point *)p1)->y;
    int x2 = ((const Point *)p2)->x;
    int y2 = ((const Point *)p2)->y;
    unsigned long int s1 = x1 * x1 + y1 * y1;
    unsigned long int s2 = x2 * x2 + y2 * y2;
    if (s1 == s2){
        if(x1 == x2)
            return y1 - y2;
        return x1 - x2;
    }
    return s1 - s2;

}

int main(){
    int i, n;
    scanf("%d", &n);
    Point a[n];
    for (i = 0; i < n; i++)
        scanf("%d%d", &a[i].x, &a[i].y);
    
    qsort(a, n, sizeof(Point), cmt);
    printf("-----------\n");
    print_a(a, n);
    
}
