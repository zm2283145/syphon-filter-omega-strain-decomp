#include "types.h"
typedef struct { int a; int b; void* vt; } S_6E60;
extern char D_004D9DE0[];
extern void operator_delete(void* p);
S_6E60* func_00176E60(S_6E60* self, short flag)
{
    if (self) {
        self->vt = D_004D9DE0;
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}