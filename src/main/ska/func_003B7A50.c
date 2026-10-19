#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
#include "vc_copy.h"
struct Q3B7A50 { __int128 q; };
struct E3B7A50 { int a; float b; unsigned char c; Q3B7A50 v; ~E3B7A50() {} };
struct V3B7A50 { unsigned int cap; unsigned int count; E3B7A50* data; };
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_code off
#pragma opt_loop_invariants off
extern "C" {
extern char D_004BCE80[];
extern char D_004BCFC8[];
extern char D_004BC4C0[];
void func_003B7A10(V3B7A50* a, V3B7A50* b);
}
/* element copy: three scalar fields, then the quadword through unfolded pointers (VCopyF idiom) */
static inline void Construct3B7A50(E3B7A50* p, const E3B7A50* s) { if (p) { p->a = s->a; p->b = s->b; p->c = s->c; { void* dv = &p->v; const void* sv = &s->v; VCopyF(dv, sv); } } }
extern "C" void func_003B7A50(V3B7A50* v, unsigned int n)
{
    if (v->cap < n) {
        unsigned int max = 0x300000;
        if (n > max) {
            func_00123BE8(D_00489738->stream, D_004BCE80);
            Libc_Abort();
        }
        V3B7A50 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E3B7A50*)TStr_Alloc(n * sizeof(E3B7A50), D_004BCFC8, 0x5C);
        { unsigned int* pc = &tmp.cap; *pc = n; }
        E3B7A50* d = tmp.data;
        E3B7A50* s = v->data;
        E3B7A50* e = s + v->count;
        for (; s < e; s++, d++) {
            Construct3B7A50(d, s);
            tmp.count++;
        }
        func_003B7A10(&tmp, v);
        {
            E3B7A50* b_ = tmp.data;
            E3B7A50* e_ = b_ + tmp.count;
            while (b_ < e_) (--e_)->~E3B7A50();
            E3B7A50* fp_ = tmp.data;
            tmp.count = 0; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004BC4C0, 0x64); }
        }
    }
}

