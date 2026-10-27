/*
 * SFOGame/Source/gameSound_msg: 1 file, 0020FE40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GameGOBJ_20FE40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable2_base_dtor.h"

extern "C" {
extern "C" void cMessage_getSOBJClassId();
extern "C" void cAtmosphericEffectMsg_Clone();
extern "C" void cAtmosphericEffectMsg_Pack();
extern "C" void cAtmosphericEffectMsg_GetMsgId();
extern "C" void cNetMsg_Pack();
extern void * const D_004DAE50[];
extern char D_004DCF10[];
void* cMessage_dtor(void* self, short deleteFlag);
}
extern "C" Vtable2Object* cAtmosphericEffectMsg_dtor(Vtable2Object* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DAE50);
        if (self) {
            self->vtable = D_004DCF10;
            cMessage_dtor(self, 0);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DAE50[8] = { (void*)0x0, (void*)0x0, (void*)cAtmosphericEffectMsg_dtor, (void*)cAtmosphericEffectMsg_Clone, (void*)cNetMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)cAtmosphericEffectMsg_Pack, (void*)cAtmosphericEffectMsg_GetMsgId };
static inline void merge_flush_GameGOBJ_20FE40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GameGOBJ_20FE40 */
