#include "types.h"
typedef struct { void* vt; } TC670;
extern char D_004E0EE0[];
extern void cMessage_dtor(void* self, short del);
extern void operator_delete(void* p);
TC670* func_003CC670(TC670* self, short del)
{
    if (self) {
        self->vt = D_004E0EE0;
        cMessage_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
