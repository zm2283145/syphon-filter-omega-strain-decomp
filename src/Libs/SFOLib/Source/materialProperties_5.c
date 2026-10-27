/*
 * Libs/SFOLib/Source/materialProperties: 5 files, 00408D20-00408D80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00408D20 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(std_pair_cString_int_dtor, String_Dtor)
static inline void merge_flush_func_00408D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408D20 */

/* merge_units: begin func_00408D80 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T8D80;
extern void std_tree_pair_cString_value_compare_destroy_nodeP_4(T8D80* t, void* n);
#if 0 /* merge_units */
extern void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

/* Deleting destructor of a tree owner: erase the root, then delete. */
T8D80* std_map_cString_int_dtor(T8D80* t, short del)
{
    if (t) {
        if (t) {
            if (t->m4)
                std_tree_pair_cString_value_compare_destroy_nodeP_4(t, t->m4);
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#undef operator_delete /* merge_units */
static inline void merge_flush_func_00408D80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408D80 */

/* merge_units: begin func_00408DF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int std_basic_string_char_char_traits_char_ctor_basicstringR(L4Elem124Vec*, int);

void std_vector_cMaterialProperties_pointer2iterator(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

/* end() of the element vector. */
L4Elem124* std_vector_imp_cMaterialProperties_end(L4Elem124Vec* v) {
    return v->data + v->count;
}

int std_make_pair_cString_int(L4Elem124Vec* v, int a1, int value) {
    int ret = std_basic_string_char_char_traits_char_ctor_basicstringR(v, a1);

    v->unk0C = value;
    return ret;
}

Word* cAssocArray_cString_int_Iterator_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_map_cString_int_end(Iter* out, Tree* t) {
    out->p = &t->header;
}

void* std_vector_deleter_cMaterialProperties_data(char* self) {
    return self + 8;
}
static inline void merge_flush_func_00408DF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408DF0 */

/* merge_units: begin func_00408EA0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T8FB0;
T8FB0* cAssocArray_cString_char_dtor(T8FB0* t, short del); /* gsynth: defined below */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Alloc_Lock(int);                                    
int EnableIntc(int);                                  
int cTimerDisable_dtor(char *, int);                            
int cTimerDisable_ctor(char *);                               
#if 0 /* merge_units */
int cAssocArray_cString_char_dtor(int, int);
#endif /* merge_units */
#define cAssocArray_cString_char_dtor(a0, a1) ((int)cAssocArray_cString_char_dtor((T8FB0 *)(a0), (short)(a1))) /* merge_units */


                            
int std_vector_deleter_cMaterialProperties_dtor(int, int);                            
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

typedef struct { int f0; int f4; unsigned char f8; } PS0_00408EA0;
void cMaterialPropertiesTable_Reset(PS0_00408EA0 *arg0) {
    int sp38[2];
    int temp_s1;
    int temp_s1_2;

    if (arg0->f8 != 0) {
        temp_s1 = arg0->f0;
        cTimerDisable_ctor(sp38);
        cAssocArray_cString_char_dtor(temp_s1, -1);
        cMemMan_Deallocate(0, temp_s1, "materialProperties.cc", 0x75);
        cTimerDisable_dtor(sp38, -1);
        arg0->f0 = 0;
        temp_s1_2 = arg0->f4;
        if (g_ProfileLockEnabled != 0) {
            Alloc_Lock(9);
        }
        g_ProfileLockDepth += 1;
        if ((temp_s1_2 != 0) && (temp_s1_2 != 0) && (temp_s1_2 != 0)) {
            std_vector_deleter_cMaterialProperties_dtor(temp_s1_2, 0);
        }
        cMemMan_Deallocate(0, temp_s1_2, "materialProperties.cc", 0x78);
        if (g_ProfileLockEnabled != 0) {
            EnableIntc(9);
        }
        g_ProfileLockDepth -= 1;
        arg0->f4 = 0;
        arg0->f8 = 0U;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00408EA0(void) {}
#undef cAssocArray_cString_char_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00408EA0 */

/* merge_units: begin func_00408FB0 */
#pragma push /* merge_units */
extern void std_tree_pair_cString_value_compare_destroy_nodeP_3(T8FB0* t, void* n);
/* Deleting destructor of a nested tree owner: erase the root, then delete. */
T8FB0* cAssocArray_cString_char_dtor(T8FB0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    std_tree_pair_cString_value_compare_destroy_nodeP_3(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00408FB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00408FB0 */
