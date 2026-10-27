/*
 * SFOGame/Source/human: 4 files, 0018A870-0018A8C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0018A870 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

int* cSkaAnimEvent_ctor_void(int* pair) {
    pair[0] = -1;
    pair[1] = 0;
    return pair;
}
static inline void merge_flush_func_0018A870(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A870 */

/* merge_units: begin func_0018A890 */
#pragma push /* merge_units */
typedef struct { Q a; Q b; Q c; } Z_18A890;
static inline void QZero_18A890(void* d0) { int n = 3; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
Z_18A890* cString16N_3_ctor_void(Z_18A890* d)
{
    QZero_18A890(d);
    return d;
}
static inline void merge_flush_func_0018A890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0018A890 */

/* merge_units: begin func_0018A8C0 */
#pragma push /* merge_units */
Rel* func_0018A8F0(Rel* r); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern Rel* func_0018A8F0(Rel*);


/* Clear the three words and set the byte at +0x0C. */
Rel* cArray_cTimedEvent_ctor_void(Rel* r) {
    func_0018A8F0(r);
    *((char*)r + 12) = 1;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A8C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A8C0 */

/* merge_units: begin func_0018A8F0 */
#pragma push /* merge_units */
/* Array constructor helper: (array, ctor, dtor, element size, count). */
extern void* __construct_array(void*, void*, void*, int, int);
extern int func_0018A210(int, int);
extern int* cSkaAnimEvent_ctor_void(int*);

Rel* func_0018A8F0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

/* Construct an array of seven 8-byte pairs. */
void* cArray_FixedSize_cSkaAnimEvent_7_ctor_void(void* array) {
    __construct_array(array, cSkaAnimEvent_ctor_void, func_0018A210, 8, 7);
    return array;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0018A8F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0018A8F0 */
