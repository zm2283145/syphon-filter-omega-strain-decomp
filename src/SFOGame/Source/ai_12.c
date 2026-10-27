/*
 * SFOGame/Source/ai: 4 files, 0016B2D0-0016B340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0016B2D0 */
#pragma push /* merge_units */
#include "types.h"
#include "iter_return_copy.h"

/* Return the end iterator. */
DEFINE_ITER_END(std_list_cActiveListItemPtr_end_void_2)
static inline void merge_flush_func_0016B2D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016B2D0 */

/* merge_units: begin func_0016B300 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Iterator copy.
 */


Word* cConstLListIterator_cActiveListItemPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}
static inline void merge_flush_func_0016B300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016B300 */

/* merge_units: begin func_0016B310 */
#pragma push /* merge_units */
/* Return the begin iterator. */
DEFINE_ITER_BEGIN(std_list_cActiveListItemPtr_begin_void_2)
static inline void merge_flush_func_0016B310(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016B310 */

/* merge_units: begin func_0016B340 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * AI receiver and action-message constructors.
 */

#include "ai_types.h"

/* action message vtable */
extern char D_004D92A0[];
/* action message with sender vtable */
extern char D_004D92C0[];
extern char D_004D9810[];
/* action message with sender and target vtable */
extern void Event_PackHeader();
extern void cMessage_getSOBJClassId();
extern void cAISoundSystemGobjToGobjMessage_dtor();
extern void cAISoundSystemGobjToGobjMessage_Clone();
void * const D_004D9870[8] = { (void*)0x0, (void*)0x0, (void*)cAISoundSystemGobjToGobjMessage_dtor, (void*)cAISoundSystemGobjToGobjMessage_Clone, (void*)Event_PackHeader, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
extern char D_004EE5C0[];
extern char D_004EE5C8[];
extern int cMessage_ctor_cMessageNameR(cActionMsg*, int);
extern int cSystem_ctor(void*, int);

void* cAISoundSystem_ctor(void* self) {
    cSystem_ctor(self, (int)D_004EE5C0);
    *(int*)self = (int)D_004D9810;
    return self;
}

/* Builds an action message carrying sender and target identities (event byte ends as 2). */
cActionMsg* cAISoundSystemGobjToGobjMessage_ctor(cActionMsg* msg, int* sender, int* target, int action) {
    cMessage_ctor_cMessageNameR(msg, (int)D_004EE5C8);
    msg->base.vtable = D_004D92A0;
    msg->event = 0;
    msg->action = action;
    *(int*)&msg->amplitude = 0;
    *(int*)&msg->unk2C = 0;
    msg->base.vtable = D_004D92C0;
    msg->sender = *sender;
    msg->base.vtable = ((char*)D_004D9870);
    msg->target = *target;
    msg->event = 2;
    return msg;
}
static inline void merge_flush_func_0016B340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0016B340 */
