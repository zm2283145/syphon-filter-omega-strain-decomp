#include "types.h"
extern char D_004DAD90[];
extern char D_004DA330[];
extern void func_001810D0(void* p, int f);
extern void operator_delete(void* p);
typedef struct { void* vt; } V_EF30;
V_EF30* func_0017EF30(V_EF30* self, short flag)
{
    if (self) {
        void* m;
        self->vt = D_004DAD90;
        m = (char*)self + 0x30;
        if (m) {
            if (m) {
                if (m)
                    func_001810D0(m, 0);
            }
        }
        if (self)
            self->vt = D_004DA330;
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}