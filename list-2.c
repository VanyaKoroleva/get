#include <stdio.h>
#include <stdlib.h>
#define N 1000000

typedef int Data;
struct Node {
    struct Node * next;
    struct Node * prev;
    Data data;
};

int list_is_empty(struct Node * list) {
    return list->next == list;
}

void list_init(struct Node * list) {
    list->next = list->prev = list;
}

void list_insert (struct Node * list, struct Node * t){
    struct Node * p = list->next;
    t->next = p;
    t->prev = list;
    p->prev = t;
    list->next = t;
}

void list_insert_before(struct Node * q, struct Node * t) {
    list_insert(q->prev, t);
}

void list_remove(struct Node * t) {
    struct Node * p = t->prev;
    struct Node * q = t->next;
    p->next = q;
    q->prev = p;
}

void list_print(struct Node * list) {
    for (struct Node * p = list->next; p != list; p = p->next) {
        printf("%d ", p->data);
    }
    printf("\n");
}

struct Node * list_push_front (struct Node * list, Data d){
    struct Node * p = malloc(sizeof(struct Node));   
    p->data = d;                        
    list_insert(list, p);             
    return p;    
}

struct Node * list_push_back (struct Node * list, Data d){
    return list_push_front(list->prev, d);
}

Data list_delete (struct Node * t){
    Data res = t->data;     
    list_remove(t);         
    free(t);                
    return res;
}

Data list_pop_front (struct Node * list){
    return list_delete(list->next);
}

Data list_pop_back(struct Node * list) {
    return list_delete(list->prev);
}

void list_clear (struct Node * list){
    while( ! list_is_empty(list))
        list_pop_front(list);
}

void list_destroy(struct Node * list){
    list_clear(list);
    free(list);
}
void print(struct Node * a, struct Node * b){
    list_print(a);
    list_print(b);
}

int main()
{
    struct Node * a = malloc(sizeof(struct Node));
    struct Node * b = malloc(sizeof(struct Node));
    list_init(a);
    list_init(b);
    int i, x, y;

    for (i = 0; i < 5; i ++){
        scanf("%d", &x);
        list_push_back(a, x);
    }

    for (i = 0; i < 5; i ++){
        scanf("%d", &y);
        list_push_back(b, y);
    }

    for(i = 0; i < N; i ++){

        if (list_is_empty(b)){
            printf("first %d\n", i);
            goto END;
        }
        if (list_is_empty(a)){
            printf("second %d\n", i);
            
            goto END;
        }

        x = list_pop_front(a);
        y = list_pop_front(b);
        if ((x > y && !(x == 9 && y == 0)) || (x == 0 && y == 9)){
            list_push_back(a, x);
            list_push_back(a, y);
        }
        else{
            list_push_back(b, x);
            list_push_back(b, y);
        }
        // print(a, b);
        // printf("----\n");
    }
    printf("botva\n");
END:
    list_destroy(a);
    list_destroy(b);
    return 0;
}
