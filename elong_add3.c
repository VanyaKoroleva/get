#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * a;           // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;     // наибольшая степень десяти
    unsigned int size;  // размер выделенной динамической памяти в а
}Decimal;

void elong_set_int(Decimal * px, unsigned int number)
{
    if (number == 0){       // 0*10**0
        px->size = 1;
        px->n = 0;
        px->a = malloc(px->size);
        px->a[0] = 0;
        return;
    }

    // number точно меньше 10 в 100, выделим память с запасом
    px->size = 100;
    px->a = malloc(px->size);

    for(px->n = 0; number > 0; px->n++){
        px->a[px->n] = number % 10;
        number /= 10;
    }
    px->n --;

    // выделим памяти точно под хранение числа
    px->size = px->n + 1;
    px->a = realloc(px->a, px->size);
}

void elong_destroy(Decimal * px)
{
    free(px->a);        // освобождаем желтый массив с цифрами
}

void elong_print(Decimal  * px){
    char * p;
    for (p = px->a + px->n; p >= px->a; --p){
        printf("%d", *p);
    }
    printf("\n");    
    
}

void elong_add (const Decimal * a, const Decimal * b, Decimal * res){
    int rem = 0;
    res->n = 0;
    res->size = 100;
    res->a = malloc(res->size);
    unsigned int i;

    for(i = 0; (i <= a->n) || (i <= b->n); ++i, ++res->n){
        rem += ((i <= a->n) ? a->a[i] : 0) + ((i <= b->n) ? b->a[i] : 0);
        res->a[i] = rem % 10;
        rem /= 10;
    }

    res->a[i] = rem;
    
    while (res->n > 0 && res->a[res->n] == 0) // Убираем лишние разряды
        --res->n;
    
    res->size = res->n + 1;
    res->a = realloc(res->a, res->size);

}

int main(){
    Decimal * a;
    Decimal * b;
    Decimal * res;
    
    a = elong_set_int(147);    // 147
    b = elong_set_int(13);     // 13

    res = elong_add(a, b);     // res = a+b = 147+13 = 160

    elong_print(res);          // print 160

    elong_destroy(a);
    elong_destroy(b);
    elong_destroy(res);

    return 0;
}