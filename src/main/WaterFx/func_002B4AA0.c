#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004ABFC0[];
extern char D_004ABFD0[];
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
}
inline void* operator new(unsigned int, void* p) { return p; }
struct Q_B4AA0 {
    float x, y, z, w;
    Q_B4AA0(const Q_B4AA0& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct Val_B4AA0 { Q_B4AA0 q0, q1, q2, q3, q4; float f50; float f54; int f58; int f5C; };
struct Node_B4AA0 { Node_B4AA0* prev; Node_B4AA0* next; Val_B4AA0 value; };
struct List_B4AA0 { int count; int alloc; };
struct Flag_B4AA0 {
    char c;
    Flag_B4AA0() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_B4AA0() {}
};
struct E_B4AA0 {};
struct Ptr_B4AA0 : E_B4AA0 { Node_B4AA0* p; Ptr_B4AA0(const E_B4AA0& e, Node_B4AA0* n) : E_B4AA0(e), p(n) {} };
struct Holder_B4AA0;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_7(Holder_B4AA0* h);
struct Holder_B4AA0 {
    int* alloc;
    Node_B4AA0* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_B4AA0()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_7(this);
            Node_B4AA0* p = node;
            if (p) {
                AllocGuard guard;
                cMemMan_Deallocate(0, p, D_004ABFD0, 0x64);
            }
        }
    }
};

static inline Node_B4AA0* NewNode() { AllocGuard guard; return (Node_B4AA0*)cMemMan_Allocate(0, 0x70, D_004ABFC0, 0x5C); }
#pragma push
#pragma opt_propagation off
extern "C" int std_list_deleter_tNode_insert(Node_B4AA0** result, List_B4AA0* list, Node_B4AA0** pos, const Val_B4AA0* value)
{
    Node_B4AA0* n;
    int* alloc = &list->alloc;
    Flag_B4AA0 flag;
    E_B4AA0 f1 = *(E_B4AA0*)&flag;
    n = NewNode();
    {
    Holder_B4AA0 h;
    Ptr_B4AA0 t(f1, n);
    h.node = t.p;
    h.alloc = alloc;
    Val_B4AA0* v = &h.node->value;
    new (v) Val_B4AA0(*value);
    Node_B4AA0* m = h.node;
    Node_B4AA0* p;
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
