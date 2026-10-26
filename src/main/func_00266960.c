#pragma cplusplus on
#pragma always_inline on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
extern char D_004A8270[];
extern char D_004A8280[];
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
}
inline void* operator new(unsigned int, void* p) { return p; }
struct M_66960 {
    float m[4][4];
    M_66960(const M_66960& o) { void* xx = this; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
struct Val_66960 { int a; float b; M_66960 m; };
struct Node_66960 { Node_66960* prev; Node_66960* next; Val_66960 value; };
struct List_66960 { int count; int alloc; };
struct Flag_66960 {
    char c;
    Flag_66960() { c = 0; }
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Flag_66960() {}
};
struct E_66960 {};
struct Ptr_66960 : E_66960 { Node_66960* p; Ptr_66960(const E_66960& e, Node_66960* n) : E_66960(e), p(n) {} };
struct Holder_66960;
extern "C" void details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(Holder_66960* h);
struct Holder_66960 {
    int* alloc;
    Node_66960* node;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~Holder_66960()
    {
        if (node) {
            details_compressed_pair_imp_cAllocator_node_compressed_pair_number_second_void_6(this);
            Node_66960* p = node;
            if (p) {
                AllocGuard guard;
                Mem_Free(0, p, D_004A8280, 0x64);
            }
        }
    }
};

static inline Node_66960* NewNode() { AllocGuard guard; return (Node_66960*)Mem_Alloc(0, 0x60, D_004A8270, 0x5C); }
#pragma push
#pragma opt_propagation off
extern "C" int std_list_deleter_TaserPulse_insert(Node_66960** result, List_66960* list, Node_66960** pos, const Val_66960* value)
{
    Node_66960* n;
    int* alloc = &list->alloc;
    Flag_66960 flag;
    E_66960 f1 = *(E_66960*)&flag;
    n = NewNode();
    {
    Holder_66960 h;
    Ptr_66960 t(f1, n);
    h.node = t.p;
    h.alloc = alloc;
    Val_66960* v = &h.node->value;
    new (v) Val_66960(*value);
    Node_66960* m = h.node;
    Node_66960* p;
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
