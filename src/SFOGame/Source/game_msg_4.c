/*
 * SFOGame/Source/game_msg: 3 files, 0020E4C0-0020E560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020E4C0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"

#define PACK_BODY(e, b) MP_S(b, 8) = MP_S(e, 0x24); MP_I(b, 0xC) = MP_I(e, 0x28);

DEFINE_MESSAGE_PACK(cEndLevelMsg_Pack, 16, D_004F53A0, PACK_BODY)
static inline void merge_flush_func_0020E4C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E4C0 */

/* merge_units: begin func_0020E540 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F5388;

void cStartLevelMsg_SOBJ_init(void) {
}

int cStartLevelMsg_getSOBJClassId(void) {
    return D_004F5388;
}
static inline void merge_flush_func_0020E540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E540 */

/* merge_units: begin func_0020E560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004DADD0[];

struct Msg_0020E560 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DADD0;

extern "C" { char D_004A4078[] = "game_msg.hh"; }
DEFINE_MESSAGE_CLONE(cStartLevelMsg_Clone, Msg_0020E560, 36, D_004A4078, 59, CLONE_BODY)
static inline void merge_flush_func_0020E560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E560 */
