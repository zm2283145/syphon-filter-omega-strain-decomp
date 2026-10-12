#include "types.h"
typedef struct { char pad[0x10]; void* vt; } TC8E0;
extern void * const D_004E00A8[];
extern void func_003D2850(void* self, short del);
extern void operator_delete(void* p);
TC8E0* func_003D27E0(TC8E0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E00A8);
        if (self)
            func_003D2850(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E00A8[3] = { (void*)0x0, (void*)0x0, (void*)func_003D27E0 };
