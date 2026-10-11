#include "types.h"
extern char D_004D95B0[];
extern void func_0015CA10(void* p);
extern void func_0015CA20(void* p, int flag);
extern void cGOBJ_dtor(void* self, int flag);
extern void operator_delete(void* p);
typedef struct { void* vt; } S_C2F0;
#pragma opt_common_subs off
S_C2F0* cNode_dtor(S_C2F0* self, short flag)
{
    if (self) {
        void* m;
        self->vt = D_004D95B0;
        func_0015CA10((char*)self + 0x68);
        m = (char*)self + 0x68;
        if (m) {
            if (m) {
                if (m)
                    func_0015CA20(m, 0);
            }
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
#pragma opt_common_subs reset
