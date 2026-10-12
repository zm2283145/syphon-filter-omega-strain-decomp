#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Child_23C010 { char pad[0x4C]; int kind; };
class Target_23C010 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void slot21(int arg);
};
struct Node_23C010 {
    void* vtable;
    char pad04[0x98];
    PtrVec children;
    char padA8[0x140 - 0xA8];
    Target_23C010* target;
};
extern "C" {
extern int D_004F7C60;
int* func_0023A550(PtrVec* v, int i);
void func_0023C010(Node_23C010* self, int arg);
void Object_Activate(Node_23C010* self, int arg);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void func_0023C010(Node_23C010* self, int arg)
{
    int i;
    if (self->target)
        self->target->slot21(arg);
    for (i = 0; i < self->children.count; i++) {
        Child_23C010* c = (Child_23C010*)*func_0023A550(&self->children, i);
        if (c->kind == D_004F7C60)
            func_0023C010((Node_23C010*)self->children.data[i], arg);
        else
            ((Target_23C010*)self->children.data[i])->slot21(arg);
    }
    Object_Activate(self, arg);
}
#pragma pop
