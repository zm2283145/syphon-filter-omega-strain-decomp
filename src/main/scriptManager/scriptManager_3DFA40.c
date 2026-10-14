/*
 * main/scriptManager: range (2 files, 003DFA40-003DFAE0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003DFA40 */
#pragma push /* merge_units */
void func_003DFAF0(Iter* out, Tree* t); /* gsynth: defined below */Word* func_003DFAE0(Word* dst, Word* src); /* gsynth: defined below */
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
extern void func_003E2EE0(int* outIt, void* map, int* key);
#if 0 /* merge_units */
extern void func_003DFAF0(int* outEnd, void* map);
#endif /* merge_units */
#define func_003DFAF0(a0, a1) (func_003DFAF0((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_003DFAE0(int* out, int* end);
#endif /* merge_units */
#define func_003DFAE0(a0, a1) ((void)func_003DFAE0((void *)(a0), (void *)(a1))) /* merge_units */

extern void func_003E3160(void* map, int* it);

/* Runs the event and removes it from the pending-event map. */
void ScriptEvent_Execute(ScriptEvent* ev) {
    int endRaw;
    int eraseIt;
    int found;
    int end;
    int it;
    ScriptEvent_Replay(D_00555070, ev->script, ev->a, ev->b, ev->c);
    func_003E2EE0(&found, D_0055A0F0, &ev->key);
    it = found;
    func_003DFAF0(&endRaw, D_0055A0F0);
    func_003DFAE0(&end, &endRaw);
    if ((it == end) ^ 1) {
        eraseIt = it;
        func_003E3160(D_0055A0F0, &eraseIt);
    }
}
#undef func_003DFAF0 /* merge_units */
#undef func_003DFAE0 /* merge_units */
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

Word* func_003DFAE0(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_003DFAF0(Iter* out, Tree* t) {
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
