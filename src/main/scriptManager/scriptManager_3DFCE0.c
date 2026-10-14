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
extern void func_003E2EE0(PendingEvent** outIt, void* map, int* key);
extern void func_003DFAF0(int* outEnd, void* map);
extern void func_003DFAE0(PendingEvent** out, int* end);
extern void func_003E3160(void* map, PendingEvent** it);
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
    func_003E2EE0(&found, D_0055A0F0, &key);
    it = found;
    func_003DFAF0(&endRaw, D_0055A0F0);
    func_003DFAE0(&end, &endRaw);
    if ((it == end) ^ 1) {
        EventQueue_Remove(it->queued);
        eraseIt = it;
        func_003E3160(D_0055A0F0, &eraseIt);
    }

}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFD10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFD10 */
