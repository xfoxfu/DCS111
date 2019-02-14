#include <stdlib.h>
struct Node
{
    struct Node *next;
    int value;
};

void insert(struct Node **head, int num);

void print_linklist(struct Node *head);

void delete_linklist(struct Node *head);

// #include "fun.h"
#include <stdio.h>

void insert(struct Node **head, int num)
{
    if (*head != NULL && num > (*head)->value)
        insert(&(*head)->next, num);
    else
    {
        struct Node *next = *head;
        *head = malloc(sizeof(struct Node));
        (*head)->value = num;
        (*head)->next = next;
    }
}

void print_linklist(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->value);
        head = head->next;
        if (head != NULL)
            putchar(' ');
    }
    putchar('\n');
}

void delete_linklist(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *next = head->next;
    free(head);
    delete_linklist(next);
}

#include <stdio.h>

int main(void)
{
    int n, num;
    scanf("%d", &n);

    struct Node *head = NULL;
    while (n--)
    {
        scanf("%d", &num);
        insert(&head, num);
    }
    print_linklist(head);
    delete_linklist(head);
}
