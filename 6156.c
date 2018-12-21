#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *left;
    struct Node *right;
    int value;
} Node;
Node *init_root(int value);
Node *create_node(int value);
void insert_node(Node *p, int value);
void traverse_tree_inorder(Node *p);
void recycle_nodes(Node *p);

void traverse_tree_inorder(Node *p)
{
    if (p->left != NULL)
        traverse_tree_inorder(p->left);
    printf("%d ", p->value);
    if (p->right != NULL)
        traverse_tree_inorder(p->right);
}
void recycle_nodes(Node *p)
{
    if (p->left != NULL)
        recycle_nodes(p->left);
    if (p->right != NULL)
        recycle_nodes(p->right);
    free(p);
}
void insert_node(Node *p, int value)
{
    if (value < p->value)
    {
        if (p->left != NULL)
            insert_node(p->left, value);
        else
            p->left = init_root(value);
    }
    if (value > p->value)
    {
        if (p->right != NULL)
            insert_node(p->right, value);
        else
            p->right = init_root(value);
    }
}
Node *init_root(int value)
{
    Node *root = malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    root->value = value;
    return root;
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int node_num, i = 0, temp;
    Node *root = NULL;
    scanf("%d", &node_num);
    while (i < node_num)
    {
        scanf("%d", &temp);
        if (i == 0)
            root = init_root(temp);
        else
            insert_node(root, temp);
        i++;
    }
    traverse_tree_inorder(root);
    printf("\n");
    recycle_nodes(root);
    return 0;
}
