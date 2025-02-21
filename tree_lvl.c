#include<stdio.h>
#include<stdlib.h>

typedef int Data;

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};

void tree_print_n(struct Node * tree, int n){
    if (tree == NULL)
        return;
    if (n == 0){
        printf("%d ", tree->val);
        return;
    }
    tree_print_n(tree->left, n - 1);
    tree_print_n(tree->right, n - 1);

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
    int x, n;
    struct Node * tree = NULL;
    scanf("%d", &x);
    while (x != 0)
    {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }
    scanf("%d", &n);
    tree_print_n(tree, n);
    tree_destroy(tree);       
    return 0;
}