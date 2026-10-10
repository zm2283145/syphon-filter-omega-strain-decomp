#include "types.h"
typedef struct { char pad[0x30]; float rot[0x14]; float wrot[8]; char pad80[0x2]; unsigned char dirty; char padA3[0xD]; void* xform; } RootIdn_f4;
extern RootIdn_f4* Root_Identity(void*);
extern void* Root_GetParent(void*);
extern void* Root_GetWorldPlacement(void*);
extern void Transform_SetOrientation(void*, void*);
extern void Placement_Compose(void*, void*);
void* func_001A0110(RootIdn_f4* self)
{
    void* pl;
    if (self->xform != 0) {
        if (Root_Identity(self)->dirty) {
            pl = Root_GetWorldPlacement(Root_GetParent(self));
            Transform_SetOrientation(Root_Identity(self)->rot, Root_Identity(self)->wrot);
            Placement_Compose(Root_Identity(self)->rot, pl);
            Root_Identity(self)->dirty = 0;
        }
        return self->rot;
    }
    return self->wrot;
}