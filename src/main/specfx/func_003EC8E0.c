#include "types.h"
typedef struct { char pad[0x14]; void* vt; } TC8E0;
extern char D_004E0780[];
extern void func_003EC220(void* self, short del);
extern void operator_delete(void* p);
TC8E0* func_003EC8E0(TC8E0* self, short del)
{
    if (self) {
        self->vt = D_004E0780;
        if (self)
            func_003EC220(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
