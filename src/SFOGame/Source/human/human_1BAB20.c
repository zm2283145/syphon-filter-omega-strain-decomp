/*
 * main/human: range (4 files, 001BAB20-001BADD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop

/* merge_units: begin func_001BAB20 */
#pragma push /* merge_units */
#pragma cplusplus on
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
DEFINE_NET_MSG_CLONE(cNetShockMsg_Clone, 0x30, D_0049D8D0, 0x45BB, D_004DA9F0, NMC_UB(0x24); NMC_F(0x28); NMC_F(0x2C))
#pragma pop /* merge_units */
/* merge_units: end func_001BAB20 */

/* merge_units: begin func_001BAC40 */
#pragma push /* merge_units */
typedef struct { int f0; unsigned int count; int* data; } D2_PtrVec;
typedef struct { int f0; int count; int* data; } D2_PtrVecI;
extern int std_vector_pod_int_insert(D2_PtrVec* v, int* pos, int n, int value);
extern void std_vector_pod_int_erase(D2_PtrVec* v, int* first, int* last);
#pragma opt_common_subs off
void std_vector_pod_int_resize(D2_PtrVec* v, unsigned int n, int value) {
    unsigned int c = v->count;
    if (c < n) {
        std_vector_pod_int_insert(v, v->data + v->count, n - c, value);
    } else if (n < c) {
        int* d = v->data;
        std_vector_pod_int_erase(v, d + n, d + v->count);
    }
}
#pragma opt_common_subs reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BAC40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BAC40 */

/* merge_units: begin func_001BACB0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct C3TcNode { struct C3TcNode* left; struct C3TcNode* right; int pad[2]; char name[0x30]; } C3TcNode;
typedef struct { int pad; C3TcNode* root; } C3TcTree;
extern "C" int Libc_Memcmp(const char* a, const char* b, int n);
static inline bool C3TcLess(const char* a, const char* b)
{
    return !(a[0] == 0 && b[0] == 0) && Libc_Memcmp(a, b, 0x30) < 0;
}
extern "C" void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR(C3TcNode** out, C3TcTree* t, const char* name)
{
    C3TcNode* x = t->root;
    C3TcNode* y = (C3TcNode*)&t->root;
    while (x != 0) {
        if (!C3TcLess(x->name, name)) {
            y = x;
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == (C3TcNode*)&t->root || C3TcLess(name, y->name)) {
        *out = (C3TcNode*)&t->root;
    } else {
        *out = y;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BACB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BACB0 */

/* merge_units: begin func_001BADD0 */
#pragma push /* merge_units */
typedef struct C4Node1BA { struct C4Node1BA* left; struct C4Node1BA* right; int pad[2]; char name[0x20]; } C4Node1BA;
typedef struct { int pad; C4Node1BA header; } C4Tree1BA;
extern int Libc_Memcmp(const char* a, const char* b, int n);
static inline int c4less(const char* a, const char* b) {
    return !(a[0] == 0 && b[0] == 0) && Libc_Memcmp(a, b, 0x20) < 0;
}
void std_tree_pair_cString16N_value_compare_cAllocator_pair_find_cString16NR_2(C4Node1BA** out, C4Tree1BA* t, const char* key) {
    C4Node1BA* x = t->header.left;
    C4Node1BA* y = &t->header;
    while (x) {
        if (!c4less(x->name, key)) {
            y = x;
            x = x->left;
        } else {
            x = x->right;
        }
    }
    if (y == &t->header || c4less(key, y->name)) {
        *out = &t->header;
    } else {
        *out = y;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BADD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BADD0 */
