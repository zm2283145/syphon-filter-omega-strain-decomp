#include "types.h"
typedef struct { char pad[0x10]; void* vt; } T1F00;
extern char D_004E0080[];
extern void operator_delete(void* p);
T1F00* func_003D1F00(T1F00* self, short del)
{
    if (self) {
        self->vt = D_004E0080;
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
