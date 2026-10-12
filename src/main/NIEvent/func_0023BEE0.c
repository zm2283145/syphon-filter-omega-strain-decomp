#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Child_23BEE0 { char pad[0x4C]; int kind; };
class Target_23BEE0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c) VPAD1(d)
    virtual void slot22(int arg);
};
struct Node_23BEE0 {
    void* vtable;
    char pad04[0x98];
    PtrVec children;
    char padA8[0x140 - 0xA8];
    Target_23BEE0* target;
};
extern "C" {
extern int D_004F7C60;
int* func_0023A550(PtrVec* v, int i);
void func_0023BEE0(Node_23BEE0* self, int arg);
void func_003CE790(Node_23BEE0* self, int arg);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void func_0023BEE0(Node_23BEE0* self, int arg)
{
    int i;
    if (self->target)
        self->target->slot22(arg);
    for (i = 0; i < self->children.count; i++) {
        Child_23BEE0* c = (Child_23BEE0*)*func_0023A550(&self->children, i);
        if (c->kind == D_004F7C60)
            func_0023BEE0((Node_23BEE0*)self->children.data[i], arg);
        else
            ((Target_23BEE0*)self->children.data[i])->slot22(arg);
    }
    func_003CE790(self, arg);
}
#pragma pop
