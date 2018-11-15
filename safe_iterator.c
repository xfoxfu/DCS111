#include <stdlib.h>

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

Array array_new(int size)
{
    Array arr = {size, calloc(sizeof(TYPE), size)};
    return arr;
}
void array_free(Array arr)
{
    free(arr.begin);
    arr.size = 0;
}
Iterator array_at(Array *array, int pos)
{
    Iterator iter = {array, array->begin + pos, pos};
    return iter;
}
Iterator array_begin(Array *array)
{
    return array_at(array, 0);
}
Iterator array_end(Array *array)
{
    return array_at(array, array->size - 1);
}
int iter_outbound(Iterator iter)
{
    return iter.pos >= iter.parent->size || iter.pos < 0;
}
Iterator iter_seek(Iterator iter, int seek)
{
    iter.pos += seek;
    iter.curr += seek;
    return iter;
}
void iter_seek_mut(Iterator *iter, int seek)
{
    iter->pos += seek;
    iter->curr += seek;
}
Iterator iter_prev(Iterator iter)
{
    return iter_seek(iter, -1);
}
void iter_prev_mut(Iterator *iter)
{
    iter_seek_mut(iter, -1);
}
Iterator iter_next(Iterator iter)
{
    return iter_seek(iter, 1);
}
void iter_next_mut(Iterator *iter)
{
    iter_seek_mut(iter, 1);
}
TYPE *iter_value_s(Iterator iter)
{
#ifdef SAFE_WARNING
    if (iter_outbound(iter))
        printf("[WARNING] 0..%d..%d\n", iter.pos, iter.parent->size);
#endif
    return iter.curr;
}
int iter_cmp(Iterator lhs, Iterator rhs)
{
    return lhs.curr - rhs.curr;
}