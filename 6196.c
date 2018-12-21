#ifndef MERGESORTEDLIST_H
#define MERGESORTEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

void push_front(node **head, int val);

node *mergeSortedList(node *head1, node *head2);

#endif

// begin
#include <stdlib.h>
#ifndef MERGESORTEDLIST_H
#include "mergeSortedList.h"
#endif

void push_front(node **head, int val)
{
    node *new_head = malloc(sizeof(node));
    new_head->val = val;
    new_head->next = *head;
    *head = new_head;
}

node *mergeSortedList(node *head1, node *head2)
{
    if (head2 == NULL)
        return head1;
    if (head1 == NULL)
        return head2;
    // handle first element
    if (head2->val < head1->val)
    {
        push_front(&head1, head2->val);
        head2 = head2->next;
    }
    // handle others
    node *p1 = head1;
    for (node *p2 = head2, *p2n = p2->next; p2 != NULL; p2 = p2n, p2n != NULL ? p2n = p2n->next : NULL)
    {
        while (p1->next != NULL && p1->next->val < p2->val)
            p1 = p1->next;
        node *next = p1->next;
        p1->next = p2;
        p2->next = next;
    }
    return head1;
}
// end

void destroy(node **head)
{
    node *p = *head;
    while (p)
    {
        node *temp = p;
        p = p->next;
        free(temp);
    }
    *head = NULL;
}

void print(node *head)
{
    while (head)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    node *head1 = NULL, *head2 = NULL;
    int size, val;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &val);
        push_front(&head1, val);
    }
    print(head1);

    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &val);
        push_front(&head2, val);
    }
    print(head2);

    node *head = mergeSortedList(head1, head2);
    print(head);

    destroy(&head);
    return 0;
}