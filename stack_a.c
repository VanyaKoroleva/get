#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef int Data;

typedef struct{
    int n;
    int Size;
    Data * a;
} Stack;

Stack * stack_create(int size){
    Stack * st = malloc(sizeof(Stack));
    st->n = 0;
    st->Size = size;
    st->a = malloc(size * sizeof(Data));
}

int stack_is_full(Stack * s){
    return (s->n == s->Size);
}

void stack_push(Stack * s, Data x){
    if (stack_is_full(s)){
        s->Size += N;
        s->a = realloc(s->a, s->Size * sizeof(Data));
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
    printf("%d\n", stack_pop(s));
    printf("%d\n", stack_get(s));
    stack_print(s);
    
    return 0;
}






