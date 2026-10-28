#pragma cplusplus on
#include "types.h"

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
} __attribute__((aligned(16)));
static inline void AddV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline V operator+(const V& a, const V& b) { V r; AddV(&r, &a, &b); return r; }
static inline float Dot3(const V* a, const V* b)
{
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
static inline unsigned char IsZero(const V* v)
{
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(v)
        vaddx.xyzw vf1, vf1, vf0x
        and r, zero, zero
        ori k, zero, 0xF
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        bne k, f, done
        nop
        ori r, zero, 1
    done:
        .set reorder
    }
    return (unsigned char)r;
}
static inline void Normalize(V* v)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(v) : "memory");
}
struct W { const V* p; W(const V* q) : p(q) {} };
struct CIt {
    const V* p;
    CIt(const W& w) : p(w.p) {}
    const V& operator*() const { return *p; }
    CIt& operator++() { p++; return *this; }
};
static inline bool operator==(const CIt& a, const CIt& b) { const V* bp = b.p; return a.p == bp; }
static inline bool operator!=(const CIt& a, const CIt& b) { return !(a == b); }
struct ArrV { int p0; int count; int p8; unsigned char canExpand; };
extern "C" V** std_vector_deleter_cVector_data(const ArrV* a);
static inline CIt Begin(const ArrV& a) { return CIt(W(*std_vector_deleter_cVector_data(&a))); }
static inline CIt End(const ArrV& a) { return CIt(W(*std_vector_deleter_cVector_data(&a) + a.count)); }

extern "C" unsigned char CheckPotentiallyStoppedByTaperingSpace(const V& moveDir, const V& faceNormal, const ArrV& prev)
{
    CIt curr = Begin(prev);
    CIt end = End(prev);
    for (; curr != end; ++curr) {
        const V& currNormal = *curr;
        if (Dot3(&faceNormal, &currNormal) < 0.0f) {
            V combinedNormal = faceNormal + currNormal;
            if (Dot3(&moveDir, &combinedNormal) < 0.0f) {
                if (!IsZero(&combinedNormal)) {
                    Normalize(&combinedNormal);
                    if (Dot3(&moveDir, &combinedNormal) < -0.866f) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
