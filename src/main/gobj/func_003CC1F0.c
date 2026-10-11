#include "types.h"
typedef struct { void* vt; } TC1F0;
extern char D_004DFE40[];
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
TC1F0* SubScript_dtor(TC1F0* self, short del)
{
    if (self) {
        self->vt = D_004DFE40;
        cGOBJ_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
