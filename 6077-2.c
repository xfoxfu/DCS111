#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct TrieNode
{
    int count;
    struct TrieNode *child[63];
} TrieNode;

void init_node(TrieNode *node)
{
    for (int i = 0; i < 63; i++)
    {
        node->child[i] = NULL;
        node->count = 0;
    }
}
int norm_char(char chr)
{
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    if (chr >= 'A' && chr <= 'Z')
        return 10 + chr - 'A';
    if (chr >= 'a' && chr <= 'z')
        return 36 + chr - 'a';
    return 62;
}
int int2char(char chr)
{
    if (chr >= 0 && chr <= 9)
        return chr + '0';
    if (chr >= 10 && chr <= 35)
        return -10 + chr + 'A';
    if (chr >= 36 && chr <= 61)
        return -36 + chr + 'a';
    return '\0';
}
void free_tree(TrieNode *node)
{
    for (int i = 0; i < 63; i++)
    {
        if (node->child[i] != NULL)
            free_tree(node->child[i]);
    }
    free(node);
}

void print_tree(TrieNode *root)
{
    static int stack[STACK_SIZE];
    static int *stack_top = stack;
    if (root->child[62] != NULL)
    {
        for (int i = 0; i < root->child[62]->count; i++)
        {
            for (int *p = stack; p < stack_top; p++)
                printf("%c", int2char(*p));
            putchar('\n');
        }
    }
    for (int i = 0; i < 62; i++)
    {
        if (root->child[i] != NULL)
        {
            *(stack_top++) = i;
            print_tree(root->child[i]);
        }
    }
    stack_top--;
}

int main()
{
#ifdef DEBUG
    for (int i = 0; i < 63; i++)
    {
        printf("%2d %2c %2d\n", i, int2char(i), norm_char(int2char(i)));
    }
    freopen("6077.in", "r", stdin);
#endif
    int n;
    scanf("%d\n", &n);

    TrieNode *root = malloc(sizeof(TrieNode));
    init_node(root);

    for (int i = 0; i < n; i++)
    {
        char chr;
        TrieNode *ptr = root;
        while ((chr = getchar()) != '\n')
        {
            TrieNode *ptrchild = ptr->child[norm_char(chr)];
            if (ptrchild == NULL)
            {
                ptrchild = malloc(sizeof(TrieNode));
                init_node(ptrchild);
                ptr->child[norm_char(chr)] = ptrchild;
            }
            ptr->count++;
            ptr = ptrchild;
        }

        if (ptr->child[62] == NULL)
        {
            ptr->child[62] = malloc(sizeof(TrieNode));
            init_node(ptr->child[62]);
        }
        ptr->child[62]->count++;
    }

    print_tree(root);
    free_tree(root);
    return 0;
}
