/*
 * main/ska: range (2 files, 003B1510-003B1560)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003B1510 */
#pragma push /* merge_units */
Rel* func_003B1560(Rel* r); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } S;
#if 0 /* merge_units */
extern void func_003B1560(S*);
#endif /* merge_units */
#define func_003B1560(a0) ((void)func_003B1560((void *)(a0))) /* merge_units */

extern void func_003B7A50(S*, int);
/* Constructor: base init, sets value from *v, stores flag. */
S* func_003B1510(S* s, int* v, unsigned char flag) { func_003B1560(s); func_003B7A50(s, *v); s->flag = flag; return s; }
#undef func_003B1560 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1510 */

/* merge_units: begin func_003B1560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern int func_003B7470(SkaVec* v, char* pos, int n, int value);

Rel* func_003B1560(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

unsigned char func_003B1580(unsigned char* self) {
    return self[69];
}

/* Append one 32-byte element at the end of the array. */
int func_003B1590(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return func_003B7470(v, data + (count << 5), 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1560 */
