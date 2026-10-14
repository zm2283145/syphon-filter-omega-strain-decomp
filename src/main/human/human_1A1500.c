/*
 * main/human: range (2 files, 001A1500-001A1570)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001A1500 */
#pragma push /* merge_units */
Rel* func_001A1570(Rel* r); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } Sub;
typedef struct { unsigned char state; char pad[3]; char items[0x38]; Sub sub; } S;
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int count);
extern void func_0018A870(void);
extern void func_0018A210(void);
#if 0 /* merge_units */
extern void func_001A1570(Sub*);
#endif /* merge_units */
#define func_001A1570(a0) ((void)func_001A1570((void *)(a0))) /* merge_units */

/* Constructor: clears state, constructs 7 8-byte items, inits the sub-object and sets its flag. */
S* func_001A1500(S* s) { Sub* sub; s->state = 0; __construct_array(s->items, func_0018A870, func_0018A210, 8, 7); sub = &s->sub; func_001A1570(sub); sub->flag = 1; return s; }
#undef func_001A1570 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A1500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A1500 */

/* merge_units: begin func_001A1570 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_001A1570(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001A1570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001A1570 */
