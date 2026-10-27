/*
 * SFOGame/Source/GameGOBJ: 5 files, 0021A7A0-0021A920
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021A7A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetCreateBlastMsg_dtor, D_004DE130, cMessage_dtor)
static inline void merge_flush_func_0021A7A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A7A0 */

/* merge_units: begin func_0021A800 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern char D_004D9DE0[];

Rec0C* cSafePtr_cGOBJ_ctor_void(Rec0C* r) {
    *(int*)&r->unk4 = -2;
    r->unk0 = 0;
    return r;
}

Rec0C* cCBData_ctor(Rec0C* r, int a1, int a2, int a3) {
    r->unk8 = D_004D9DE0;
    r->unk4 = a2;
    r->unk0 = a1;
    r->unk5 = a3;
    return r;
}
static inline void merge_flush_func_0021A800(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A800 */

/* merge_units: begin func_0021A840 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "linked_target_refresh.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_flag_slot16.h"
#pragma pop

#pragma cplusplus on

/* Push the value to the linked target and refresh it. */
DEFINE_LINKED_TARGET_REFRESH(cGameGOBJ_Render)
static inline void merge_flush_func_0021A840(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A840 */

/* merge_units: begin func_0021A8C0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Call slot 16 unless the object is active. */
DEFINE_GOBJ_FLAG_SLOT16(cGameGOBJ_CriticalNextFrame)
static inline void merge_flush_func_0021A8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A8C0 */

/* merge_units: begin func_0021A920 */
#pragma push /* merge_units */
extern void cGOBJ_NextFrame(void* self);
extern int cGOBJ_HandleMessage(void* self, int a1);

void cGameGOBJ_NextFrame(void* self) {
    cGOBJ_NextFrame(self);
}

int cGameGOBJ_HandleMessage(void* self, int a1) {
    return cGOBJ_HandleMessage(self, a1);
}
static inline void merge_flush_func_0021A920(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021A920 */
