#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct E25DBD0 { __int128 q; ~E25DBD0() {} };
struct V25DBD0 { unsigned int cap; unsigned int count; E25DBD0* data; };
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_dead_code off
#pragma opt_loop_invariants off
extern "C" {
extern char D_004A7D10[];
extern char D_0049CEB8[];
extern char D_0049CEA8[];
void func_00181080(V25DBD0* a, V25DBD0* b);
}
static inline void Construct25DBD0(E25DBD0* p, const E25DBD0* s) { if (p) *p = *s; }
extern "C" void Vector_Reserve_25DBD0(V25DBD0* v, unsigned int n)
{
    if (v->cap < n) {
        unsigned int max = 0x600000;
        if (n > max) {
            Libc_Fprintf(D_00489738->stream, D_004A7D10);
            Libc_Abort();
        }
        V25DBD0 tmp;
        tmp.cap = 0;
        tmp.count = 0;
        tmp.data = 0;
        tmp.data = (E25DBD0*)TStr_Alloc(n * sizeof(E25DBD0), D_0049CEB8, 0x5C);
        { unsigned int* pc = &tmp.cap; *pc = n; }
        E25DBD0* d = tmp.data;
        E25DBD0* s = v->data;
        E25DBD0* e = s + v->count;
        for (; s < e; s++, d++) {
            Construct25DBD0(d, s);
            tmp.count++;
        }
        func_00181080(&tmp, v);
        {
            E25DBD0* b_ = tmp.data;
            E25DBD0* e_ = b_ + tmp.count;
            while (b_ < e_) (--e_)->~E25DBD0();
            E25DBD0* fp_ = tmp.data;
            tmp.count = 0; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049CEA8, 0x64); }
        }
    }
}

