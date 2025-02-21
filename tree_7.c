#include<stdio.h>
#include<stdlib.h>

typedef int Data;

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};
typedef struct Node * ListData;
typedef struct {
    int n;
    int size;
    struct Node * a;
    ListData tree_node;
} Stack;

Stack * stack_create(int size){
    Stack * st = malloc(sizeof(Stack));
    st->n = 0;
    st->size = size;
    st->a = malloc(size * sizeof(struct Node));
    return st;
}

int stack_is_full(Stack * s){
    return (s->n == s->size);
}

void stack_push(Stack * s, struct Node * x){
    s->a[s->n] = x;
    s->n ++;
}

Data stack_pop(Stack * s){
    return((s->a[--s->n]).val);
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

struct Node * tree_add(struct Node * tree, Data x){
    if (tree == NULL){
        struct Node * res = malloc(sizeof(struct Node));
        res->val = x;
        res->left = NULL;
        res->right= NULL;
        return res;
    }
    if(x > tree->val)
        tree->right = tree_add(tree->right, x);
    if(x < tree->val)
        tree->left = tree_add(tree->left, x);
    return tree;

} 

void tree_destroy (struct Node * tree){
    if (tree == NULL)
        return;
    tree_destroy(tree->right);
    tree_destroy(tree->left);
    free(tree);
}

int main(){
    int x;
    struct Node * tree = NULL;
    Stack * s = stack_create(10);
    scanf("%d", &x);
    while (x != 0)
    {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }

    stack_push(s, tree)

    
    tree_destroy(tree);   
    return 0;
}