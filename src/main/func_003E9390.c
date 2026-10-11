#include "types.h"
typedef struct { void* vt; } T9390;
extern char D_004E0800[];
extern void operator_delete(void* p);
T9390* func_003E9390(T9390* self, short del)
{
    if (self) {
        self->vt = D_004E0800;
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
