/*
 * Libs/SFOLib/Source/ska: 2 files, 003B0020-003B0050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B0020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */

#include "ska_types.h"

extern int std_list_deleter_voidPtr_insert(int* result, List* list, void** pos, int value);

/* Append value at the end of the list (insert before the sentinel at +4). */
int std_list_cSkaTransPlaybackPtr_push_back(List* list, int value) {
    struct {
        void* pos;
        int result;
    } loc;

    loc.pos = &list->first;
    return std_list_deleter_voidPtr_insert(&loc.result, list, &loc.pos, value);
}
static inline void merge_flush_func_003B0020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0020 */

/* merge_units: begin func_003B0050 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"

/* Find the first list entry matching key; 0 if none. */
typedef struct { int w[1]; } It_3B0050;
typedef struct { unsigned char pad[0x6C]; int list; } Obj_3B0050;

extern "C" {
void cLList_cSkaTransPlaybackPtr_Begin(It_3B0050* out, void* list);
void cLList_cSkaTransPlaybackPtr_End(It_3B0050* out, void* list);
bool opNe_cLListIteratorR_cLListIteratorR_8(It_3B0050* a, It_3B0050* b);
int* cLListIterator_cSkaTransPlaybackPtr_opMul(It_3B0050* it);
void cLListIterator_cSkaTransPlaybackPtr_opInc(It_3B0050* it);
int cSkaTransPlayback_CheckId(int entry, void* key);
}

extern "C" int cSkaSwitch_GetTransPlayback(void* key, Obj_3B0050* o)
{
    It_3B0050 it;
    It_3B0050 end;
    for (cLList_cSkaTransPlaybackPtr_Begin(&it, &o->list); (cLList_cSkaTransPlaybackPtr_End(&end, &o->list), opNe_cLListIteratorR_cLListIteratorR_8(&it, &end)); cLListIterator_cSkaTransPlaybackPtr_opInc(&it)) {
        if (cSkaTransPlayback_CheckId(*cLListIterator_cSkaTransPlaybackPtr_opMul(&it), key))
            return *cLListIterator_cSkaTransPlaybackPtr_opMul(&it);
    }
    return 0;
}
static inline void merge_flush_func_003B0050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B0050 */
