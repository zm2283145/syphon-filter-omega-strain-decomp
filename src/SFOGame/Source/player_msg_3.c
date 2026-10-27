/*
 * SFOGame/Source/player_msg: 1 file, 002103A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GameGOBJ_2103A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" char D_004DCF10[];
extern "C" char D_004DAE70[];

struct Msg_002103A0 : ClonedMessageBase {
    int a24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DAE70; p->a24 = s->a24;

extern "C" { char D_004A41B8[] = "player_msg.hh"; }
DEFINE_MESSAGE_CLONE(cMaxActiveNpcCountMsg_Clone, Msg_002103A0, 40, D_004A41B8, 59, CLONE_BODY)
static inline void merge_flush_GameGOBJ_2103A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GameGOBJ_2103A0 */
