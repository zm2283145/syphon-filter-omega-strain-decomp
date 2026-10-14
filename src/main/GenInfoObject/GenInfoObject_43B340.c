/*
 * main/GenInfoObject: range (2 files, 0043B340-0043B410)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "tree_insert_unique_u32.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "tree_erase3.h"
#pragma pop

/* merge_units: begin func_0043B340 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
static const unsigned int dat_00497590[2] = { 0x1, 0x0 };
static const unsigned int dat_00497598[2] = { 0x0, 0x0 };
TUNode* func_0043B6F0(TUTree* t, TUNode* parent, bool left, bool first,
                 const unsigned int* v);
}
extern "C" void func_0043B340(TUPair* ret, TUTree* t, const unsigned int* v)
{
    bool left = true;
    bool first = left;
    TUNode* y = 0;
    TUNode* parent = (TUNode*)&t->root;
    TUNode* x = t->root;
    while (x) {
        parent = x;
        if (*v < x->key) {
            x = x->left;
            left = true;
        } else {
            y = x;
            x = x->right;
            left = false;
            first = false;
        }
    }
    if (!y || y->key < *v) {
        ret->it = func_0043B6F0(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00497590);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00497598);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0043B340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0043B340 */

/* merge_units: begin func_0043B410 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_TREE_ERASE3(func_0043B410, 0xC, func_0043B9D0, func_0043B9B0, func_0043B9C0, func_0043B910, func_0043B860, D_004BFDB0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0043B410 */
