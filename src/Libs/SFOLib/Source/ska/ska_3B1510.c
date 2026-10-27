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
Rel* std_vector_imp_cSkaPlaybackItem_ctor(Rel* r); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } S;
#if 0 /* merge_units */
extern void std_vector_imp_cSkaPlaybackItem_ctor(S*);
#endif /* merge_units */
#define std_vector_imp_cSkaPlaybackItem_ctor(a0) ((void)std_vector_imp_cSkaPlaybackItem_ctor((void *)(a0))) /* merge_units */

extern void std_vector_imp_cSkaPlaybackItem_reserve(S*, int);
/* Constructor: base init, sets value from *v, stores flag. */
S* cArray_cSkaPlaybackItem_ctor(S* s, int* v, unsigned char flag) { std_vector_imp_cSkaPlaybackItem_ctor(s); std_vector_imp_cSkaPlaybackItem_reserve(s, *v); s->flag = flag; return s; }
#undef std_vector_imp_cSkaPlaybackItem_ctor /* merge_units */
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


extern int std_vector_imp_cSkaPlaybackItem_insert(SkaVec* v, char* pos, int n, int value);

Rel* std_vector_imp_cSkaPlaybackItem_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

unsigned char cSkaAnim_IsLooping(unsigned char* self) {
    return self[69];
}

/* Append one 32-byte element at the end of the array. */
int cArray_cSkaPlaybackItem_PushBackActual(SkaVec* v, int value) {
    int count = v->count;
    char* data = v->data;
    return std_vector_imp_cSkaPlaybackItem_insert(v, data + (count << 5), 1, value);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B1560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B1560 */
