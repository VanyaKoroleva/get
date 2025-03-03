#include <stdio.h>  // нужно для работы функций scanf и printf
#include <math.h>   // нужно для работы функции sin


int main()
{
    double
        a,          // угол к горизонту в ГРАДУСАХ, под которым бросили тело
        v0,         // начальная скорость тела, м/с
        g = 9.81,   // ускорение свободного падения
        h;          // максимальная высота подъема тела

   // h = v0 * v0 * sin(a) * sin(a) / (2 * g);

   // читаем входные данные
   scanf("%lf", &a);
   scanf("%lf", &v0);

   // sin вычисляется от радиан, даны градусы
   // переведем градусы в радианы rad = degree * (M_PI / 180.0)
   // M_PI - число PI, определено в стандартной математической библиотеке
   double arad = a * (M_PI / 180.0);
   h = (v0 * v0 * sin(arad) * sin(arad) / (2 * g));

   printf("Максимальная высота подъема %lf м\n", h);

   return 0;
}