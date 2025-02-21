#include<stdio.h>
#include<math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point a;    // начало отрезка
    Point b;    // конец отрезка
    float len;  // длина отрезка
} Line;

float distance(Point a, Point b);   // расстояние между точками
void scanLine(Line * t);
void printLine(Line t);
void rotRLine(Line * t);

int main() {
    Line t;
    scanLine(&t);
    t.len = distance(t.a, t.b);
    rotRLine(&t);
    printLine(t);

    return 0;
}

float distance(Point a, Point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void scanLine(Line * t){
    scanf("%d%d%d%d", &(t -> a.x), &(t -> a.y), &(t -> b.x), &(t -> b.y));
}

void printLine(Line t){
    printf("%d %d %d %d %.3f", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}

void rotRLine(Line * t){
    int k = t -> a.x, m = t -> b.x;
    t -> a.x = t -> a.y;
    t -> a.y = -k;
    t -> b.x = t -> b.y;
    t -> b.y = -m;
}