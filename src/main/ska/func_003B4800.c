#include "types.h"
typedef struct { Q q[3]; } Name48_4800;
typedef struct { Name48_4800 key; int val; } Pair_4800;
typedef struct { char pad[0x24]; Tree tree; char vec[4]; int count; } Self_4800;
typedef struct { int node; char ins; } Res_4800;
extern void func_003B4990(Iter* out, Tree* t);
extern void func_003B4980(Iter* out, Iter* in);
extern void Tree_Compare(Iter* out, Tree* t, Name48_4800* key);
extern void func_003B83D0(Res_4800* out, Tree* t, Pair_4800* v);
extern int func_003B4960(void* v, int* value);
extern int D_004BCD60;
static inline void QCopy_4800(void* d0, void* s0) { int n = 3; __int128 t; void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline Iter* ItCopy_4800(Iter* d, Iter* s) { d->p = s->p; return d; }
#pragma opt_common_subs off
#pragma opt_propagation off
void ModelNames_Insert(int* out, Self_4800* self, Name48_4800* name, int value)
{
    if (value != 0) {
        Iter c;
        Iter e2;
        Iter f;
        Iter e;
        Iter* pc;
        func_003B4990(&e, &self->tree);
        func_003B4980(&e2, &e);
        Tree_Compare(&f, &self->tree, name);
        if (ItCopy_4800(&c, &f)->p == e2.p) {
            Res_4800 r;
            Pair_4800 q;
            Pair_4800 p;
            Name48_4800 k;
            int n = self->count;
            QCopy_4800(&k, name);
            QCopy_4800(&p.key, &k);
            p.val = n;
            QCopy_4800(&q, &p);
            q.val = p.val;
            func_003B83D0(&r, &self->tree, &q);
            func_003B4960(self->vec, &value);
            *out = self->count - 1;
        } else {
            *out = D_004BCD60;
        }
    } else {
        *out = D_004BCD60;
    }
}




