#include "types.h"
typedef struct { char data[0x50000]; int head; int count; int size; } T7710;
int func_003F7710(T7710* t, char** out)
{
    int c = t->count;
    if (c)
        *out = t->data + (t->size + (t->head - c)) % t->size;
    return t->count;
}
