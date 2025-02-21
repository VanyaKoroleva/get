#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int cmp_Point(const void * p1, const void * p2){
    int x1 = ((const struct Point *)p1)->x;
    int y1 = ((const struct Point *)p1)->y;
    int x2 = ((const struct Point *)p2)->x;
    int y2 = ((const struct Point *)p2)->y;
    unsigned long int s1 = x1 * x1 + y1 * y1;
    unsigned long int s2 = x2 * x2 + y2 * y2;
    printf("%lu\n%lu\n", s1, s2);
    return (s1 > s2) - (s1 < s2);
}

int main()
{
    struct Point a, b;
    scanf("%d%d", &a.x, &a.y);
    scanf("%d%d", &b.x, &b.y);

    int res = cmp_Point(&a, &b);

    if (res < 0)
        printf("<\n");
    else if (res > 0)
        printf(">\n");
    else
        printf("=\n");

    return 0;
}