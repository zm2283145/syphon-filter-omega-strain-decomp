/*
 * Libs/SFOLib/Source/animtexman: 5 files, 003D2710-003D2850
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D2710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Container/iterator helpers; original translation unit not identified yet.
 */

#include "types.h"
#include "loose04_types.h"

extern L4Iter* std_list_deleter_voidPtr_insert(L4Iter* out, Tree* t, L4Iter* pos, int* value);
L4Iter* std_list_cAnimTexturePtr_push_front(Tree* t, int* value);

Word* cLListIterator_cAnimTexturePtr_ctor_cLListIteratorR(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

/* Iterator inequality. */
int opNe_cLListIteratorR_cLListIteratorR_10(L4Iter* a, L4Iter* b) {
    return a->node != b->node;
}

/* Iterator increment. */
L4Iter* cLListIterator_cAnimTexturePtr_opInc(L4Iter* it) {
    it->node = it->node->next;
    return it;
}

/* Iterator dereference. */
int* cLListIterator_cAnimTexturePtr_opMul(L4Iter* it) {
    return &it->node->value;
}

float* cLListIterator_cAnimTexturePtr_opAssign(float* dst, float* src) {
    *dst = *src;
    return dst;
}

void* cLListIterator_cAnimTexturePtr_ctor_void(void* self) {
    return self;
}

/* Inserts a value (by copy). */
void cAnimTexMan_Add(Tree* t, int value) {
    int loc[1];

    loc[0] = value;
    std_list_cAnimTexturePtr_push_front(t, loc);
}

/* Inserts *value using the word at +8 of the container as the position hint. */
L4Iter* std_list_cAnimTexturePtr_push_front(Tree* t, int* value) {
    L4Iter it[2];

    it[0].node = (L4Node*)t->unk8;
    return std_list_deleter_voidPtr_insert(&it[1], t, &it[0], value);
}
static inline void merge_flush_func_003D2710(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2710 */

/* merge_units: begin func_003D27E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; void* vt; } TC8E0;
extern void * const D_004E00A8[];
#if 0 /* merge_units */
extern void std_list_cAnimTexturePtr_dtor(void* self, short del);
#endif /* merge_units */
void* std_list_cAnimTexturePtr_dtor(void* self, short deleteFlag); /* merge_units */
#define std_list_cAnimTexturePtr_dtor(a0, a1) ((void)std_list_cAnimTexturePtr_dtor((a0), (a1))) /* merge_units */

extern void operator_delete(void* p);
TC8E0* cAnimTexMan_dtor(TC8E0* self, short del)
{
    if (self) {
        self->vt = ((char*)D_004E00A8);
        if (self)
            std_list_cAnimTexturePtr_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004E00A8[3] = { (void*)0x0, (void*)0x0, (void*)cAnimTexMan_dtor };
#undef std_list_cAnimTexturePtr_dtor /* merge_units */
static inline void merge_flush_func_003D27E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D27E0 */

/* merge_units: begin func_003D2850 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "obj_list_dtor.h"

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(std_list_cAnimTexturePtr_dtor)
static inline void merge_flush_func_003D2850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2850 */

/* merge_units: begin func_003D28D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern char D_004E00A8[];         /* Unk3D28D0 vtable */
#endif /* merge_units */
#define D_004E00A8 ((char*)&D_004E00A8) /* merge_units */

extern int std_list_deleter_voidPtr_ctor_void(L4ScalarCollection*);

Unk3D28D0* cAnimTexMan_ctor(Unk3D28D0* self) {
    self->vtable = D_004E00A8;
    std_list_deleter_voidPtr_ctor_void(&self->coll);
    self->unk0C = 0;
    return self;
}
#undef D_004E00A8 /* merge_units */
static inline void merge_flush_func_003D28D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D28D0 */

/* merge_units: begin func_003D2910 */
#pragma push /* merge_units */
#pragma cplusplus on
#if 0 /* merge_units */
extern "C" void operator_delete(void* allocation);
#endif /* merge_units */
#define operator_delete(a0) (operator_delete((a0))) /* merge_units */

extern "C" char D_004E0090[];
extern "C" char D_004E0080[];
struct VC_003D2910 { char pad[0x10]; void* vtable; };
extern "C" VC_003D2910* cScrollAnimTexture_dtor(VC_003D2910* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004E0090;
        if (self)
            self->vtable = D_004E0080;
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
static inline void merge_flush_func_003D2910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D2910 */
