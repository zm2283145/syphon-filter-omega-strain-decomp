/*
 * Libs/SFOLib/Source/hoglist: 1 file, 003F9B30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F9B30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_0049AE60[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}
inline void* operator new(unsigned int, void* p) { return p; }
struct V4_3F9B30 { float x, y, z, w; V4_3F9B30(const V4_3F9B30& o) { float a = o.x, b = o.y, c = o.z, d = o.w; x = a; y = b; z = c; w = d; } };
struct V3_3F9B30 { float x, y, z; V3_3F9B30(const V3_3F9B30& o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
struct Val_3F9B30 {
    char name[0x80]; int f80; V4_3F9B30 v84; V4_3F9B30 v94; float fA4; int fA8; int fAC;
    V3_3F9B30 vB0; int fBC; unsigned char fC0; char name2[0x80]; int f144; int f148; signed char f14C;
    int f150; int f154; int f158; int f15C; int f160; int f164; unsigned char f168;
};
struct Node_3F9B30 { Node_3F9B30* prev; Node_3F9B30* next; Val_3F9B30 value; };
struct List_3F9B30 { int count; int alloc; };
struct Flag_3F9B30 {
    char c;
    Flag_3F9B30() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_3F9B30() {}
};
struct Holder_3F9B30;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_10(Holder_3F9B30* h);
struct Holder_3F9B30 {
    int* alloc;
    Node_3F9B30* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_3F9B30()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_10(this);
            Node_3F9B30* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_0049AE60, 0x64);
            }
        }
    }
};

#pragma push
#pragma opt_propagation off
extern "C" int std_list_deleter_cHogFile_insert(Node_3F9B30** result, List_3F9B30* list, Node_3F9B30** pos, const Val_3F9B30* value)
{
    Node_3F9B30* n;
    int* alloc = &list->alloc;
    Flag_3F9B30 flag;
    {
        AllocGuard guard;
        n = (Node_3F9B30*)cMemMan_Allocate(0, 0x174, "allocator.hh", 0x5C);
    }
    {
    Holder_3F9B30 h;
    h.alloc = alloc;
    h.node = n;
    Val_3F9B30* v = &h.node->value;
    new (v) Val_3F9B30(*value);
    Node_3F9B30* p;
    Node_3F9B30* m = h.node;
    h.node = 0;
    p = *pos;
    p->prev->next = m;
    m->prev = p->prev;
    p->prev = m;
    m->next = p;
    list->count++;
    *result = m;
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_003F9B30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003F9B30 */
