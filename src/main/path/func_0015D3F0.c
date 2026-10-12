#include "types.h"
#pragma cplusplus on
typedef struct { int idx; int type; } F8Elem_15D;
struct F8It_15D {
    F8Elem_15D* p;
    bool operator==(const F8It_15D& o) const { return p == o.p; }
    bool operator!=(const F8It_15D& o) const { return !(*this == o); }
    F8It_15D& operator++() { p++; return *this; }
    F8Elem_15D* operator->() const { return p; }
};
typedef struct { char pad[0x68]; char list[4]; } F8Obj_15D;
typedef struct { char pad[8]; F8Obj_15D** nodes; } F8Table_15D;
extern "C" {
F8Obj_15D* NpcPath_GetNode(int self);
F8Elem_15D* func_0015D3E0(void* c);
F8Elem_15D* func_0015D3B0(void* c);
F8It_15D func_0015D3D0(void* c, F8Elem_15D** raw);
extern F8Table_15D* D_004FFBE0;
}
static inline F8It_15D F8Begin(void* c) { F8Elem_15D* b = func_0015D3E0(c); return func_0015D3D0(c, &b); }
static inline F8It_15D F8End(void* c) { F8Elem_15D* e = func_0015D3B0(c); return func_0015D3D0(c, &e); }
static inline F8It_15D F8CBegin(void* c) { F8It_15D r; r.p = F8Begin(c).p; return r; }
static inline bool F8More(F8It_15D& it, void* c) { return it != F8End(c); }
extern "C" int NpcPath_LinkType(int from, int to)
{
    int r;
    void* c;
    r = -1;
    c = D_004FFBE0->nodes[from]->list;
    F8It_15D it = F8CBegin(c);
    while (F8More(it, c)) {
        F8Elem_15D* e = it.p;
        if (to == e->idx) {
            r = e->type;
            break;
        }
        it.p = e + 1;
    }
    return r;
}