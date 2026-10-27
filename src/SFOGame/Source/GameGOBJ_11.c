/*
 * SFOGame/Source/GameGOBJ: 2 files, 002118D0-00211970
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002118D0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_H(b, 8) = MP_I(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28); MP_I(b, 0x10) = MP_I(e, 0x30); MP_I(b, 0x14) = MP_I(e, 0x2C); MP_I(e, 0x1C) = 0x40;

DEFINE_MESSAGE_PACK_NOTYPE(cGOBJTriggerEventMsg_Pack, 24, D_004F5470, PACK_BODY)
static inline void merge_flush_func_002118D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002118D0 */

/* merge_units: begin func_00211970 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int cElevatorGOBJ_CreateElevatorInfo(cElevatorGOBJ* lift);

int cElevatorGOBJ_InitNetwork(cElevatorGOBJ* lift) {
    return cElevatorGOBJ_CreateElevatorInfo(lift);
}
static inline void merge_flush_func_00211970(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211970 */
