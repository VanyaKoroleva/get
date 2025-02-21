#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
    Data val;               
    struct Node * next;     
};

struct Node * list_create (){
    return NULL;
}

void list_push (struct Node ** plist, Data x){
    struct Node * p = malloc(sizeof(struct Node));
    p->val = x;
    p->next = *plist;
    *plist = p;
}

Data list_pop (struct Node ** plist){
    struct Node * p = *plist;      
    Data res = p->val;     
    *plist = p->next;       
    free(p);                
    return res;             
}

Data list_get(struct Node * list){
    return list->val;
}

void list_print (struct Node * list){
    struct Node * p;
    for(p = list; p != NULL; p = p->next)
       printf("%d ", p->val);
    printf("\n");
}

int list_size(struct Node * list){
    int i;
    struct Node * p;
    for(i = 0, p = list; p != NULL; p = p->next, i++);
    return i;
}

void list_clear(struct Node ** plist){
    struct Node * p;  
    while(*plist != NULL){
        p = *plist;           
        *plist = p->next;       
        free(p);
    }                    
}

int list_is_empty (struct Node * list){
    return(list == NULL);
}

int main(){
    struct Node * list = list_create();
    list_print(list);
    list_push(&list, 1);
    list_print(list);
    list_push(&list, 2);
    list_print(list);
    // printf("%d\n", list_get(list));
    printf("%d\n", list_size(list));
    list_clear(&list);
    printf("%d\n", list_size(list));

    return 0;
}