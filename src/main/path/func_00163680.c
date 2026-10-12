#include "types.h"
extern void func_00163920();
extern void func_001639D0();
extern void func_00163A70();
extern void * const D_004D9720[];
extern void * const D_004D9730[];
extern void * const D_004D9740[];
extern void * const D_004D9750[];
extern void operator_delete(void* p);
typedef struct { void* vt; } V_3680;
V_3680* func_00163680(V_3680* self, short flag)
{
    if (self) {
        self->vt = ((char*)D_004D9750);
        if (self) {
            V_3680* m;
            self->vt = ((char*)D_004D9740);
            m = (V_3680*)((char*)self + 0x10);
            if (m) {
                self[4].vt = ((char*)D_004D9730);
                if (m)
                    self[4].vt = ((char*)D_004D9720);
            }
            m = (V_3680*)((char*)self + 0x4);
            if (m) {
                self[1].vt = ((char*)D_004D9730);
                if (m)
                    self[1].vt = ((char*)D_004D9720);
            }
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9720[4] = { (void*)0x0, (void*)0x0, (void*)func_00163920, (void*)0x0 };
void * const D_004D9730[4] = { (void*)0x0, (void*)0x0, (void*)func_00163A70, (void*)0x0 };
void * const D_004D9740[4] = { (void*)0x0, (void*)0x0, (void*)func_001639D0, (void*)0x0 };
void * const D_004D9750[4] = { (void*)0x0, (void*)0x0, (void*)func_00163680, (void*)0x0 };
