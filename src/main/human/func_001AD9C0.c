#include "types.h"
typedef struct { Q a; Q b; } VP_1AD9C0;
typedef struct { char pad[0x50]; VP_1AD9C0 orient; char pad70[0x30]; unsigned char dirty; } Id_1AD9C0;
typedef struct { char pad[0x160]; int x160; } R_1AD9C0;
extern Id_1AD9C0* Root_IdentityAccessor(R_1AD9C0* self);
extern void Transform_SetOrientation(VP_1AD9C0* d, VP_1AD9C0* s);
extern int func_001A0280(R_1AD9C0* self);
extern void func_001A7530(VP_1AD9C0* p);
extern VP_1AD9C0* Root_GetParentInverse(R_1AD9C0* self, VP_1AD9C0* tmp);
extern void Placement_Compose(VP_1AD9C0* d, VP_1AD9C0* s);
extern void Root_PropagateChildren(R_1AD9C0* self);
void func_001AD9C0(R_1AD9C0* self, VP_1AD9C0* o)
{
    Transform_SetOrientation(&Root_IdentityAccessor(self)->orient, o);
    if (func_001A0280(self)) {
        VP_1AD9C0 tmp;
        func_001A7530(&tmp);
        Placement_Compose(&Root_IdentityAccessor(self)->orient, Root_GetParentInverse(self, &tmp));
    }
    Root_IdentityAccessor(self)->dirty = 1;
    Root_PropagateChildren(self);
    self->x160 = 0;
}