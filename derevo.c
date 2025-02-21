#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node Node;

struct Node {
    Data data;      // данные в узле
    Node * left;    // указатель на левого ребенка
    Node * right;   // указатель на правого ребенка
};

void tree_print(Node * tree) {
    if (tree == NULL)
        return;     
    tree_print(tree->left);
    printf("%d ", tree->data); 
    tree_print(tree->right);
}

Node * tree_add(Node * tree, Data d) {
    if (tree == NULL) {
        Node * p = malloc(sizeof(Node));    // создаем узел
        p->data = d;                        // записываем в него 7
        p->left = p->right = NULL;          // детей нет
        return p;                           // вернуть указатель на новый узел
    }
    if (d < tree->data)
        tree->left = tree_add(tree->left, d);   // запомним указатель на узел 3
    if (d > tree->data)
        tree->right = tree_add(tree->right, d); // запомним указатель на узел 9
    return tree;
}

Node * tree_destroy(Node * tree) {
    // для пустого дерева ничего не делаем
    if (tree == NULL)
        return NULL;
    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);
    return NULL;
}
int main () {
    Node * tree = NULL;

    Data test_data[] = {7, 3, 2, 1, 9, 5, 4, 6};
    for(size_t i = 0; i < sizeof(test_data)/sizeof(test_data[0]); i++) {
        tree = tree_add(tree, test_data[i]);
    }

    tree_print(tree);       // 1 2 3 4 5 6 7 8 9
    return 0;
}
