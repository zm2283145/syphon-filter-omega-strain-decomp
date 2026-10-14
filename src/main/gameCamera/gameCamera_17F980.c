/*
 * main/gameCamera: range (2 files, 0017F980-0017F9B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0017F980 */
#pragma push /* merge_units */
Rel* func_0017F9B0(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern Rel* func_0017F9B0(Rel*);
#endif /* merge_units */
#define func_0017F9B0(a0) (func_0017F9B0((a0))) /* merge_units */


/* Clears the three words and sets byte +0xC. */
Rel* func_0017F980(Rel* r) {
    func_0017F9B0(r);
    *((char*)r + 12) = 1;
    return r;
}
#undef func_0017F9B0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F980 */

/* merge_units: begin func_0017F9B0 */
#pragma push /* merge_units */
extern char D_004DA330[]; /* vtable */

Rel* func_0017F9B0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Sets the vtable pointer. */
char* func_0017F9D0(char* self) {
    *(char**)self = D_004DA330;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0017F9B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0017F9B0 */
