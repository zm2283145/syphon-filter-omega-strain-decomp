/*
 * main/GobjMan: 2 files, 0040CC40-0040CD10
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040CC40 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tree_insert_unique_u32.h"

extern "C" {
static const unsigned int dat_00493C28[2] = { 0x1, 0x0 };
static const unsigned int dat_00493C30[4] = { 0x0, 0x0, 0x0, 0x0 };
TUNode* func_0040CFF0(TUTree* t, TUNode* parent, bool left, bool first,
                 const unsigned int* v);
}
extern "C" void ObjMap_Insert(TUPair* ret, TUTree* t, const unsigned int* v)
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
        ret->it = func_0040CFF0(t, parent, left, first, v);
        ret->ok = (*(bool*)dat_00493C28);
    } else {
        ret->it = y;
        ret->ok = (*(bool*)dat_00493C30);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040CC40 */

/* merge_units: begin func_0040CD10 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "tree_erase3.h"

DEFINE_TREE_ERASE3(func_0040CD10, 0xC, func_0040D2D0, func_0040D2B0, func_0040D2C0, func_0040D210, func_0040D160, D_004BECF0, 0x64)
#pragma pop /* merge_units */
/* merge_units: end func_0040CD10 */
