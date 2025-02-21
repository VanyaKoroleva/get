#include<stdio.h>
#include<stdlib.h>

typedef int Data;

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};

void tree_print(struct Node * tree){
    if (tree == NULL)
        return;
    tree_print(tree->left);
    printf("%d ", tree->val);
    tree_print(tree->right);
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
    scanf("%d", &x);
    while (x != 0)
    {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }
    tree_print(tree);
    tree_destroy(tree);
        
    return 0;
}
