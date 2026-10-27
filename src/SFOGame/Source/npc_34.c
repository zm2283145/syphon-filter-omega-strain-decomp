/*
 * main/npc: range (2 files, 00150BF0-00150C60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vtable2_base_dtor.h"
#pragma pop

/* merge_units: begin func_00150BF0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cCharActionMsg_TargetInfo_dtor, D_004E0200, D_004E0840, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00150BF0 */

/* merge_units: begin func_00150C60 */
#pragma push /* merge_units */
#pragma bool off
typedef struct C6Obj_150C60 { int pad[3]; int serial; } C6Obj_150C60;
typedef struct C6Ref_150C60 { C6Obj_150C60* obj; int serial; } C6Ref_150C60;
static inline int C6Valid(void* p) { return p != 0; }
C6Obj_150C60* cSafePtr_cGOBJ_opCast_cGOBJPtr(C6Ref_150C60* ref) {
    C6Obj_150C60* o = ref->obj;
    unsigned char ok = 1;
    if (!C6Valid(o) == 0) {
        if (o->serial != ref->serial) ok = 0;
    }
    return ok ? o : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00150C60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00150C60 */
