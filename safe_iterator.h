#ifndef HEADER_SAFE_ITERATOR
#define HEADER_SAFE_ITERATOR

#include <stdlib.h>
#define TYPE int

typedef struct
{
    int size;
    TYPE *begin;
} Array;
typedef struct
{
    Array *parent;
    TYPE *curr;
    int pos;
} Iterator;

Array array_new(int size);
void array_free(Array arr);
Iterator array_at(Array *array, int pos);
Iterator array_begin(Array *array);
Iterator array_end(Array *array);
int iter_outbound(Iterator iter);
Iterator iter_seek(Iterator iter, int seek);
void iter_seek_mut(Iterator *iter, int seek);
Iterator iter_prev(Iterator iter);
void iter_prev_mut(Iterator *iter);
Iterator iter_next(Iterator iter);
void iter_next_mut(Iterator *iter);
TYPE *iter_value_s(Iterator iter);
int iter_cmp(Iterator lhs, Iterator rhs);

#endif