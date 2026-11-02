/*
 * SFOGame/Source/BeamMsg: 2 files, 00282910-00282980
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
#if 0 /* merge_units */
extern "C" void cNetUpdateTankMsg_GetMsgId();
#endif /* merge_units */
int cNetUpdateTankMsg_GetMsgId(void); /* merge_units */
#define cNetUpdateTankMsg_GetMsgId() ((void)cNetUpdateTankMsg_GetMsgId()) /* merge_units */

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
#undef cNetUpdateTankMsg_GetMsgId /* merge_units */
static inline void merge_flush_func_00282910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282910 */

/* merge_units: begin func_00282980 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "tank_types.h"

extern int D_00506268;

/* Message type id for cNetUpdateTankMsg. */
int cNetUpdateTankMsg_GetMsgId(void) {
    return D_00506268;
}
static inline void merge_flush_func_00282980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00282980 */
