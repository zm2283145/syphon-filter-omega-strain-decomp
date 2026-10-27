/*
 * SFOGame/Source/path: 2 files, 0015D680-0015D790
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0015D680 */
#pragma push /* merge_units */
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
F8Obj_15D* cAIPathData_GetNode(int self);
F8Elem_15D* std_vector_imp_tNodeLink_begin_void_2(void* c);
F8Elem_15D* std_vector_imp_tNodeLink_end_void_2(void* c);
F8It_15D std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(void* c, F8Elem_15D** raw);
}
static inline F8It_15D F8Begin(void* c) { F8Elem_15D* b = std_vector_imp_tNodeLink_begin_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &b); }
static inline F8It_15D F8End(void* c) { F8Elem_15D* e = std_vector_imp_tNodeLink_end_void_2(c); return std_vector_tNodeLink_pointer2iterator_tNodeLinkPR_2(c, &e); }
static inline F8It_15D F8CBegin(void* c) { F8It_15D r; r.p = F8Begin(c).p; return r; }
static inline bool F8More(F8It_15D& it, void* c) { return it != F8End(c); }
extern "C" int cAIPathData_GetNextPatrolPathNodeIndex(int self)
{
    int r = -1;
    void* c = cAIPathData_GetNode(self)->list;
    F8It_15D it = F8CBegin(c);
    while (F8More(it, c)) {
        if ((cAIPathData_GetNode(*it)->flags & 8) != 0) {
            r = *it;
            break;
        }
        ++it;
    }
    return r;
}
static inline void merge_flush_func_0015D680(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015D680 */

/* merge_units: begin func_0015D790 */
#pragma push /* merge_units */
/* cAIPathData_GetGroupIndex: index of the route region whose box contains the point
 * (the hint first); when several boxes overlap, the one with the nearest
 * group node wins. -1 if none. */
#pragma cplusplus on
#pragma inline_depth(10)
/* lq/sq and VU0 ops: no C equivalent (asm). */
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(this) } }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void AddXYZ(V4* a, const V4* b)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(a), "r"(b) : "memory");
}
static inline V4 operator-(const V4& a) { V4 r; V4* pr = &r; const V4* pa = &a; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa) : "memory"); return r; }
struct Box0 { V4 lo, hi;
    Box0& operator=(const Box0& o) { __int128 t0; __int128 t1; Box0* d = this; const Box0* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); sq %1, 0x10(%2)" : "=&r"(t0), "=&r"(t1) : "r"(d), "r"(s) : "memory"); return *this; }
};
struct Box : Box0 {
    Box() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
};
struct BoxVec { int p0; int n; Box* data; unsigned char owned; };
struct Region { int p0; int n; int p8[2]; };
struct RegionVec { int p0; int n; Region* data; };
extern "C" {
extern BoxVec* D_004EE118;
extern int D_004FFBE4;
extern RegionVec* D_004FFBE8;
extern char D_0049C1B8[];
#if 0 /* merge_units */
void* cAIPathData_GetNode(int id);
#endif /* merge_units */
#define cAIPathData_GetNode(a0) ((void *)cAIPathData_GetNode((a0))) /* merge_units */

V4 cNode_GetLoc(void* node);
void cAIPathData_InitSystem(void);
int cAIPathData_GetClosestNodeIndex(int region, V4* p, int mask, int skip);
int cAIPathData_GetGroupIndex(V4* pos, int hint);
}

/* VU0 point-in-box test via MAC sign flags (hand-scheduled, .set noreorder) */
static inline unsigned char Contains(Box* b, const V4* p)
{
    int r;
    V4* lo = &b->lo;
    V4* hi = &b->hi;
    asm {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(lo)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline void SubV(V4* pr, const V4* pa, const V4* pb) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory"); }
static inline V4 operator-(const V4& a, const V4& b) { V4 r; SubV(&r, &a, &b); return r; }
static inline float SumSq(V4 v)
{
    V4* p = &v;
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(p)
        vaddw.x vf3, vf0, vf0w
        vmul.xyz vf2, vf1, vf1
        vmulax.x ACC, vf3, vf2x
        vmadday.x ACC, vf3, vf2y
        vmaddz.x vf4, vf3, vf2z
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}

int cAIPathData_GetGroupIndex(V4* pos, int hint)
{
    int best = -1;
    int count = 0;
    float bestD;
    int i;
    cAIPathData_InitSystem();
    if (hint >= 0 && D_004EE118 && Contains(&D_004EE118->data[hint], pos)) {
        best = hint;
    } else
    for (i = 0; i < D_004FFBE4; i++) {
        if (Contains(&D_004EE118->data[i], pos)) {
            if (count == 0) {
                best = i;
            } else {
                int n;
                if (count == 1) {
                    n = cAIPathData_GetClosestNodeIndex(best, pos, 0x88, -1);
                    if (n >= 0) {
                        bestD = SumSq(*pos - cNode_GetLoc(cAIPathData_GetNode(n)));
                    }
                }
                n = cAIPathData_GetClosestNodeIndex(i, pos, 0x88, -1);
                if (n >= 0) {
                    float d = SumSq(*pos - cNode_GetLoc(cAIPathData_GetNode(n)));
                    if (d < bestD) {
                        bestD = d;
                        best = i;
                    }
                }
            }
            count++;
        }
    }
    return best;
}
#undef cAIPathData_GetNode /* merge_units */
static inline void merge_flush_func_0015D790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0015D790 */
