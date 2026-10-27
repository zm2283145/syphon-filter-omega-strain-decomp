#include "types.h"
typedef struct { int first; char data[0x4CE3C]; } E6040;
typedef struct { int m0; E6040* base; int head; int count; int size; } T6040;
void voBufCreate(T6040* q, int m0, E6040* base, int size)
{
    int i;
    q->m0 = m0;
    q->base = base;
    q->size = size;
    q->count = 0;
    q->head = 0;
    for (i = 0; i < size; i++)
        q->base[i].first = 0;
}