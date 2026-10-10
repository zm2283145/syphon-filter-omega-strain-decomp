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
F8Obj_15D* func_0015DDB0(int self);
F8Elem_15D* func_0015D3E0(void* c);
F8Elem_15D* func_0015D3B0(void* c);
F8It_15D func_0015D3D0(void* c, F8Elem_15D** raw);
}
static inline F8It_15D F8Begin(void* c) { F8Elem_15D* b = func_0015D3E0(c); return func_0015D3D0(c, &b); }
static inline F8It_15D F8End(void* c) { F8Elem_15D* e = func_0015D3B0(c); return func_0015D3D0(c, &e); }
static inline F8It_15D F8CBegin(void* c) { F8It_15D r; r.p = F8Begin(c).p; return r; }
static inline bool F8More(F8It_15D& it, void* c) { return it != F8End(c); }
extern "C" int func_0015D680(int self)
{
    int r = -1;
    void* c = func_0015DDB0(self)->list;
    F8It_15D it = F8CBegin(c);
    while (F8More(it, c)) {
        if ((func_0015DDB0(*it)->flags & 8) != 0) {
            r = *it;
            break;
        }
        ++it;
    }
    return r;
}


