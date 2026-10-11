#include "types.h"
typedef struct { char data[0x50000]; int head; int count; int size; } T77F0;
int func_003F77F0(T77F0* t, char** out)
{
    int f = t->size - t->count;
    if (f)
        *out = t->data + t->head;
    return f;
}
