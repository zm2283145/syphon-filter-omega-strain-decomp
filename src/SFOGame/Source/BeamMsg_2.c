/*
 * SFOGame/Source/BeamMsg: 1 file, 00282910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00282910 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
extern "C" {
extern "C" void cMessage_getSOBJClassId();
extern "C" void cNetUpdateTankMsg_Clone();
extern "C" void cNetUpdateTankMsg_Pack();
extern "C" void cNetUpdateTankMsg_GetMsgId();
extern "C" void cNetMsg_Pack();
extern void * const D_004DCF50[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cNetUpdateTankMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DCF50);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DCF50[8] = { (void*)0x0, (void*)0x0, (void*)cNetUpdateTankMsg_dtor, (void*)cNetUpdateTankMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cNetUpdateTankMsg_Pack, (void*)cNetUpdateTankMsg_GetMsgId };
static inline void merge_flush_func_00282910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282910 */
