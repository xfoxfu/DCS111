#ifndef TREE_NODE_H
#define TREE_NODE_H

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

#endif

// begins

#include <stdlib.h>
#ifndef TREE_NODE_H
#include "TreeNode.h"
#endif

TreeNode *reConstructBinaryTree(int pre[], int in[], int size)
{
    if (size == 0)
        return NULL;
    TreeNode *node = malloc(sizeof(TreeNode));
    node->val = pre[0];
    int *pValIn;
    for (pValIn = in; *pValIn != pre[0]; pValIn++)
        ;
    int left_size = pValIn - in;
    node->left = reConstructBinaryTree(pre + 1, in, left_size);
    node->right = reConstructBinaryTree(pre + 1 + left_size, in + left_size + 1, size - left_size - 1);
    return node;
}
void deleteTree(TreeNode *root)
{
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

// end

#include <stdio.h>

void postOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

int main()
{
    int preOrder[100], inOrder[100];
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &preOrder[i]);
    }
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &inOrder[i]);
    }

    TreeNode *root = reConstructBinaryTree(preOrder, inOrder, size);
    postOrder(root);
    printf("\n");
    deleteTree(root);
    root = NULL;
    return 0;
}
