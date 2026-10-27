#include "types.h"
#pragma cplusplus on
#include "tstr_types.h"
struct TENode_func_003CA530 { TENode_func_003CA530* left; TENode_func_003CA530* right; int parentColor; };
extern "C" {
void* std_tree_pair_int_value_compare_cAllocator_pair_alloc_void(void* t);
void* std_tree_pair_int_value_compare_cAllocator_pair_node_alloc_void(void* t);
void cAllocator_pair_int_destroy_pairP(void* a, void* v);
void cAllocator_node_deallocate_nodeP_uint_4(void* a, TENode_func_003CA530* n, int count);
void opDelete_nodeP_int_bool_charP_etc_3(TENode_func_003CA530* n, int a, int b, char* file, int ln);
void std_pair_int_cLList_tQueuedMessage_dtor(void* v, int flags);
void std_list_deleter_tQueuedMessage_dtor(void* v, int flags);
void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP(void* t, TENode_func_003CA530* x);
void operator_delete(void* p);
}
static inline void L2_func_003CA530(void* t, TENode_func_003CA530* g)
{
    if (g->left)
        std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP(t, g->left);
    if (g->right)
        std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP(t, g->right);
    cAllocator_pair_int_destroy_pairP(std_tree_pair_int_value_compare_cAllocator_pair_alloc_void(t), (char*)g + 0xC);
    cAllocator_node_deallocate_nodeP_uint_4(std_tree_pair_int_value_compare_cAllocator_pair_node_alloc_void(t), g, 1);
}
static inline void L1_func_003CA530(void* t, TENode_func_003CA530* c)
{
    TENode_func_003CA530* g;
    if ((g = c->left) != 0)
        L2_func_003CA530(t, g);
    if ((g = c->right) != 0)
        L2_func_003CA530(t, g);
    std_tree_pair_int_value_compare_cAllocator_pair_alloc_void(t);
    std_pair_int_cLList_tQueuedMessage_dtor((char*)c + 0xC, -1);
    std_tree_pair_int_value_compare_cAllocator_pair_node_alloc_void(t);
    if (c)
        opDelete_nodeP_int_bool_charP_etc_3(c, 0, 0, "allocator.hh", 0x64);
}
static inline void D3_func_003CA530(void* p) { if (p) { if (p) std_list_deleter_tQueuedMessage_dtor(p, 0); } }
static inline void D2_func_003CA530(void* p) { if (p) D3_func_003CA530(p); }
static inline void D1_func_003CA530(char* v) { if (v) D2_func_003CA530(v + 4); }
extern "C" void std_tree_pair_int_value_compare_cAllocator_pair_destroy_nodeP(void* t, TENode_func_003CA530* x)
{
    TENode_func_003CA530* c;
    if ((c = x->left) != 0)
        L1_func_003CA530(t, c);
    if ((c = x->right) != 0)
        L1_func_003CA530(t, c);
    D1_func_003CA530((char*)x + 0xC);
    if (x)
        TStr_Free((char*)x, "allocator.hh", 0x64);
}