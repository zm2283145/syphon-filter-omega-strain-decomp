#include "types.h"
typedef struct { Q q[3]; } Name48_4800;
typedef struct { Name48_4800 key; int val; } Pair_4800;
typedef struct { char pad[0x24]; Tree tree; char vec[4]; int count; } Self_4800;
typedef struct { int node; char ins; } Res_4800;
extern void std_map_cString16N_3_int_cAllocator_pair_end_void_2(Iter* out, Tree* t);
extern void cAssocArray_cString16N_3_int_Iterator_ctor(Iter* out, Iter* in);
extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(Iter* out, Tree* t, Name48_4800* key);
extern void std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR(Res_4800* out, Tree* t, Pair_4800* v);
extern int std_vector_cSkaNodePtr_push_back(void* v, int* value);
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
void cSkaAnimationSet_AddNode(int* out, Self_4800* self, Name48_4800* name, int value)
{
    if (value != 0) {
        Iter c;
        Iter e2;
        Iter f;
        Iter e;
        Iter* pc;
        std_map_cString16N_3_int_cAllocator_pair_end_void_2(&e, &self->tree);
        cAssocArray_cString16N_3_int_Iterator_ctor(&e2, &e);
        std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(&f, &self->tree, name);
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
            std_tree_pair_cString16N_value_compare_cAllocator_pair_insert_one_pairR(&r, &self->tree, &q);
            std_vector_cSkaNodePtr_push_back(self->vec, &value);
            *out = self->count - 1;
        } else {
            *out = D_004BCD60;
        }
    } else {
        *out = D_004BCD60;
    }
}




