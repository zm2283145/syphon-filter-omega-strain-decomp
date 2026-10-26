/*
 * main/weapon: 5 files, 0013F5F0-0013F800
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013F5F0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(opDelete_nodeP_int_bool_charP_etc)
#pragma pop /* merge_units */
/* merge_units: end func_0013F5F0 */

/* merge_units: begin func_0013F6A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_0049B030[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void cAllocator_node_deallocate_nodeP_uint(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_0049B030, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F6A0 */

/* merge_units: begin func_0013F740 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* std_tree_pair_float_value_compare_node_alloc(char* self) {
    return self + 4;
}

void cAllocator_pair_float_destroy(void) {
}

void* std_tree_pair_float_value_compare_alloc(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F740 */

/* merge_units: begin func_0013F770 */
#pragma push /* merge_units */
/* float-keyed tree: find insert position, then insert via Tree_Insert_13F820 */
typedef struct C3FtNode { struct C3FtNode* left; struct C3FtNode* right; int pad; float key; } C3FtNode;
typedef struct { int pad; C3FtNode* root; } C3FtTree;
extern C3FtNode* Tree_Insert_13F820(C3FtTree* t, C3FtNode* parent, unsigned char left, unsigned char leftmost, float* key);
void SceneDrawMap_Insert(C3FtNode** out, C3FtTree* t, float* key)
{
    C3FtNode* parent = (C3FtNode*)&t->root;
    C3FtNode* n = t->root;
    unsigned char left = 1;
    unsigned char leftmost = left;
    while (n != 0) {
        parent = n;
        if (*key < n->key) {
            n = n->left;
            left = 1;
        } else {
            n = n->right;
            left = 0;
            leftmost = 0;
        }
    }
    *out = Tree_Insert_13F820(t, parent, left, leftmost, key);
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F770 */

/* merge_units: begin func_0013F800 */
#pragma push /* merge_units */
Map* std_tree_pair_float_value_compare_ctor(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0013F800 */
