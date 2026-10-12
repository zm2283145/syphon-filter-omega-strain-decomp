#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { Q q[2]; } Name32_4640;
typedef struct { int a, b, c; } Val_4640;
typedef struct { Name32_4640 key; Val_4640* val; } Pair_4640;
typedef struct { char pad[0x44]; Tree tree; } Self_4640;
typedef struct { int node; char ins; } Res_4640;
extern "C" void func_003B47F0(Iter* out, Tree* t);
extern "C" void func_003B47E0(Iter* out, Iter* in);
extern "C" void func_001BADD0(Iter* out, Tree* t, Name32_4640* key);
extern "C" void MotionRegistry_MapInsert(Res_4640* out, Tree* t, Pair_4640* v);
extern "C" void* Mem_Alloc(int a, int size, char* file, int line);
extern "C" char D_004BCD70;
static inline void QCopy_4640(void* d0, void* s0) { int n = 2; __int128 t; void* s = s0; void* d = d0;
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
static inline Iter* ItCopy_4640(Iter* d, Iter* s) { d->p = s->p; return d; }
static inline int End_4640(Iter* out, Tree* t) { Iter e; func_003B47F0(&e, t); func_003B47E0(out, &e); return 0; }
static inline Iter* Sel_4640(Iter* a, int b) { return a; }
static inline Iter* Find_4640(Iter* out, Tree* t, Name32_4640* n) { Iter f; func_001BADD0(&f, t, n); return ItCopy_4640(out, &f); }
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void MotionRegistry_Register(Self_4640* self, Name32_4640* name, Val_4640* src)
{
    Iter c;
    Iter e2;
    if (Sel_4640(Find_4640(&c, &self->tree, name), End_4640(&e2, &self->tree))->p == e2.p) {
        Res_4640 r;
        Pair_4640 q;
        Pair_4640 p;
        Name32_4640 k;
        Val_4640* v;
        {
            AllocGuard g;
            v = (Val_4640*)Mem_Alloc(0, 0xC, &D_004BCD70, 0x27D);
        }
        if (v != 0) {
            v->a = src->a;
            v->b = src->b;
            v->c = src->c;
        }
        QCopy_4640(&k, name);
        QCopy_4640(&p.key, &k);
        p.val = v;
        QCopy_4640(&q, &p);
        q.val = p.val;
        MotionRegistry_MapInsert(&r, &self->tree, &q);
    }
}





