/*
 * main/scriptManager: range (2 files, 003DFCE0-003DFD10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptManager_types.h"

/* merge_units: begin func_003DFCE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern void Script_Unschedule(int id);

/* Script native: Unschedule(args[0]). volatile mirrors the original stack temporary. */
int Script_UnscheduleThunk(ScriptArg* args) {
    volatile int id = args[0].i;
    Script_Unschedule(id);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFCE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFCE0 */

/* merge_units: begin func_003DFD10 */
#pragma push /* merge_units */
typedef struct PendingEvent {
    char pad00[0x10];
    void* queued; /* 0x10 */
} PendingEvent;

extern char D_0055A0F0[];
extern void std_tree_pair_int_value_compare_find_intR_2(PendingEvent** outIt, void* map, int* key);
extern void std_map_int_SchedCallbackPtr_end(int* outEnd, void* map);
extern void cAssocArray_int_SchedCallbackPtr_Iterator_ctor(PendingEvent** out, int* end);
extern void std_tree_pair_int_value_compare_erase_tree_2(void* map, PendingEvent** it);
extern void EventQueue_Remove(void* queued);

/* Unschedule(id): removes a pending scheduled event. */
void Script_Unschedule(int id) {
    int key;
    int endRaw;
    PendingEvent* eraseIt;
    PendingEvent* found;
    PendingEvent* end;
    PendingEvent* it;
    key = id;
    std_tree_pair_int_value_compare_find_intR_2(&found, D_0055A0F0, &key);
    it = found;
    std_map_int_SchedCallbackPtr_end(&endRaw, D_0055A0F0);
    cAssocArray_int_SchedCallbackPtr_Iterator_ctor(&end, &endRaw);
    if ((it == end) ^ 1) {
        EventQueue_Remove(it->queued);
        eraseIt = it;
        std_tree_pair_int_value_compare_erase_tree_2(D_0055A0F0, &eraseIt);
    }

}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFD10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFD10 */
