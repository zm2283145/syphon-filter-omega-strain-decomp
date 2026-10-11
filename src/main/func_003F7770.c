#include "types.h"
typedef struct { char data[0x50000]; int head; int count; int size; } T7770;
int func_003F7770(T7770* t, int n)
{
    int size = t->size;
    int k = size - t->count < n ? size - t->count : n;
    t->head = (t->head + k) % size;
    t->count += k;
    return k;
}
