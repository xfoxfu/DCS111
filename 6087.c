#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

int size;   // the size of linked list
node *head; // the head of linkedlist

//insert the value to the right position
//if the position is not valid, return false
//if insert successfully, return true
bool insert(int position, int value);

// return the value in the given position
int get(int position);

//clear the linkedlist, remember to free the memory you allocated
void clear();

#endif

#include <stdlib.h>
#include <stdbool.h>
extern int size;
extern struct node;
typedef struct node node;
extern node *head;

node *get_ptr(int position)
{
    node *pn = head;
    for (int offset = 0; offset < position; offset++)
        pn = pn->next;
    return pn;
}
bool insert(int position, int value)
{
    if (position > size || position < 0)
        return false;
    if (position == 0)
    {
        node *pnext = head;
        head = malloc(sizeof(node));
        head->value = value;
        head->next = pnext;
    }
    else
    {
        node *pnext = get_ptr(position);
        node *pnew = malloc(sizeof(node));
        pnew->value = value;
        pnew->next = pnext;
        get_ptr(position - 1)->next = pnew;
    }
    size++;
    return true;
}
int get(int position)
{
    return get_ptr(position)->value;
}
void clear()
{
    for (int i = size - 1; i >= 0; i--)
        free(get_ptr(i));
}

#include <stdio.h>

void print()
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", get(i));
    }
    printf("\n");
}

int main()
{
    head = NULL;
    size = 0;
    int n, i, position, value;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &position, &value);
        if (insert(position, value))
        {
            print();
        }
        else
        {
            printf("position is not valid\n");
        }
    }
    clear();
    return 0;
}