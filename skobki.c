#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

typedef char Data;

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
        printf("%c ", s->a[i]);
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
    Data * start_c = "([{<";
    Data * end_c = ")]}>";
    Stack * s = stack_create(N);
    Data p;
    Data c;
    while(1 == scanf("%c", &c)){
        if(strchr(end_c, c) == NULL)  // если скобка открывающаяся
            stack_push(s, c);
        else{ //если закрывающаяся
            p = stack_pop(s);
            // printf("%d, %d", index(start_c, p), index(end_c, c));
            if (index(start_c, p) != index(end_c, c)){
                printf("NO1\n");
                s = stack_destroy(s);
                return 0;
            }
        }    
    }
    printf("%d\n", stack_size(s));  
    if (stack_is_empty(s))
        printf("YES\n");
    else
        printf("NO2\n");
    s = stack_destroy(s);
    return 0;
}