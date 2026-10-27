/*
 * main/Checkpoint: range (2 files, 0022ED30-0022EE30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop

/* merge_units: begin func_0022ED30 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DB8B0[];

struct Msg_0022ED30 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004DB8B0;

extern "C" {
char D_004A67D8[] = "Checkpoint.hh";
}
DEFINE_MESSAGE_CLONE(cNotifyCheckpointMsg_Clone, Msg_0022ED30, 36, D_004A67D8, 73, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022ED30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022ED30 */

/* merge_units: begin func_0022EE30 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DB8D0[];

struct Msg_0022EE30 : ClonedMessageBase {
    int a24;
    int a28;
};

#undef CLONE_BODY /* merge_units */
#define CLONE_BODY(p, s) p->vtable = D_004DB8D0; p->a24 = s->a24; p->a28 = s->a28;

extern "C" {
char D_004A67E8[] = "Checkpoint.hh";
}
DEFINE_MESSAGE_CLONE(cAddCheckpointMsg_Clone, Msg_0022EE30, 44, D_004A67E8, 35, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022EE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022EE30 */
