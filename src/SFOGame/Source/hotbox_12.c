/*
 * SFOGame/Source/hotbox: 2 files, 00171020-00171050
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00171020 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern int std_list_deleter_voidPtr_insert(HotboxListIter* out, Tree* list, HotboxListIter* pos, int* value);

/* Inserts value with end() as the position hint; the result iterator is discarded. */
int cLList_cHotboxPtr_PushBackActual(Tree* list, int* value) {
    HotboxListIter end;
    HotboxListIter result;

    end.node = (HotboxListNode*)&list->header;
    return std_list_deleter_voidPtr_insert(&result, list, &end, value);
}
static inline void merge_flush_func_00171020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171020 */

/* merge_units: begin func_00171050 */
#pragma push /* merge_units */
/* 32-byte copy as one GCC-style lq/sq asm (q0,q1 outputs first, then d, s) gives retail register choice. */
typedef struct Bounds {
    __int128 q[2];
} Bounds;

extern void CalculateInteractBoxDimensionsAndLocation(Bounds* out, void* a, void* b);

typedef struct Obj {
    char pad[0x70];
    Bounds b;
} Obj;

#pragma peephole off
void cHotboxMan_SetupInteractBoxDimensionsAndLocation(void* self, Obj* o, void* a, void* b) {
    Bounds t;
    CalculateInteractBoxDimensionsAndLocation(&t, a, b);
    { void* d = &o->b; void* s = &t; __int128 q0, q1; __asm__ volatile("lq %0, 0(%3); lq %1, 0x10(%3); sq %0, 0(%2); sq %1, 0x10(%2)" : "=&r"(q0), "=&r"(q1) : "r"(d), "r"(s) : "memory"); }
}
static inline void merge_flush_func_00171050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00171050 */
