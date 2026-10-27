/*
 * main/game: range (2 files, 00136540-001365B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00136540 */
#pragma push /* merge_units */
Rel* std_vector_cGOBJPtr_ctor_void(Rel* r); /* gsynth: defined below */int std_vector_cGOBJPtr_reserve(int a0, int a1); /* gsynth: defined below */typedef struct { char pad[0xC]; unsigned char flag; } Sub00136540;
typedef struct { void* vtable; Sub00136540 sub; char pad[0x14 - 4 - sizeof(Sub00136540)]; int unk14; } Obj00136540;
extern char D_004D9140[];
#if 0 /* merge_units */
extern void std_vector_cGOBJPtr_ctor_void(Sub00136540* sub);
#endif /* merge_units */
#define std_vector_cGOBJPtr_ctor_void(a0) ((void)std_vector_cGOBJPtr_ctor_void((void *)(a0))) /* merge_units */

extern int cArrayCapacity_Int(void* src);
#if 0 /* merge_units */
extern int std_vector_cGOBJPtr_reserve(Sub00136540* sub, int value);
#endif /* merge_units */
#define std_vector_cGOBJPtr_reserve(a0, a1) (std_vector_cGOBJPtr_reserve((int)(a0), (a1))) /* merge_units */

/* Constructor. */
Obj00136540* cCollisionModelList_ctor(Obj00136540* obj, void* src)
{
    Sub00136540* sub;
    obj->vtable = D_004D9140;
    sub = &obj->sub;
    std_vector_cGOBJPtr_ctor_void(sub);
    std_vector_cGOBJPtr_reserve(sub, cArrayCapacity_Int(src));
    sub->flag = 1;
    obj->unk14 = 0;
    return obj;
}
#undef std_vector_cGOBJPtr_ctor_void /* merge_units */
#undef std_vector_cGOBJPtr_reserve /* merge_units */
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


extern int std_vector_pod_int_reserve(int, int);

int std_vector_cGOBJPtr_reserve(int a0, int a1) {
    return std_vector_pod_int_reserve(a0, a1);
}

Rel* std_vector_cGOBJPtr_ctor_void(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

Rel* std_vector_cNodePtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001365B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001365B0 */
