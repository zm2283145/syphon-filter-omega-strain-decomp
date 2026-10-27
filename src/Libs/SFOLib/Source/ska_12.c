/*
 * Libs/SFOLib/Source/ska: 3 files, 003ACDC0-003ACDD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003ACDC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "types.h"

void func_003ACDC0(Iter* out, PtrVec* v) {
    out->p = v->data;
}
static inline void merge_flush_func_003ACDC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003ACDC0 */

/* merge_units: begin func_003ACDD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C4Anim3AC { char pad[0x31]; unsigned char complete; };
struct C4It3AC { void* p; C4It3AC() {} C4It3AC(const C4It3AC& o) : p(o.p) {} };
extern "C" {
C4It3AC cArray_cString_REnd(void* list);
C4It3AC func_00198B60(void* list);
bool opNe_cConstLListIteratorR_cConstLListIteratorR(C4It3AC* a, C4It3AC* b);
void cConstLListIterator_cSkaPlaybackGroupPtr_opInc(C4It3AC* it);
C4Anim3AC** cConstLListIterator_cSkaPlaybackGroupPtr_opMul(C4It3AC* it);
bool cSkaPlaybackGroup_CheckId(C4Anim3AC* a, int id);
}
extern "C" unsigned char AnimGroup_IsComplete(void* list, int id) {
    C4Anim3AC* found = 0;
    C4It3AC it = cArray_cString_REnd(list);
    C4It3AC end = func_00198B60(list);
    while (opNe_cConstLListIteratorR_cConstLListIteratorR(&it, &end)) {
        if (cSkaPlaybackGroup_CheckId(*cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it), id)) {
            found = *cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it);
            break;
        }
        cConstLListIterator_cSkaPlaybackGroupPtr_opInc(&it);
    }
    if (found) return found->complete;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ACDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ACDD0 */

/* merge_units: begin func_003ACEA0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* For every phase overlapping the given one, run its handler. */
typedef struct { unsigned char pad[0xC]; unsigned char sub[8]; } Phase_3ACEA0;
typedef struct { int pad0; int count; } Vec_3ACEA0;
typedef struct { unsigned char enabled; unsigned char pad[0x3B]; Vec_3ACEA0 phases; } Obj_3ACEA0;

extern "C" {
Phase_3ACEA0** cSkaPlaybackGroup_PlaybackPosWithHistory(Vec_3ACEA0* v);
int cSkaAnimCheckpoints_cTimedEvent_IsTimeToTriggerEvent(void* a, Phase_3ACEA0* b);
void cSkaAnimEvent_Trigger(void* p);
}

static inline bool Ne_3ACEA0(Phase_3ACEA0* a, Phase_3ACEA0* b) { return !(a == b); }

extern "C" void cSkaAnimCheckpoints_TriggerScheduledEvents(Obj_3ACEA0* o, void* phase)
{
    if (o->enabled) {
        Phase_3ACEA0* it;
        Phase_3ACEA0* end;
        it = *cSkaPlaybackGroup_PlaybackPosWithHistory(&o->phases);
        end = *cSkaPlaybackGroup_PlaybackPosWithHistory(&o->phases) + o->phases.count;
        for (; Ne_3ACEA0(it, end); it++) {
            if (cSkaAnimCheckpoints_cTimedEvent_IsTimeToTriggerEvent(phase, it))
                cSkaAnimEvent_Trigger(it->sub);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ACEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ACEA0 */
