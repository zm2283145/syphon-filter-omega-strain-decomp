/*
 * main/path: range (2 files, 0015D3F0-0015D510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0015D3F0 */
#pragma push /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015D3F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015D3F0 */

/* merge_units: begin func_0015D510 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator-=(const V& o) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(this), "r"(this), "r"(&o) : "memory"); return *this; }
    float LenSq() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct RNode { char pad[0x64]; int flags; };
struct NodeMgr { char pad[8]; RNode** nodes; };
struct Group { int pad0; unsigned count; int* ids; int padC; };
struct GroupMgr { char pad[8]; Group* groups; };
extern "C" {
#if 0 /* merge_units */
extern NodeMgr* D_004FFBE0;
#endif /* merge_units */
#define D_004FFBE0 (*(NodeMgr **)&D_004FFBE0) /* merge_units */

extern GroupMgr* D_004FFBE8;
void Node_GetTranslation(V* out, RNode* n);
}
extern "C" int NpcRoute_NearestGroupNode(int group, const V* pos, int mask, int exclude)
{
    int best = -1;
    if (group >= 0) {
        float bestd = 3.4028235e38f;
        NodeMgr* nm = D_004FFBE0;
        Group* g = &D_004FFBE8->groups[group];
        for (unsigned i = 0; i < g->count; i++) {
            int id = g->ids[i];
            if (id != exclude) {
                RNode* n = nm->nodes[id];
                if (mask & n->flags) {
                    V d(*pos);
                    V t;
                    Node_GetTranslation(&t, n);
                    d -= t;
                    float l = d.LenSq();
                    if (l < bestd) {
                        bestd = l;
                        best = id;
                    }
                }
            }
        }
    }
    return best;
}
#undef D_004FFBE0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015D510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015D510 */
