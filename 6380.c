#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left_child;
    struct Node *right_child;
    int value;
};

void insert(struct Node **root, int num);

void traverse_inorder(struct Node *root);

void delete_tree(struct Node *root);

int main(void)
{
    int n, num;
    scanf("%d", &n);

    struct Node *root = NULL;
    while (n--)
    {
        scanf("%d", &num);
        insert(&root, num);
    }
    traverse_inorder(root);
    delete_tree(root);
    return 0;
}

// #include "fun.h"
void insert(struct Node **root, int num)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(struct Node));
        (*root)->left_child = NULL;
        (*root)->right_child = NULL;
        (*root)->value = num;
    }
    else
    {
        if (num < (*root)->value)
            insert(&(*root)->left_child, num);
        else
            insert(&(*root)->right_child, num);
    }
}

void traverse_inorder(struct Node *root)
{
    if (root == NULL)
        return;
    traverse_inorder(root->left_child);
    printf("%d\n", root->value);
    traverse_inorder(root->right_child);
}

void delete_tree(struct Node *root)
{
    if (root == NULL)
        return;
    delete_tree(root->left_child);
    delete_tree(root->right_child);
    free(root);
}