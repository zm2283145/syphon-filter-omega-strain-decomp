#include "types.h"
typedef struct { int pad; int count; void** data; } Vec40B830;
typedef struct { void* vt; char m4[0x10]; char m14[0xC]; } Obj40B830;
extern Vec40B830* func_0040BCC0(void);
extern void PtrVector_Resize(Vec40B830* v, int n, int* fill);
extern void func_00175240(void* p, int f);
extern void func_0040B920(void* p, int f);
extern void operator_delete(void* p);
static inline void D1_40B830(void* p) { if (p) func_00175240(p, 0); }
static inline void D2_40B830(void* p) { if (p) D1_40B830(p); }
static inline void D3_40B830(void* p) { if (p) D2_40B830(p); }
#pragma push
#pragma inline_depth(10)
#pragma opt_strength_reduction off
Obj40B830* func_0040B830(Obj40B830* self, short del)
{
    if (self) {
        Vec40B830* v = func_0040BCC0();
        int i;
        int last = v->count - 1;
        int zero;
        for (i = 0; !(last < i); i++) {
            if (v->data[i] == self) {
                v->data[i] = v->data[last];
                last--;
            }
        }
        zero = 0;
        PtrVector_Resize(v, last + 1, &zero);
        D3_40B830(self->m14);
        if (self->m4) func_0040B920(self->m4, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop
