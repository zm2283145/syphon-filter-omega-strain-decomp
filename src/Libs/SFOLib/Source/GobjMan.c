/*
 * main/materialProperties: 6 files, 0040AD30-0040B000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040AD30 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then cMemMan_Deallocate under the guard. */
extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void* std_pair_cString_int_dtor(void* self, short flags);
void opDelete_nodeP_int_bool_charP_etc_9(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_nodeP_int_bool_charP_etc_9(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            std_pair_cString_int_dtor((char*)allocation + 12, -1);
    }
    cMemMan_Deallocate(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040AD30 */

/* merge_units: begin func_0040AE10 */
#pragma push /* merge_units */
extern char D_004BEC68[];
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int del);
#if 0 /* merge_units */
extern void cMemMan_Deallocate(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define cMemMan_Deallocate(a0, a1, a2, a3) (cMemMan_Deallocate((a0), (a1), (char *)(a2), (a3))) /* merge_units */

void cAllocator_node_deallocate_nodeP_uint_10(void* self, void* p)
{
    if (p) {
        int g[1];
        cTimerDisable_ctor(g);
        cMemMan_Deallocate(0, p, D_004BEC68, 100);
        cTimerDisable_dtor(g, -1);
    }
}
#undef cMemMan_Deallocate /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040AE10 */

/* merge_units: begin func_0040AE70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int String_Dtor_138350(void* obj, int flags);

void* std_tree_pair_cString_value_compare_node_alloc_void_2(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void cAllocator_pair_cString_destroy_pairP_2(void* self, void* obj) {
    if (obj != 0) {
        String_Dtor_138350(obj, -1);
    }
}

void* std_tree_pair_cString_value_compare_alloc_void_2(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040AE70 */

/* merge_units: begin func_0040AEC0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct K1C4770 { int w[4]; };
struct N1C4770 { N1C4770* left; N1C4770* right; int color; K1C4770 key; };
struct T1C4770 { int count; N1C4770* root; };
struct R1C4770 { N1C4770* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_00493C08[2] = { 0x1, 0x0 };
static const unsigned int dat_00493C10[2] = { 0 };
int std_basic_string_char_char_traits_char_compare_basicstringR(const K1C4770* a, const K1C4770* b);
N1C4770* std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR_4(T1C4770* t, N1C4770* parent, bool left, bool leftmost, const K1C4770* k); }
static inline int K1C4770_less(const K1C4770* a, const K1C4770* b) { int r = std_basic_string_char_char_traits_char_compare_basicstringR(a, b) < 0; return r; }
extern "C" void std_tree_pair_cString_value_compare_insert_one_pairR_4(R1C4770* out, T1C4770* t, const K1C4770* k)
{
    N1C4770* j;
    N1C4770* y;
    N1C4770* x;
    bool left;
    bool leftmost;
    left = true;
    leftmost = left;
    j = 0;
    y = (N1C4770*)&t->root;
    x = t->root;

    while (x) {
        y = x;
        if (K1C4770_less(k, &x->key)) {
            x = x->left;
            left = true;
        } else {
            j = x;
            x = x->right;
            left = false;
            leftmost = false;
        }
    }
    if (j == 0 || K1C4770_less(&j->key, k)) {
        out->node = std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR_4(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_00493C08);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_00493C10);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040AEC0 */

/* merge_units: begin func_0040AFE0 */
#pragma push /* merge_units */
Map* std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_4(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040AFE0 */

/* merge_units: begin func_0040B000 */
#pragma push /* merge_units */
typedef struct { char d[0x124]; } RB000;
typedef struct { int m0; unsigned int size; RB000* data; } VB000;
extern void cMaterialProperties_dtor(RB000* r, short del);
/* Destroys every record and sets the size to zero. */
void std_vector_deleter_cMaterialProperties_clear(VB000* v) {
    RB000* b = v->data;
    RB000* e = b + v->size;
    while (b < e) {
        --e;
        cMaterialProperties_dtor(e, -1);
    }
    v->size = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040B000 */
