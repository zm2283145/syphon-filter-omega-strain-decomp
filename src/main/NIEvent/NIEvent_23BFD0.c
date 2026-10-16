/*
 * main/NIEvent: range (2 files, 0023BFD0-0023C010)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0023BFD0 */
#pragma push /* merge_units */
typedef struct B4Ev { char pad[0x94]; struct B4Ev* next; } B4Ev;
extern void func_0023BEE0(B4Ev*);
void cNIEventOBJ_v16(B4Ev* p) {
    B4Ev* n;
    for (n = p->next; n != 0; n = n->next) p = n;
    func_0023BEE0(p);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023BFD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023BFD0 */

/* merge_units: begin func_0023C010 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void NiEvent_SetTreePresence(Node_23C010* self, int arg);
void Object_Activate(Node_23C010* self, int arg);
}
#pragma push
#pragma opt_strength_reduction off
extern "C" void NiEvent_SetTreePresence(Node_23C010* self, int arg)
{
    int i;
    if (self->target)
        self->target->slot21(arg);
    for (i = 0; i < self->children.count; i++) {
        Child_23C010* c = (Child_23C010*)*func_0023A550(&self->children, i);
        if (c->kind == D_004F7C60)
            NiEvent_SetTreePresence((Node_23C010*)self->children.data[i], arg);
        else
            ((Target_23C010*)self->children.data[i])->slot21(arg);
    }
    Object_Activate(self, arg);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023C010(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023C010 */
