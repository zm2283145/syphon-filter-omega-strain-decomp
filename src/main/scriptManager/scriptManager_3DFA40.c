/*
 * main/scriptManager: range (2 files, 003DFA40-003DFAE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003DFA40 */
#pragma push /* merge_units */
void std_map_int_SchedCallbackPtr_end(Iter* out, Tree* t); /* gsynth: defined below */Word* cAssocArray_int_SchedCallbackPtr_Iterator_ctor(Word* dst, Word* src); /* gsynth: defined below */
typedef struct ScriptEvent {
    char pad00[0xC];
    int a;        /* 0x0C */
    int b;        /* 0x10 */
    int script;   /* 0x14 */
    int c;        /* 0x18 */
    int key;      /* 0x1C */
} ScriptEvent;

extern char D_00555070[];
extern char D_0055A0F0[];
extern void ScriptEvent_Replay(void* sched, int script, int a, int b, int c);
extern void std_tree_pair_int_value_compare_find_intR_2(int* outIt, void* map, int* key);
#if 0 /* merge_units */
extern void std_map_int_SchedCallbackPtr_end(int* outEnd, void* map);
#endif /* merge_units */
#define std_map_int_SchedCallbackPtr_end(a0, a1) (std_map_int_SchedCallbackPtr_end((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cAssocArray_int_SchedCallbackPtr_Iterator_ctor(int* out, int* end);
#endif /* merge_units */
#define cAssocArray_int_SchedCallbackPtr_Iterator_ctor(a0, a1) ((void)cAssocArray_int_SchedCallbackPtr_Iterator_ctor((void *)(a0), (void *)(a1))) /* merge_units */

extern void std_tree_pair_int_value_compare_erase_tree_2(void* map, int* it);

/* Runs the event and removes it from the pending-event map. */
void ScriptEvent_Execute(ScriptEvent* ev) {
    int endRaw;
    int eraseIt;
    int found;
    int end;
    int it;
    ScriptEvent_Replay(D_00555070, ev->script, ev->a, ev->b, ev->c);
    std_tree_pair_int_value_compare_find_intR_2(&found, D_0055A0F0, &ev->key);
    it = found;
    std_map_int_SchedCallbackPtr_end(&endRaw, D_0055A0F0);
    cAssocArray_int_SchedCallbackPtr_Iterator_ctor(&end, &endRaw);
    if ((it == end) ^ 1) {
        eraseIt = it;
        std_tree_pair_int_value_compare_erase_tree_2(D_0055A0F0, &eraseIt);
    }
}
#undef std_map_int_SchedCallbackPtr_end /* merge_units */
#undef cAssocArray_int_SchedCallbackPtr_Iterator_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFA40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFA40 */

/* merge_units: begin func_003DFAE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int Script_ClearSchedules_3DFB20(void);

Word* cAssocArray_int_SchedCallbackPtr_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_int_SchedCallbackPtr_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

int Script_ClearSchedules(void) {
    Script_ClearSchedules_3DFB20();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003DFAE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003DFAE0 */
