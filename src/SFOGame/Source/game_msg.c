/*
 * SFOGame/Source/game_msg: 2 files, 0020E220-0020E330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020E220 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DADB0[];

struct Msg_0020E220 : ClonedMessageBase {
    char b24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = D_004DADB0; p->b24 = s->b24; p->a28 = s->a28;

extern "C" { char D_004A4068[] = "game_msg.hh"; }
DEFINE_MESSAGE_CLONE(cEndLevelMsg_Clone, Msg_0020E220, 44, D_004A4068, 81, CLONE_BODY)
static inline void merge_flush_func_0020E220(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E220 */

/* merge_units: begin func_0020E330 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004F53A8;

void cEndLevelMsg_SOBJ_init(void) {
}

int cEndLevelMsg_getSOBJClassId(void) {
    return D_004F53A8;
}
static inline void merge_flush_func_0020E330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020E330 */
