#include "types.h"
typedef struct { short a; short b; unsigned short val; unsigned short id; } E2F3250;
unsigned short func_002F3250(char* base, E2F3250* k, int v)
{
    unsigned short id = k->id;
    E2F3250* e = (E2F3250*)(base + (id & 0xFF) * 8 + 0x40);
    if (e->id == id) return e->val;
    *e = *k;
    e->val = v;
    return 0xFFFF;
}