#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Child_23B120 { char pad[0x4C]; int kind; };
class Node_23B120 {
public:
    VPAD32(a) VPAD32(b) VPAD4(c) VPAD2(d)
    virtual void slot70();
    char pad04[0x98];
    PtrVec children;
};
extern "C" {
extern int D_004F7C60;
int* func_0023A550(PtrVec* v, int i);
void func_0023B120(Node_23B120* self);
}
/* Calls virtual slot 70, then recurses into every child whose kind (+0x4C) is NIEventOBJ (D_004F7C60). */
#pragma push
#pragma opt_strength_reduction off
extern "C" void func_0023B120(Node_23B120* self)
{
    int i;
    self->slot70();
    for (i = 0; i < self->children.count; i++) {
        Child_23B120* c = (Child_23B120*)*func_0023A550(&self->children, i);
        if (c->kind == D_004F7C60)
            func_0023B120((Node_23B120*)self->children.data[i]);
    }
}
#pragma pop
