/*
 * main/ska: range (2 files, 003B4E70-003B4EB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "ska_types.h"
#include "types.h"

/* merge_units: begin func_003B4E70 */
#pragma push /* merge_units */
typedef struct { char b[20]; } Elem20;
typedef struct { int unk0; int count; Elem20* data; } Vec20;
typedef struct { void* begin; void* end; void* cap; } VecImpl;
VecImpl* std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(VecImpl* self, Vec20* src); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Part of ska.cc (skeletal animation).
 */


#if 0 /* merge_units */
extern SkaFlaggedVec* std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(SkaFlaggedVec* dst, SkaFlaggedVec* src);
#endif /* merge_units */
#define std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(a0, a1) ((SkaFlaggedVec *)std_vector_imp_cSkaSwitchItem_ctor_vectorimpR((void *)(a0), (void *)(a1))) /* merge_units */


/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* cArray_cSkaSwitchItem_ctor_cArrayR(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(dst, src);
    dst->flag = src->flag;
    return dst;
}
#undef std_vector_imp_cSkaSwitchItem_ctor_vectorimpR /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B4E70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B4E70 */

/* merge_units: begin func_003B4EB0 */
#pragma push /* merge_units */
typedef struct { char unused; } Allocator;
extern void std_vector_imp_cSkaSwitchItem_init(VecImpl* self, Elem20* first, Elem20* last, Allocator alloc);

/* Copy-constructs the vector from the range of src. */
VecImpl* std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(VecImpl* self, Vec20* src)
{
    Allocator alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    std_vector_imp_cSkaSwitchItem_init(self, src->data, src->data + src->count, alloc);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B4EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003B4EB0 */
