/*
 * SFOGame/Source/humanAnimData: 4 files, 00209510-00209680
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00209510 */
#pragma push /* merge_units */
#include "types.h"

extern void MEMCPY16(int, int, int);
extern int cString16N_3_Empty(int);

int cString16N_3_opAssign(int a0, int a1) {
    int a2, s0, s1, v0;
    int cond;

    s1 = a0;
    s0 = a1;
    v0 = cString16N_3_Empty(a0);
    cond = v0 == 0;
    a0 = s0;
    if (cond) goto L00209548;
    v0 = cString16N_3_Empty(a0);
    cond = v0 != 0;
    if (cond) goto L00209558;
L00209548:;
    a1 = s0;
    a0 = s1;
    a2 = 0 + 3;
    MEMCPY16(a0, a1, a2);
L00209558:;
    v0 = s1;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_00209510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209510 */

/* merge_units: begin func_00209570 */
#pragma push /* merge_units */
extern int cString_Length(void* s);
extern char* cString_opCast_constcharPtr(void* s);
#pragma optimization_level 1
char* cString16N_3_ctor_cStringR(char* dst, void* s)
{
    int i;
    for (i = 0; i < 47; i++) {
        dst[i] = (i < cString_Length(s)) ? cString_opCast_constcharPtr(s)[i] : 0;
    }
    dst[i] = 0;
    return dst;
}
#pragma optimization_level reset
static inline void merge_flush_func_00209570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209570 */

/* merge_units: begin func_00209620 */
#pragma push /* merge_units */
/* Retail code here was built with different optimizer settings than -O4,p. */
#pragma push
#pragma optimization_level 1

extern int std_basic_string_char_char_traits_char_size(void* obj);
extern void std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(void* obj, int value, int zero, int arg);

/* Forwards std_basic_string_char_char_traits_char_size's result to std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR. */
void std_basic_string_char_char_traits_char_append_basicstringR(void* obj, int arg) {
    std_basic_string_char_char_traits_char_replace_uint_uint_basicstringR(obj, std_basic_string_char_char_traits_char_size(obj), 0, arg);
}

#pragma pop
static inline void merge_flush_func_00209620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209620 */

/* merge_units: begin func_00209680 */
#pragma push /* merge_units */
typedef struct { int a, b, c; } E9680;
typedef struct { int x0; unsigned int count; } V9680;
extern int std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(E9680* first, E9680* last);
extern unsigned int std_vector_imp_cSkaBlendSequenceItem_max_size(V9680* v);
extern void std_msl_error(const char* msg);
extern char D_004A3E70[];
extern void* std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(V9680* v);
extern E9680* cAllocator_cSkaBlendSequenceItem_allocate(void* alloc, int n, int hint);
extern E9680** std_vector_deleter_cSkaBlendSequenceItem_data_void(V9680* v);
extern int* std_vector_deleter_cSkaBlendSequenceItem_cap_void(V9680* v);
extern E9680* std_vector_imp_cSkaBlendSequenceItem_begin_void_2(V9680* v);
extern void cAllocator_cSkaBlendSequenceItem_construct(void* alloc, E9680* p, E9680* src);
#pragma optimization_level 1
void std_vector_imp_cSkaBlendSequenceItem_init(V9680* v, E9680* first, E9680* last)
{
    int x; int* px = &x; /* unused address-taken local: reproduces the retail 16-byte frame slot */
    int n = std_distance_cSkaBlendSequenceItemP_cSkaBlendSequenceItemP(first, last);
    if (v->count > std_vector_imp_cSkaBlendSequenceItem_max_size(v))
        std_msl_error(D_004A3E70);
    if (n != 0) {
        E9680* p;
        *std_vector_deleter_cSkaBlendSequenceItem_data_void(v) = cAllocator_cSkaBlendSequenceItem_allocate(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), n, 0);
        *std_vector_deleter_cSkaBlendSequenceItem_cap_void(v) = n;
        for (p = std_vector_imp_cSkaBlendSequenceItem_begin_void_2(v); first != last; first++) {
            cAllocator_cSkaBlendSequenceItem_construct(std_vector_deleter_cSkaBlendSequenceItem_alloc_void_2(v), p, first);
            p++;
            v->count++;
        }
    }
}
#pragma optimization_level reset
static inline void merge_flush_func_00209680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00209680 */
