/*
 * SFOGame/Source/humanIk: 4 files, 001DF4D0-001DF650
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001DF4D0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(opDelete_nodeP_int_bool_charP_etc_2)
static inline void merge_flush_func_001DF4D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DF4D0 */

/* merge_units: begin func_001DF580 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004A02F8[]; void cMemMan_Deallocate(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint_2(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        cMemMan_Deallocate(0, node, D_004A02F8, 0x64);
    }
}
static inline void merge_flush_func_001DF580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DF580 */

/* merge_units: begin func_001DF620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* std_tree_pair_cWeaponSlotPair_value_compare_node_alloc(char* self) {
    return self + 4;
}

void cAllocator_pair_cWeaponSlotPair_destroy(void) {
}

void* std_tree_pair_cWeaponSlotPair_value_compare_alloc(void* self) {
    return self;
}
static inline void merge_flush_func_001DF620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DF620 */

/* merge_units: begin func_001DF650 */
#pragma push /* merge_units */
#pragma cplusplus on
struct K1DF650 { unsigned char a; unsigned char b; };
struct N1DF650 { N1DF650* left; N1DF650* right; int pad[2]; K1DF650 key; };
struct T1DF650 { int count; N1DF650* root; };
struct R1DF650 { N1DF650* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_0048A958[2] = { 0x1, 0x0 };
static const unsigned int dat_0048A960[2] = { 0 };
N1DF650* std_tree_pair_cWeaponSlotPair_value_compare_insert_node_at(T1DF650* t, N1DF650* parent, bool left, bool leftmost, const K1DF650* k); }
static inline bool K1DF650_less(const K1DF650& x, const K1DF650& y)
{
    return x.a < y.a || (x.a == y.a && x.b < y.b);
}
extern "C" void std_tree_pair_cWeaponSlotPair_value_compare_insert_one(R1DF650* out, T1DF650* t, const K1DF650* k)
{
    bool left = true;
    N1DF650* j = 0;
    N1DF650* x = t->root;
    N1DF650* y = (N1DF650*)&t->root;
    bool leftmost = true;
    while (x) {
        y = x;
        if (K1DF650_less(*k, x->key)) {
            x = x->left;
            left = true;
        } else {
            j = x;
            x = x->right;
            left = false;
            leftmost = false;
        }
    }
    if (j == 0 || K1DF650_less(j->key, *k)) {
        out->node = std_tree_pair_cWeaponSlotPair_value_compare_insert_node_at(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_0048A958);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_0048A960);
    }
}
static inline void merge_flush_func_001DF650(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001DF650 */
