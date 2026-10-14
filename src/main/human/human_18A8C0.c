/*
 * main/human: range (2 files, 0018A8C0-0018A8F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0018A8C0 */
#pragma push /* merge_units */
Rel* func_0018A8F0(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern Rel* func_0018A8F0(Rel*);
#endif /* merge_units */
#define func_0018A8F0(a0) (func_0018A8F0((a0))) /* merge_units */


/* Clear the three words and set the byte at +0x0C. */
Rel* func_0018A8C0(Rel* r) {
    func_0018A8F0(r);
    *((char*)r + 12) = 1;
    return r;
}
#undef func_0018A8F0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A8C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A8C0 */

/* merge_units: begin func_0018A8F0 */
#pragma push /* merge_units */
/* Array constructor helper: (array, ctor, dtor, element size, count). */
extern void* __construct_array(void*, void*, void*, int, int);
extern int func_0018A210(int, int);
extern int* func_0018A870(int*);

Rel* func_0018A8F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Construct an array of seven 8-byte pairs. */
void* func_0018A910(void* array) {
    __construct_array(array, func_0018A870, func_0018A210, 8, 7);
    return array;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A8F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A8F0 */
