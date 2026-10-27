/*
 * SFOGame/Source/hud_radar: 1 file, 00261950
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00261950 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vt4_dtor.h"

extern "C" {
extern "C" void cHudRadar_Update();
extern "C" void cHudTargetsObserver_dtor();
extern "C" void cHudTargetsObserver_Update();
extern "C" void cHudTargetsObserver_TargetAdded();
extern "C" void cHudTargetsObserver_TargetRemoved();
extern void * const D_004DC930[];
extern void * const D_004DC950[];
}
extern "C" Vt4Object* cHudRadar_dtor(Vt4Object* self, short deleteFlag) {
    if (self) {
        self->vtable = ((char*)D_004DC950);
        if (self) self->vtable = ((char*)D_004DC930);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
void * const D_004DC930[8] = { (void*)0x0, (void*)0x0, (void*)cHudTargetsObserver_Update, (void*)cHudTargetsObserver_TargetAdded, (void*)cHudTargetsObserver_TargetRemoved, (void*)cHudTargetsObserver_dtor, (void*)0x0, (void*)0x0 };
void * const D_004DC950[8] = { (void*)0x0, (void*)0x0, (void*)cHudRadar_Update, (void*)cHudTargetsObserver_TargetAdded, (void*)cHudTargetsObserver_TargetRemoved, (void*)cHudRadar_dtor, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00261950(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00261950 */
