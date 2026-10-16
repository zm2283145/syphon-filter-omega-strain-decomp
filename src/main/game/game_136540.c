/*
 * main/game: range (2 files, 00136540-001365B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00136540 */
#pragma push /* merge_units */
Rel* PtrVec_InitEmpty(Rel* r); /* gsynth: defined below */int func_001365B0(int a0, int a1); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } Sub00136540;
typedef struct { void* vtable; Sub00136540 sub; char pad[0x14 - 4 - sizeof(Sub00136540)]; int unk14; } Obj00136540;
extern char D_004D9140[];
#if 0 /* merge_units */
extern void PtrVec_InitEmpty(Sub00136540* sub);
#endif /* merge_units */
#define PtrVec_InitEmpty(a0) ((void)PtrVec_InitEmpty((void *)(a0))) /* merge_units */

extern int func_001361D0(void* src);
#if 0 /* merge_units */
extern int func_001365B0(Sub00136540* sub, int value);
#endif /* merge_units */
#define func_001365B0(a0, a1) (func_001365B0((int)(a0), (a1))) /* merge_units */

/* Constructor. */
Obj00136540* func_00136540(Obj00136540* obj, void* src)
{
    Sub00136540* sub;
    obj->vtable = D_004D9140;
    sub = &obj->sub;
    PtrVec_InitEmpty(sub);
    func_001365B0(sub, func_001361D0(src));
    sub->flag = 1;
    obj->unk14 = 0;
    return obj;
}
#undef PtrVec_InitEmpty /* merge_units */
#undef func_001365B0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00136540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00136540 */

/* merge_units: begin func_001365B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int PtrVec_Reserve(int, int);

int func_001365B0(int a0, int a1) {
    return PtrVec_Reserve(a0, a1);
}

Rel* PtrVec_InitEmpty(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* func_001365E0(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001365B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001365B0 */
