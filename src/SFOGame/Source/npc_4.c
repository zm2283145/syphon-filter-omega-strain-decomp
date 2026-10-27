/*
 * SFOGame/Source/npc: 2 files, 00148470-00148480
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin npc_148470 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* clear(): count = 0. */
void std_vector_deleter_Record_clear(PtrVec* v) {
    v->count = 0;
}
static inline void merge_flush_npc_148470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end npc_148470 */

/* merge_units: begin func_00148480 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" void Event_PackHeader();
extern "C" void cAIModeChangeMsg_dtor();
extern "C" void cAIModeChangeMsg_getSOBJClassId();
extern void * const D_004D92E0[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = ((char*)D_004D92E0); p->b24 = s->b24;

DEFINE_MESSAGE_CLONE(cAIModeChangeMsg_Clone, Msg_0023FF50, 0x28, D_0049C070, 0x2D5, CLONE_BODY)
void * const D_004D92E0[8] = { (void*)0x0, (void*)0x0, (void*)cAIModeChangeMsg_dtor, (void*)cAIModeChangeMsg_Clone, (void*)Event_PackHeader, (void*)cAIModeChangeMsg_getSOBJClassId, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_00148480(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00148480 */
