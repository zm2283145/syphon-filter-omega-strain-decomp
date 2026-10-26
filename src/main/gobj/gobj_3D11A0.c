/*
 * main/gobj: 2 files, 003D11A0-003D1280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D11A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* cText_dtor(void* self, short flags);
void opDelete_nodeP_int_bool_charP_etc_5(void* allocation, int pool, int destroy, char* file, int line);
}
void opDelete_nodeP_int_bool_charP_etc_5(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            cText_dtor((char*)allocation + 16, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D11A0 */

/* merge_units: begin func_003D1280 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004BD318[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void* Mem_PlacementNew(int size, void* p);
}
struct Node1280 {
    Node1280* prev;
    Node1280* next;
    int pad[2];
    char value[0x30];
};
struct List1280 {
    int count;
    int alloc;
};
struct Flag1280 {
    char c;
    Flag1280() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag1280() {}
};
struct Holder1280;
extern "C" {
void* alloc_ptr_node_cAllocator_node_allocator_void_2(Holder1280* h);
Node1280* alloc_ptr_node_cAllocator_node_get_void_2(Holder1280* h);
int alloc_ptr_node_cAllocator_node_capacity_void_2(Holder1280* h);
void cAllocator_node_deallocate_nodeP_uint_6(void* a, Node1280* n, int c);
void cText_ctor(void* d, const void* s);
}
struct Holder1280 {
    int* alloc;
    Node1280* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder1280()
    {
        if (alloc_ptr_node_cAllocator_node_get_void_2(this))
            cAllocator_node_deallocate_nodeP_uint_6(alloc_ptr_node_cAllocator_node_allocator_void_2(this), alloc_ptr_node_cAllocator_node_get_void_2(this), alloc_ptr_node_cAllocator_node_capacity_void_2(this));
    }
};
extern "C" int std_list_deleter_cText_insert(Node1280** result, List1280* list, Node1280** pos, const void* value)
{
    Node1280* n;
    int* alloc = &list->alloc;
    Flag1280 flag;
    {
        AllocGuard guard;
        n = (Node1280*)Mem_Alloc(0, 0x40, D_004BD318, 0x5C);
    }
    Holder1280 h;
    h.alloc = alloc;
    h.node = n;
    void* v = Mem_PlacementNew(0x30, h.node->value);
    if (v)
        cText_ctor(v, value);
    Node1280* p;
    Node1280* m = h.node;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1280 */
