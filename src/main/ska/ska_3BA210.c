/*
 * main/ska: range (3 files, 003BA210-003BA290)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "ska_types.h"

/* merge_units: begin func_003BA210 */
#pragma push /* merge_units */
SkaRelFlag* func_003BA260(SkaRelFlag* self); /* gsynth: defined below */
typedef struct TmpB0 {
    char b[0xB0];
} TmpB0;

typedef struct ObjB0 {
    char pad[0xB0];
    int unkB0;
    char sub[4];
} ObjB0;

extern void AnimRoot_ConstructBase(TmpB0*);
extern void func_003B6CB0(ObjB0*, TmpB0*);
#if 0 /* merge_units */
extern void func_003BA260(void*);
#endif /* merge_units */
#define func_003BA260(a0) ((void)func_003BA260((void *)(a0))) /* merge_units */


/* Constructor: initializes from a default temporary and sets up the sub-object at +0xB4. */
ObjB0* func_003BA210(ObjB0* o) {
    TmpB0 tmp;
    AnimRoot_ConstructBase(&tmp);
    func_003B6CB0(o, &tmp);
    o->unkB0 = 0;
    func_003BA260(o->sub);
    return o;
}
#undef func_003BA260 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA210(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA210 */

/* merge_units: begin func_003BA260 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


extern Rel* func_003BA290(Rel* r);

/* Construct: zero the three words and set the flag byte. */
SkaRelFlag* func_003BA260(SkaRelFlag* self) {
    func_003BA290(&self->rel);
    self->flag = 1;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA260 */

/* merge_units: begin func_003BA290 */
#pragma push /* merge_units */
Rel* func_003BA290(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003BA290(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003BA290 */
