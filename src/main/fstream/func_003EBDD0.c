#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Sub_EBDD0 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};

extern "C" {
extern char D_004BE010;
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
int func_0011A668(unsigned long p, int align);
}

static inline void* Alloc_EBDD0(unsigned int n)
{
    AllocGuard g;
    return Mem_Alloc(1, n, &D_004BE010, 0x37);
}

extern "C" int func_003EBDD0(Sub_EBDD0* s, int size)
{
    int n = size + 0x7F;
    if (s->n0) {
        s->bC = 1;
        return 1;
    }
    s->n0 = (int)Alloc_EBDD0(n);
    if (s->n0) {
        unsigned long u = (unsigned int)s->n0;
        if (func_0011A668(u, 0x40))
            s->n8 = (int)((u + 0x7F) / 0x80 * 0x80);
        else
            s->n8 = 0;
        s->n4 = n;
        s->bC = 0;
        return 1;
    }
    return 0;
}



