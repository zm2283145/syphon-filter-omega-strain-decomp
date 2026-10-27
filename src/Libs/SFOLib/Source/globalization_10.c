/*
 * Libs/SFOLib/Source/globalization: 2 files, 003FEC90-003FECD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FEC90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * globalization.cc: pointer-vector swap.
 */

#include "types.h"

/* Swap the contents of two pointer vectors. */
void std_swap_vectordeleterR_vectordeleterR_46(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_003FEC90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FEC90 */

/* merge_units: begin func_003FECD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#pragma inline_depth(10)

inline void* operator new(unsigned int, void* p) { return p; }
struct E_3FECD0 { __int128 q; E_3FECD0(const E_3FECD0& o) { q = o.q; } };
struct Vec_3FECD0 { unsigned int cap; unsigned int count; E_3FECD0* data; };
typedef struct { char pad[0xC]; void* stream; } Err_3FECD0;
extern "C" {
extern Err_3FECD0* D_00489738;
extern char D_004BE520[];
extern char D_004BE530[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
void Libc_Abort(void);
void Libc_Fprintf(void* s, char* msg);
#if 0 /* merge_units */
void std_swap_vectordeleterR_vectordeleterR_46(Vec_3FECD0* a, Vec_3FECD0* b);
#endif /* merge_units */
#define std_swap_vectordeleterR_vectordeleterR_46(a0, a1) (std_swap_vectordeleterR_vectordeleterR_46((PtrVec *)(a0), (PtrVec *)(a1))) /* merge_units */

void func_003F4390(Vec_3FECD0* a);
}

static inline E_3FECD0* Alloc_3FECD0(unsigned int n) { AllocGuard g; return (E_3FECD0*)cMemMan_Allocate(0, n * sizeof(E_3FECD0), D_004BE530, 0x5C); }
#pragma push
#pragma peephole off
#pragma opt_propagation off
extern "C" void std_vector_imp_1_reserve(Vec_3FECD0* v0, unsigned int n0)
{
    Vec_3FECD0* v = v0;
    unsigned int n = n0;
    if (v0->cap < n) {
        if (n > 0x600000) {
            Libc_Fprintf(D_00489738->stream, "vector::reserve length error\n");
            Libc_Abort();
        }
        {
            E_3FECD0* d; E_3FECD0* s; E_3FECD0* e; Vec_3FECD0 tmp;
            tmp.cap = 0;
            tmp.count = 0;
            tmp.data = 0;
            tmp.data = Alloc_3FECD0(n);
            tmp.cap = n;
            s = v->data;
            e = s + v->count;
            d = tmp.data;
            for (; s < e; s++, d++) {
                new (d) E_3FECD0(*s);
                tmp.count++;
            }
            std_swap_vectordeleterR_vectordeleterR_46(&tmp, v);
            tmp.count = 0;
            {
                E_3FECD0* p = tmp.data;
                if (p) { if (p) { AllocGuard g; cMemMan_Deallocate(0, p, D_004BE520, 0x64); } }
            }
        }
    }
}
#pragma pop
#undef std_swap_vectordeleterR_vectordeleterR_46 /* merge_units */
static inline void merge_flush_func_003FECD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FECD0 */
