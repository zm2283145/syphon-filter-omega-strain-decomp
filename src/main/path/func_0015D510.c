#pragma cplusplus on
#include "types.h"
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
extern NodeMgr* D_004FFBE0;
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
