#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10

typedef int Data;

typedef struct {
    int n;
    int size;
    Data * a;
} Stack;

Stack * stack_create(int size){
    Stack * st = malloc(sizeof(Stack));
    st->n = 0;
    st->size = size;
    st->a = malloc(size * sizeof(Data));
    return st;
}

int stack_is_full(Stack * s){
    return (s->n == s->size);
}

void stack_push(Stack * s, Data x){
    if (stack_is_full(s)){
        s->size += N;
        s->a = realloc(s->a, s->size * sizeof(Data));
    }
    s->a[s->n] = x;
    s->n ++;
}

Data stack_pop(Stack * s){
    return(s->a[--s->n]);
}

Data stack_get(Stack * s){
    return(s->a[s->n - 1]);
}

void stack_print(Stack * s){
    int i;
    for (i = 0; i < s->n; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}

int  stack_size(Stack * s){
    return s->n;
}

int  stack_is_empty(Stack * s){
    return s->n == 0;
}

void stack_clear(Stack * s){
    s->n = 0;
    s->size = 0;
    free(s->a);
    s->a = NULL;
}

Stack * stack_destroy(Stack * s){
    stack_clear(s);
    free(s);
    return NULL;
}

int index(char *s, int c){
    int i;
    for(i = 0; i < 4; i++){
        if (s[i] == c)
            return i;
    }
    return -1;
}

int main(){
    Stack * s = stack_create(10);
    char * operator = "+-*=";
    char c;
    int a, b;
    while(1 == scanf("%c", &c)){
        if(isspace(c))
            continue;
        if(strchr(operator, c) == NULL)
            stack_push(s, (int)(c - 48));
        else{
            switch(index(operator, c))
            {
            case 0 : // +
                stack_push(s, stack_pop(s) + stack_pop(s));
                break;
            case 1 : // -
                a = stack_pop(s);
                b = stack_pop(s);
                stack_push(s, b - a);
                break;
            case 2 : // *
                stack_push(s, stack_pop(s) * stack_pop(s));
                break;
            default: // =
                stack_print(s);
                return 0;
            }
        }
    }

    return 0;
}