#include <stdlib.h>
#ifndef MERGESORTEDLIST_H
#include "list.h"
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
