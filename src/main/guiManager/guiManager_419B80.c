/*
 * main/guiManager: 5 files, 00419B80-00419E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419B80 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* std_pair_cString_cFontPtr_dtor(void* self, short flags);
void opDelete_nodeP_int_bool_charP_etc_12(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_nodeP_int_bool_charP_etc_12(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            std_pair_cString_cFontPtr_dtor((char*)allocation + 12, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_00419B80 */

/* merge_units: begin func_00419C60 */
#pragma push /* merge_units */
extern char D_004BF180[];
extern void cTimerDisable_ctor(int* g);
extern void cTimerDisable_dtor(int* g, int del);
#if 0 /* merge_units */
extern void Mem_Free(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define Mem_Free(a0, a1, a2, a3) (Mem_Free((a0), (a1), (char *)(a2), (a3))) /* merge_units */

void cAllocator_node_deallocate_nodeP_uint_13(void* self, void* p)
{
    if (p) {
        int g[1];
        cTimerDisable_ctor(g);
        Mem_Free(0, p, D_004BF180, 100);
        cTimerDisable_dtor(g, -1);
    }
}
#undef Mem_Free /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00419C60 */

/* merge_units: begin func_00419CC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int String_Dtor_138350(void* obj, int flags);

void* std_tree_pair_cString_value_compare_node_alloc_void_3(char* self) {
    return self + 4;
}

/* Destroys obj (flags -1) when it is non-null. */
void cAllocator_pair_cString_destroy_pairP_3(void* self, void* obj) {
    if (obj != 0) {
        String_Dtor_138350(obj, -1);
    }
}

void* std_tree_pair_cString_value_compare_alloc_void_3(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00419CC0 */

/* merge_units: begin func_00419D10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct K1C4770 { int w[4]; };
struct N1C4770 { N1C4770* left; N1C4770* right; int color; K1C4770 key; };
struct T1C4770 { int count; N1C4770* root; };
struct R1C4770 { N1C4770* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_004940F0[2] = { 0x1, 0x0 };
static const unsigned int dat_004940F8[2] = { 0 };
int std_basic_string_char_char_traits_char_compare_basicstringR(const K1C4770* a, const K1C4770* b);
N1C4770* std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR_5(T1C4770* t, N1C4770* parent, bool left, bool leftmost, const K1C4770* k); }
static inline int K1C4770_less(const K1C4770* a, const K1C4770* b) { int r = std_basic_string_char_char_traits_char_compare_basicstringR(a, b) < 0; return r; }
extern "C" void std_tree_pair_cString_value_compare_insert_one_pairR_5(R1C4770* out, T1C4770* t, const K1C4770* k)
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
        out->node = std_tree_pair_cString_value_compare_insert_node_at_nodeP_bool_bool_pairR_5(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_004940F0);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_004940F8);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00419D10 */

/* merge_units: begin func_00419E30 */
#pragma push /* merge_units */
Map* std_tree_pair_cString_value_compare_ctor_valuecompareR_cAllocatorR_5(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_00419E30 */
