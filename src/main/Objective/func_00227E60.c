#include "types.h"
typedef struct { void* vtable; } ObjMan00227E60;
extern char D_004DB790[];
extern void ObjMan_DeleteAll(ObjMan00227E60* self);
extern void Receiver_Destruct(ObjMan00227E60* self, int flags);
extern void operator_delete(void* p);
ObjMan00227E60* cObjectiveMan_dtor(ObjMan00227E60* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DB790;
        ObjMan_DeleteAll(self);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}