#include "types.h"
typedef struct { char p[0x10]; unsigned char b10; } H3FA1B0;
typedef struct { char p[0x50C]; H3FA1B0* h; } M3FA1B0;
void func_003FA1B0(M3FA1B0* m, int on)
{
    if (m->h) m->h->b10 = on ? 3 : 2;
}
