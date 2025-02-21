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
    if (tree->left == NULL && tree->right == NULL)
        printf("%d ", tree->val);
    tree_print(tree->left);
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

int max(int a, int b){
    return a > b ? a : b;
}

int tree_height(struct Node * tree){
    if (tree == NULL)
        return 0;
    
    return max(tree_height(tree->left) + 1, tree_height(tree->right) + 1);
}

int proverka(struct Node * tree){
    if (tree == NULL)
        return 1;
    if (abs(tree_height(tree->left) - tree_height(tree->right)) > 1)
        return 0;
    return (proverka(tree->left) * proverka(tree->right));
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

    if(proverka(tree))
        printf("YES");
    else
        printf("NO");
    tree_destroy(tree);       
    return 0;
}
