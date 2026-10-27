/*
 * main/weapon: range (2 files, 00140D40-00140DA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_00140D40 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cCharActionMsg_dtor, D_004E0840, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00140D40 */

/* merge_units: begin func_00140DA0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMessage_getSOBJClassId();
extern "C" void cAISoundSystemGOBJMessage_Clone();
extern void * const D_004D92C0[];
extern char D_004D92A0[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cAISoundSystemGOBJMessage_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D92C0);
        if (self) {
            self->vtable = D_004D92A0;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D92C0[8] = { (void*)0x0, (void*)0x0, (void*)cAISoundSystemGOBJMessage_dtor, (void*)cAISoundSystemGOBJMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00140DA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00140DA0 */
