#include "types.h"
typedef struct { __int128 q; } Q5600;
typedef struct { unsigned char b0; float dist; char pad8[8]; Q5600 pos; Q5600 v; } E5600;
typedef struct { int f0; int count; int max; int fC; E5600 e[6]; } G5600;
typedef struct { int max; int pad4[3]; G5600 g[1]; } S5600;
extern int D_005392D0;
#define IDX5600(s) (*(int*)((char*)(s) + 0x11768))
static inline int Min5600(int a, int b) { int r; if (a < b) { r = a; asm { .set reorder } } else r = b; return r; }
#pragma peephole on
#pragma opt_rotateloops off
#pragma opt_common_subs off


void Shadow_AddLightEntries(S5600* s, Q5600* v, float dist)
{
    if (D_005392D0 & 0x20) {
        Q5600 zero;
        int slot;
        G5600* g;
        char* p;
        int lim;
        int n;
        int i;
        ((int*)&zero)[0] = 0;
        ((int*)&zero)[1] = 0;
        ((int*)&zero)[2] = 0;
        ((int*)&zero)[3] = 0;
        if (dist <= 0.0f)
            return;
        p = (char*)s + IDX5600(s)*sizeof(G5600);
        g = (G5600*)(p + 0x10);
        lim = Min5600(s->max, *(int*)(p + 0x18));
        n = g->count;
        slot = -1;
        if (n < lim) {
            slot = n;
            g->count = n + 1;
        } else {
            for (lim = 0; lim < n; lim++) {
                if (((E5600*)(lim*sizeof(E5600) + (char*)g->e))->dist < dist) {
                    slot = lim;
                    break;
                }
            }
        }
        if (slot >= 0) {
            Q5600* zp = &zero;
            int k = 1;
            G5600* e = (G5600*)(slot*sizeof(E5600) + (char*)g->e - 0x10);
            e->e[0].b0 = k;
            asm { .set reorder } /* sched barrier */
            { Q5600* d = &e->e[0].pos; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(zp) : "memory"); }
            ((G5600*)(slot*sizeof(E5600) + (char*)g))->e[0].v = *v;
            ((E5600*)(slot*sizeof(E5600) + (char*)g->e))->dist = dist;
        }
    }
}


