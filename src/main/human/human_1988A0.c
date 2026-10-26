/*
 * main/human: range (2 files, 001988A0-00198900)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001988A0 */
#pragma push /* merge_units */
typedef struct { char d[0xF8]; } DqElemD4;
typedef struct { DqElemD4** node; DqElemD4** first; int pad; DqElemD4** last; DqElemD4* cur; DqElemD4* end; } DequeIterD4;
DequeIterD4* DequeIter_Next(DequeIterD4* it)
{
    if (++it->cur == it->end) {
        if (++it->node == it->last) it->node = it->first;
        it->cur = *it->node;
        it->end = it->cur + 8;
    }
    return it;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001988A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001988A0 */

/* merge_units: begin func_00198900 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C4Anim3AC { char pad[0x18]; float value; };
struct C4It3AC { void* p; C4It3AC() {} C4It3AC(const C4It3AC& o) : p(o.p) {} };
extern "C" {
C4It3AC cArray_cString_REnd(void* list);
C4It3AC func_00198B60(void* list);
bool opNe_cConstLListIteratorR_cConstLListIteratorR(C4It3AC* a, C4It3AC* b);
void cConstLListIterator_cSkaPlaybackGroupPtr_opInc(C4It3AC* it);
C4Anim3AC** cConstLListIterator_cSkaPlaybackGroupPtr_opMul(C4It3AC* it);
bool cSkaPlaybackGroup_CheckId(C4Anim3AC* a, int id);
}
extern "C" float cSkaPlaybackList_FreezePlayback_cSkaPlaybackGroupIdR_bool(void* list, int id) {
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
    if (found) return found->value;
    return 0.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00198900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00198900 */
