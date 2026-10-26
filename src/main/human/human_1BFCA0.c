/*
 * main/human: 3 files, 001BFCA0-001BFD30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001BFCA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

/* clear(): count = 0. */
void std_vector_deleter_cSkaSwitchValue_clear(PtrVec* v) {
    v->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BFCA0 */

/* merge_units: begin func_001BFCB0 */
#pragma push /* merge_units */
extern void cSkaSliderValue_dtor(void*, int);
typedef struct { char d[0x3C]; } G6E1B;
typedef struct { int x; int count; G6E1B* arr; } G6C1B;
void std_vector_deleter_cSkaSliderValue_clear(G6C1B* c)
{
    G6E1B* arr = c->arr;
    G6E1B* e = arr + c->count;
    while (arr < e) {
        --e;
        cSkaSliderValue_dtor(e, -1);
    }
    c->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BFCB0 */

/* merge_units: begin func_001BFD30 */
#pragma push /* merge_units */
#include "loose00_types.h"

extern int Global_LoadAnimation(int anim);

/* Script native: LoadAnimation(id). */
int Script_LoadAnimation(ScriptArg* args) {
    volatile int anim = args[0].i; /* stored to the stack and reloaded */

    Global_LoadAnimation(anim);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_001BFD30 */
