#pragma opt_unroll_loops off
#include "types.h"
typedef struct {
    int key;
    unsigned int ofs;
} Pair8550;
typedef struct {
    int count;
    Pair8550 pairs[20];
} Group8550;
typedef struct {
    unsigned int base[7];
    int group[7];
    int f38;
    char pad[0x94 - 0x3C];
} Obj8550;
extern Group8550 D_00493530[];
extern unsigned int D_004937E0[];
extern void* memset(void*, int, unsigned int);
Obj8550* func_003C8550(Obj8550* o)
{
    int i;
    int j;
    unsigned int k;
    unsigned int acc;
    int n;
    Pair8550* p;
    Group8550* g;
    unsigned int* b;
    unsigned int* end;

    memset(o, 0, sizeof(Obj8550));
    o->f38 = -1;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_00493530[i].count; j++) {
            o->group[D_00493530[i].pairs[j].key] = i;
        }
    }
    k = 0;
    acc = 0;
    n = 0;
    g = D_00493530;
    b = o->base;
    end = D_004937E0;
    for (; n < 7; n++, b++) {
        *b = acc;
        p = &g->pairs[k];
        if (k < g->count - 1) {
            acc += (g->pairs[k + 1].ofs - p->ofs) / 8;
        } else {
            acc += (*end - p->ofs) / 8;
        }
        k++;
        if (k == g->count) {
            g++;
            end++;
            k = 0;
            acc = 0;
        }
    }
    return o;
}




