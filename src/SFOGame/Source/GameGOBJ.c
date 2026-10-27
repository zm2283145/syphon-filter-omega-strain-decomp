/*
 * SFOGame/Source/GameGOBJ: 1 file, 002104B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002104B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "message_clone.h"

extern "C" void Event_PackHeader();
extern "C" void cPathedNotice_getSOBJClassId();
extern "C" void cPathedNotice_dtor();
extern void * const D_004DAE90[];

struct Msg_002104B0 : ClonedMessageBase {
    int a24;
    int a28;
};

#define CLONE_BODY(p, s) p->vtable = ((char*)D_004DAE90); p->a24 = s->a24; p->a28 = s->a28;

DEFINE_MESSAGE_CLONE(cPathedNotice_Clone, Msg_002104B0, 44, D_004A4A48, 75, CLONE_BODY)
void * const D_004DAE90[8] = { (void*)0x0, (void*)0x0, (void*)cPathedNotice_dtor, (void*)cPathedNotice_Clone, (void*)Event_PackHeader, (void*)cPathedNotice_getSOBJClassId, (void*)0x0, (void*)0x0 };
static inline void merge_flush_func_002104B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002104B0 */
