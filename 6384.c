#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;
void insert(struct Node **root, int num)
{
    if (*root == NULL)
    {
        *root = malloc(sizeof(struct Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->value = num;
    }
    else
    {
        if (num < (*root)->value)
            insert(&(*root)->left, num);
        else
            insert(&(*root)->right, num);
    }
}
void delete_tree(struct Node *root)
{
    if (root == NULL)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}
bool has_number(struct Node *root, int num)
{
    if (root == NULL)
        return false;
    else if (root->value == num)
        return true;
    else
    {
        if (num < root->value)
            return has_number(root->left, num);
        else
            return has_number(root->right, num);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int id;
        scanf("%d", &id);
        insert(&root, id);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int id;
        scanf("%d", &id);
        bool result = has_number(root, id);
        if (result)
            printf("Yes\n");
        else
            printf("No\n");
    }
    delete_tree(root);
    return 0;
}