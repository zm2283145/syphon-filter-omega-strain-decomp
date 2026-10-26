/* NpcRoute_RegionAt: index of the route region whose box contains the point
 * (the hint first); when several boxes overlap, the one with the nearest
 * group node wins. -1 if none. */
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
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
void* NpcPath_GetNode(int id);
V4 Node_GetTranslation(void* node);
void NpcRoute_BuildRegionBoxes(void);
int NpcRoute_NearestGroupNode(int region, V4* p, int mask, int skip);
int NpcRoute_RegionAt(V4* pos, int hint);
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

int NpcRoute_RegionAt(V4* pos, int hint)
{
    int best = -1;
    int count = 0;
    float bestD;
    int i;
    NpcRoute_BuildRegionBoxes();
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
                    n = NpcRoute_NearestGroupNode(best, pos, 0x88, -1);
                    if (n >= 0) {
                        bestD = SumSq(*pos - Node_GetTranslation(NpcPath_GetNode(n)));
                    }
                }
                n = NpcRoute_NearestGroupNode(i, pos, 0x88, -1);
                if (n >= 0) {
                    float d = SumSq(*pos - Node_GetTranslation(NpcPath_GetNode(n)));
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
