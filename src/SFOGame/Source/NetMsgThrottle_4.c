/*
 * SFOGame/Source/NetMsgThrottle: 1 file, 00472410
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin NetMsgThrottle_472410 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct TENode_func_00472410 { TENode_func_00472410* left; TENode_func_00472410* right; int parentColor; };
extern "C" {
void* func_004728C0(void* t);
void* func_00472880(void* t);
void cAllocator_pair_int_destroy_pairP_7(void* a, void* v);
void cAllocator_node_deallocate_nodeP_uint_19(void* a, TENode_func_00472410* n, int count);
void opDelete_nodeP_int_bool_charP_etc_19(TENode_func_00472410* n, int a, int b, char* file, int ln);
void std_pair_int_sMsgTypeInfo_dtor(void* v, int flags);
void func_00135C90(void* v, int flags);
void std_tree_pair_int_value_compare_destroy_nodeP_6(void* t, TENode_func_00472410* x);
void operator_delete(void* p);
}
static inline void L2_func_00472410(void* t, TENode_func_00472410* g)
{
    if (g->left)
        std_tree_pair_int_value_compare_destroy_nodeP_6(t, g->left);
    if (g->right)
        std_tree_pair_int_value_compare_destroy_nodeP_6(t, g->right);
    cAllocator_pair_int_destroy_pairP_7(func_004728C0(t), (char*)g + 0xC);
    cAllocator_node_deallocate_nodeP_uint_19(func_00472880(t), g, 1);
}
static inline void L1_func_00472410(void* t, TENode_func_00472410* c)
{
    TENode_func_00472410* g;
    if ((g = c->left) != 0)
        L2_func_00472410(t, g);
    if ((g = c->right) != 0)
        L2_func_00472410(t, g);
    func_004728C0(t);
    std_pair_int_sMsgTypeInfo_dtor((char*)c + 0xC, -1);
    func_00472880(t);
    if (c)
        opDelete_nodeP_int_bool_charP_etc_19(c, 0, 0, "allocator.hh", 0x64);
}
static inline void D3_func_00472410(void* p) { if (p) { if (p) func_00135C90(p, 0); } }
static inline void D2_func_00472410(void* p) { if (p) D3_func_00472410(p); }
static inline void D1_func_00472410(char* v) { if (v) D2_func_00472410(v + 4); }
extern "C" void std_tree_pair_int_value_compare_destroy_nodeP_6(void* t, TENode_func_00472410* x)
{
    TENode_func_00472410* c;
    if ((c = x->left) != 0)
        L1_func_00472410(t, c);
    if ((c = x->right) != 0)
        L1_func_00472410(t, c);
    D1_func_00472410((char*)x + 0xC);
    if (x)
        TStr_Free((char*)x, "allocator.hh", 0x64);
}
static inline void merge_flush_NetMsgThrottle_472410(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end NetMsgThrottle_472410 */
