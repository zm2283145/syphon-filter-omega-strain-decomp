#include "types.h"
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9BA0;
extern char D_004E0480[];
extern char D_004E05A0[];
extern void IeElement_Release(void* p);
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
G9BA0* HudTracker_Delete(G9BA0* self, short del)
{
    if (self) {
        self->vt = D_004E0480;
        if (self) {
            self->vt = D_004E05A0;
            IeElement_Release(self->m60);
            cGOBJ_dtor(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
