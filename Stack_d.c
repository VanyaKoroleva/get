#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef int Data;

typedef struct{
    int n;
    int Size;
    Data * a;
} Stack;

Stack * stack_create(int size){
    Stack * res = malloc(sizeof(Stack));
    res->n = 0;
    res->Size = size;
    res->a = malloc(size * sizeof(int));
    return res;
}

int stack_is_full(Stack * s){
    return (s->n == s->Size);
}

void stack_push(Stack * s, Data x){
    if(stack_is_full(s)){
        s->Size += N;
        s->a = realloc(s->a, s->Size * sizeof(int));
    }
    s->a[s->n] = x;
    s->n ++;
}

void stack_print(Stack * s){
    int i;
    for (i = 0; i < s->n; i++)
        printf("%d ", s->a[i]);
    printf("\n");
}

Data stack_pop(Stack * s){
    return(s->a[--s->n]);
}

Data stack_get(Stack * s){
    return(s->a[s->n - 1]);
}

int stack_is_empty(Stack * s){
    return(s->n == 0);
}

int stack_size(Stack * s){
    return(s->n);
}

void stack_clear(Stack * s){
    s->n = 0;
    s->Size = 0;
    free(s->a);
    s->a = NULL;
}

Stack * stack_destroy(Stack * s){
    free(s);
    return NULL;
}

int main(){
    Stack * s;
    s = stack_create(N);
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int i;
    for (i = 0; i < 9; i ++)
        stack_push(s, a[i]);
    stack_print(s);
    Data c = stack_get(s);
    printf("%d\n", c);
    Data b = stack_pop(s);
    stack_print(s);
    printf("%d\n", b);
    
    return 0;
}

