/*
 * main/NIEvent: range (2 files, 0023B0B0-0023B120)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0023B0B0 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE2_BASE_DTOR(cBeamMsg_dtor, D_004DCF30, D_004DCF10, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0023B0B0 */

/* merge_units: begin func_0023B120 */
#pragma push /* merge_units */
#pragma cplusplus on
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
int* std_vector_cNIEventBasePtr_opIndex(PtrVec* v, int i);
void cNIEventOBJ_UpdateChildren(Node_23B120* self);
}
/* Calls virtual slot 70, then recurses into every child whose kind (+0x4C) is NIEventOBJ (D_004F7C60). */
#pragma push
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_UpdateChildren(Node_23B120* self)
{
    int i;
    self->slot70();
    for (i = 0; i < self->children.count; i++) {
        Child_23B120* c = (Child_23B120*)*std_vector_cNIEventBasePtr_opIndex(&self->children, i);
        if (c->kind == D_004F7C60)
            cNIEventOBJ_UpdateChildren((Node_23B120*)self->children.data[i]);
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023B120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023B120 */
