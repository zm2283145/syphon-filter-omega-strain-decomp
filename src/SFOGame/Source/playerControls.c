/*
 * SFOGame/Source/playerControls: 1 file, 002470E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002470E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Event_PackHeader();
extern "C" void cMenuChoiceMsg_Clone();
extern "C" void cMenuChoiceMsg_getSOBJClassId();
extern void * const D_004DC330[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" VtableObject* cMenuChoiceMsg_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DC330);
        cMessage_dtor(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DC330[8] = { (void*)0x0, (void*)0x0, (void*)cMenuChoiceMsg_dtor, (void*)cMenuChoiceMsg_Clone, (void*)Event_PackHeader, (void*)cMenuChoiceMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_002470E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002470E0 */
