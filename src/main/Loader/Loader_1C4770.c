/*
 * main/Loader: range (2 files, 001C4770-001C4890)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_erase_destroy.h"
#pragma pop

/* merge_units: begin func_001C4770 */
#pragma push /* merge_units */
#pragma cplusplus on
struct K1C4770 { int w[4]; };
struct N1C4770 { N1C4770* left; N1C4770* right; int color; K1C4770 key; };
struct T1C4770 { int count; N1C4770* root; };
struct R1C4770 { N1C4770* node; unsigned char inserted; };
extern "C" {
static const unsigned int dat_0048A320[2] = { 0x1, 0x0 };
static const unsigned int dat_0048A328[2] = { 0 };
int std_basic_string_char_char_traits_char_compare_basicstringR(const K1C4770* a, const K1C4770* b);
N1C4770* Tree_Insert_1C4F20(T1C4770* t, N1C4770* parent, bool left, bool leftmost, const K1C4770* k); }
static inline int K1C4770_less(const K1C4770* a, const K1C4770* b) { int r = std_basic_string_char_char_traits_char_compare_basicstringR(a, b) < 0; return r; }
extern "C" void std_tree_pair_cString_value_compare_insert_one_pairR_2(R1C4770* out, T1C4770* t, const K1C4770* k)
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
        out->node = Tree_Insert_1C4F20(t, y, left, leftmost, k);
        out->inserted = (*(unsigned char*)dat_0048A320);
    } else {
        out->node = j;
        out->inserted = (*(unsigned char*)dat_0048A328);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C4770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C4770 */

/* merge_units: begin func_001C4890 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_ERASE_ELEMENT(E1C4890, 16)
DEFINE_VECTOR_ERASE_DESTROY(std_vector_imp_cArray_int_erase, E1C4890, std_msl_copy_cArray_int_copy, cArray_int_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_001C4890 */
