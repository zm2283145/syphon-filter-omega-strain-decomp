#include "types.h"
#pragma cplusplus on
typedef struct { int obj; int pad; } F8Elem_15D;
struct F8It_15D {
    F8Elem_15D* p;
    bool operator==(const F8It_15D& o) const { return p == o.p; }
    bool operator!=(const F8It_15D& o) const { return !(*this == o); }
    F8It_15D& operator++() { p++; return *this; }
    int& operator*() const { return p->obj; }
};
typedef struct { char pad[0x64]; int flags; char list[4]; } F8Obj_15D;
extern "C" {
F8Obj_15D* NpcPath_GetNode(int self);
F8Elem_15D* std_vector_imp_tNodeLink_begin_void_2(void* c);
F8Elem_15D* std_vector_imp_tNodeLink_end_void_2(void* c);
F8It_15D std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(void* c, F8Elem_15D** raw);
}
static inline F8It_15D F8Begin(void* c) { F8Elem_15D* b = std_vector_imp_tNodeLink_begin_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &b); }
static inline F8It_15D F8End(void* c) { F8Elem_15D* e = std_vector_imp_tNodeLink_end_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &e); }
static inline F8It_15D F8CBegin(void* c) { F8It_15D r; r.p = F8Begin(c).p; return r; }
static inline bool F8More(F8It_15D& it, void* c) { return it != F8End(c); }
extern "C" int NpcPath_NextPatrolNode(int self)
{
    int r = -1;
    void* c = NpcPath_GetNode(self)->list;
    F8It_15D it = F8CBegin(c);
    while (F8More(it, c)) {
        if ((NpcPath_GetNode(*it)->flags & 8) != 0) {
            r = *it;
            break;
        }
        ++it;
    }
    return r;
}


