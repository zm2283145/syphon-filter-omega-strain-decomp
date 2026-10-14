/*
 * main/collision: range (2 files, 003C3110-003C3120)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003C3110 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


/* Constructor: null pointer wrapper. */
int* func_003C3110(int* self) {
    *self = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3110(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3110 */

/* merge_units: begin func_003C3120 */
#pragma push /* merge_units */
typedef struct Obj3C3 {
    char pad[0xC];
    char flag;
} Obj3C3;

extern void func_003C3170(Obj3C3* self, int* src, int flag);
extern void func_001396D0(Obj3C3* self, int value);

/* Constructor: base init, applies *src, then stores the flag byte at +0xC. */
Obj3C3* func_003C3120(Obj3C3* self, int* src, int flag) {
    func_003C3170(self, src, flag);
    func_001396D0(self, *src);
    self->flag = flag;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003C3120(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003C3120 */
