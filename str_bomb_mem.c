#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

char * replace (const char * s){
    size_t lenbomb = strlen("bomb");
    size_t lenwater = strlen("watermelon");
    char * p = strstr(s, "bomb");
    char * res = strdup(s);
    while (p != NULL){
        memmove(p + lenwater, p + lenbomb, strlen(p + lenbomb) + 1);
        memcpy(p, "watermelon", lenwater);
        
        p = strstr(s, "bomb");
    }
    return res;
}

int main()
{
    char s[N];   // нужно объявить переменную - место для читаемой строки
    char * d;    // указатель на динамический массив, память еще не выделена

    while (NULL != fgets(s, N, stdin)) {  // пока можем прочитать строку
        d = replace(s);                   // тут память выделяем
        printf("+++%s+++\n", d);
        free(d);                          // тут память освобождаем
    }
    return 0;
}