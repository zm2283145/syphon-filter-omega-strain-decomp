/*
 * Libs/SFOLib/Source/ska: 3 files, 003B4E70-003B4F10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003B4E70 */
#pragma push /* merge_units */
#include "ska_types.h"
#include "types.h"

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
#define std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(a0, a1) ((SkaFlaggedVec *)std_vector_imp_cSkaSwitchItem_ctor_vectorimpR((VecImpl *)(a0), (Vec20 *)(a1))) /* merge_units */



/* Copy-construct: copy the array part, then the flag byte. */
SkaFlaggedVec* cArray_cSkaSwitchItem_ctor_cArrayR(SkaFlaggedVec* dst, SkaFlaggedVec* src) {
    std_vector_imp_cSkaSwitchItem_ctor_vectorimpR(dst, src);
    dst->flag = src->flag;
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003B4E70(void) {}
#undef std_vector_imp_cSkaSwitchItem_ctor_vectorimpR /* merge_units */
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

/* merge_units: begin func_003B4F10 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003B4F10 { virtual int v0(...); };
extern "C" {
int Alloc_Lock(...);                                    
int EnableIntc(...);                                  
void **cMemMan_Allocate(...);                     
int cMemMan_Deallocate(...);                     
int cSkaAnimationSet_AddNode(...);          
void **cSkaAnim_ctor_cSkaAnimDataR(...);               
extern int D_004BCD60;
extern char D_004BCD70;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
}
extern "C" void cSkaAnimationSet_CreateNode_cString16NR_cSkaAnimDataR(int *arg0, int arg1, int arg2, int arg3) {
    int sp6C;
    void **var_s0;

    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    var_s0 = cMemMan_Allocate(0, 0x50, &D_004BCD70, 0x216);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    if (var_s0 != NULL) {
        var_s0 = cSkaAnim_ctor_cSkaAnimDataR(var_s0, arg3);
    }
    cSkaAnimationSet_AddNode(&sp6C, arg1, arg2, var_s0);
    if (sp6C == D_004BCD60) {
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        ((VC003B4F10 *)(var_s0))->v0(-1);
        cMemMan_Deallocate(0, var_s0, &D_004BCD70, 0x21C);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
    }
    *arg0 = sp6C;
}
static inline void merge_flush_func_003B4F10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003B4F10 */
