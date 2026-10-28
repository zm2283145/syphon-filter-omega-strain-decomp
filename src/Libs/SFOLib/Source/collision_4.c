/*
 * Libs/SFOLib/Source/collision: 2 files, 003BDF20-003BDF60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BDF20 */
#pragma push /* merge_units */
#include "types.h"
#include "vu0_ops.h"
int cVector_IsZero(void* v) {
    return VU0_IsZero4(v);
}
static inline void merge_flush_func_003BDF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BDF20 */

/* merge_units: begin func_003BDF60 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
static inline void QQ(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { void* xx = this; QQ(this, &o); }
    V& operator=(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); return *this; }
    V operator+(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator-(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V operator*(float s) const {
        V c; __int128 t = 0; V* q = &c; const V* v = this;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    V SubA(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory"); return c; }
    V SubB(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&b), "r"(this), "r"(&c) : "memory"); return c; }
    V SubC(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(&c), "r"(this) : "memory"); return c; }
    V SubD(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&b), "r"(this) : "memory"); return c; }
    V SubE(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
    V SubF(const V& b) const { V c; const V* bb = &b; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(this), "r"(bb), "r"(&c) : "memory"); return c; }
    V SubG(const V& b) const { V c; const V* tt = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(tt), "r"(&b), "r"(&c) : "memory"); return c; }
    V SubP(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
    V S0(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V A0(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory");
        return c;
    }
    V S1(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&b), "r"(this) : "memory");
        return c;
    }
    V A1(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&b), "r"(this) : "memory");
        return c;
    }
    V S2(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
    V A2(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory");
        return c;
    }
    V S3(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(this), "r"(&b), "r"(&c) : "memory");
        return c;
    }
    V A3(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(this), "r"(&b), "r"(&c) : "memory");
        return c;
    }
    V S4(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(&c), "r"(this) : "memory");
        return c;
    }
    V S3B(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
    V S4B(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
    V A4B(const V& b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
    V A4(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(&c), "r"(this) : "memory");
        return c;
    }
    V S5(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&b), "r"(this), "r"(&c) : "memory");
        return c;
    }
    V A5(const V& b) const {
        V c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&b), "r"(this), "r"(&c) : "memory");
        return c;
    }
    float DotV(const V& b) const {
        float r = 0.0f; int t;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this), "r"(&b) : "memory");
        return r;
    }
    V MulB(float s) const {
        V c; const V* v = this; __int128 t = 0; V* q = &c;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory");
        return c;
    }
    float Dot2(const V& b) const {
        float r = 0.0f; int t;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&b), "r"(this) : "memory");
        return r;
    }
    float Dot(const V& b) const {
        float r = 0.0f; int t;
        __asm__ volatile("lqc2 $vf1, 0x0(%3); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %1, %1, %1; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(&b), "r"(this) : "memory");
        return r;
    }
    float DotX(const V& b) const {
        float r = 0.0f; int t, u;
        __asm__ volatile("lqc2 $vf1, 0x0(%4); lqc2 $vf2, 0x0(%3); vmul.xyzw $vf3, $vf1, $vf2; mtsah $0, 6; vmulax.w $ACC, $vf0, $vf3x; vmadday.w $ACC, $vf0, $vf3y; vmaddz.w $vf4, $vf0, $vf3z; qmfc2.ni %1, $vf4; qfsrv %2, %1, %1; mtc1 %2, %0" : "+f"(r), "=&r"(t), "=&r"(u) : "r"(&b), "r"(this) : "memory");
        return r;
    }
    void Neg() { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory"); }
    V& N2() { V* p = this; __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(p) : "memory"); return *p; }
    V& Normalize() {
        void* xx = this;
        __asm__ volatile("lqc2 $vf1, 0x0(%0); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vrsqrt $Q, $vf0w, $vf3w; vwaitq; vmulq.xyz $vf1, $vf1, $Q; sqc2 $vf1, 0x0(%0)" : : "r"(this) : "memory");
        return *this;
    }
    unsigned char IsZero() const {
        const void* xx = this;
        int z = 0;
        int k, fl, r;
        const V* v = this;
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
            cfc2.ni fl, vi17
            bne k, fl, done
            nop
            ori r, zero, 1
        done:
            .set reorder
        }
        return r;
    }
    V SubPV(V b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory"); return c; }
    V A2V(V b) const { V c; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(this), "r"(&c), "r"(&b) : "memory"); return c; }
    void MulOutB(float s, V* out) const { __int128 t = 0; const V* v = this; V* q = out; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    void MulOut(float s, V* out) const { __int128 t = 0; V* q = out; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    void MulOutR(float s, V*& out) const { __int128 t = 0; V* q = out; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    struct VD0 MulD0(float s) const; struct VD0 SubD0(const V& b) const; struct VD0 AddD0(const V& b) const;
    struct VD1 MulD1(float s) const; struct VD1 SubD1(const V& b) const; struct VD1 AddD1(const V& b) const;
    struct VD2 MulD2(float s) const; struct VD2 SubD2(const V& b) const; struct VD2 AddD2(const V& b) const;
    struct VD3 MulD3(float s) const; struct VD3 SubD3(const V& b) const; struct VD3 AddD3(const V& b) const;
    struct VD4 MulD4(float s) const; struct VD4 SubD4(const V& b) const; struct VD4 AddD4(const V& b) const;
    struct VD5 MulD5(float s) const; struct VD5 SubD5(const V& b) const; struct VD5 AddD5(const V& b) const;
    struct VD6 MulD6(float s) const; struct VD6 SubD6(const V& b) const; struct VD6 AddD6(const V& b) const;
    struct VD7 MulD7(float s) const; struct VD7 SubD7(const V& b) const; struct VD7 AddD7(const V& b) const;
    struct VD8 MulD8(float s) const; struct VD8 SubD8(const V& b) const; struct VD8 AddD8(const V& b) const;
    struct VD9 MulD9(float s) const; struct VD9 SubD9(const V& b) const; struct VD9 AddD9(const V& b) const;
    V Unit() const { const V* s = this; V r = *s; V& n = r.N2(); return n; }
    V Unit0() const { V r = *this; V& n = r.N2(); return n; }
} __attribute__((aligned(16)));
static inline V MulV(const V& n, float s) { V m; n.MulOutB(s, &m); return m; }
static inline V MulV2(const V& n, float s) { V m; V* mp = &m; n.MulOutR(s, mp); return *mp; }
struct VD0 : V { VD0() {} VD0(const VD0& o) { void* xx = this; QQ(this, &o); } } __attribute__((aligned(16)));
inline VD0 V::MulD0(float s) const { VD0 c; __int128 t = 0; VD0* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD0 V::SubD0(const V& b) const { VD0 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD0 V::AddD0(const V& b) const { VD0 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD1 : V { VD1() {} VD1(const VD1& o) { QQ(this, &o); } } __attribute__((aligned(16)));
inline VD1 V::MulD1(float s) const { VD1 c; __int128 t = 0; VD1* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD1 V::SubD1(const V& b) const { VD1 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD1 V::AddD1(const V& b) const { VD1 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD2 : V { VD2() {} VD2(const VD2& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory"); } } __attribute__((aligned(16)));
inline VD2 V::MulD2(float s) const { VD2 c; __int128 t = 0; VD2* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD2 V::SubD2(const V& b) const { VD2 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD2 V::AddD2(const V& b) const { VD2 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD3 : V { VD3() {} VD3(const VD3& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory"); } } __attribute__((aligned(16)));
inline VD3 V::MulD3(float s) const { VD3 c; __int128 t = 0; VD3* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD3 V::SubD3(const V& b) const { VD3 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD3 V::AddD3(const V& b) const { VD3 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD4 : V { VD4() {} VD4(const VD4& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
inline VD4 V::MulD4(float s) const { VD4 c; __int128 t = 0; VD4* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD4 V::SubD4(const V& b) const { VD4 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD4 V::AddD4(const V& b) const { VD4 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD5 : V { VD5() {} VD5(const VD5& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); } } __attribute__((aligned(16)));
inline VD5 V::MulD5(float s) const { VD5 c; __int128 t = 0; VD5* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD5 V::SubD5(const V& b) const { VD5 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD5 V::AddD5(const V& b) const { VD5 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD6 : V { VD6() {} VD6(const VD6& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(this) : "memory"); } } __attribute__((aligned(16)));
inline VD6 V::MulD6(float s) const { VD6 c; __int128 t = 0; VD6* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD6 V::SubD6(const V& b) const { VD6 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD6 V::AddD6(const V& b) const { VD6 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD7 : V { VD7() {} VD7(const VD7& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(&o) : "memory"); __asm__ volatile("sq %1, 0x0(%0)" : : "r"(this), "r"(t) : "memory"); } } __attribute__((aligned(16)));
inline VD7 V::MulD7(float s) const { VD7 c; __int128 t = 0; VD7* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD7 V::SubD7(const V& b) const { VD7 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD7 V::AddD7(const V& b) const { VD7 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD8 : V { VD8() {} VD8(const VD8& o) { const V* s = &o; void* d = this; QQ(d, s); } } __attribute__((aligned(16)));
inline VD8 V::MulD8(float s) const { VD8 c; __int128 t = 0; VD8* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD8 V::SubD8(const V& b) const { VD8 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD8 V::AddD8(const V& b) const { VD8 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
struct VD9 : V { VD9() {} VD9(const VD9& o) { const V* s = &o; QQ(this, s); } } __attribute__((aligned(16)));
inline VD9 V::MulD9(float s) const { VD9 c; __int128 t = 0; VD9* q = &c; const V* v = this; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); return c; }
inline VD9 V::SubD9(const V& b) const { VD9 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
inline VD9 V::AddD9(const V& b) const { VD9 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(this), "r"(&b) : "memory"); return c; }
static inline VD0 MulVD0(const V& n, float s) { VD0 m; n.MulOut(s, &m); return m; }
static inline VD1 MulVD1(const V& n, float s) { VD1 m; n.MulOut(s, &m); return m; }
static inline VD2 MulVD2(const V& n, float s) { VD2 m; n.MulOut(s, &m); return m; }
static inline VD3 MulVD3(const V& n, float s) { VD3 m; n.MulOut(s, &m); return m; }
static inline VD4 MulVD4(const V& n, float s) { VD4 m; n.MulOut(s, &m); return m; }
static inline VD5 MulVD5(const V& n, float s) { VD5 m; n.MulOut(s, &m); return m; }
static inline VD6 MulVD6(const V& n, float s) { VD6 m; n.MulOut(s, &m); return m; }
static inline VD7 MulVD7(const V& n, float s) { VD7 m; n.MulOut(s, &m); return m; }
static inline VD8 MulVD8(const V& n, float s) { VD8 m; n.MulOut(s, &m); return m; }
static inline VD9 MulVD9(const V& n, float s) { VD9 m; n.MulOut(s, &m); return m; }
struct VM : V { VM() {} VM(const VM& o) { void* d; __int128 t; const V* s = &o; d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
struct VT : V { VT() {} VT(const VT& o) { void* xx = this; const V* s = &o; void* d; __int128 t; d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); } VT& operator=(const V& o) { V::operator=(o); return *this; } } __attribute__((aligned(16)));
static inline VT SubT(const V& a, const V& b) { VT c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
struct VN : V { VN() {} VN(const VN& o) { void* xx = this; const V* s = &o; void* d; __int128 t; d = this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
static inline VN MulN(const V& n, float s) { VN m; n.MulOutB(s, &m); return m; }
static inline VM MulM(const V& q, float s) { VM c; q.MulOut(s, &c); return c; }
static inline V FS0(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory");
    return c;
}
static inline V FA0(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory");
    return c;
}
static inline V FS1(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&b), "r"(&a) : "memory");
    return c;
}
static inline V FA1(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&b), "r"(&a) : "memory");
    return c;
}
static inline V FS2(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&a), "r"(&c), "r"(&b) : "memory");
    return c;
}
static inline V FA2(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&a), "r"(&c), "r"(&b) : "memory");
    return c;
}
struct VE : V { VE() {} VE(const VE& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(this), "r"(&o) : "memory"); } } __attribute__((aligned(16)));
static inline VE AddE(const V& a, const V& b) { VE c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
static inline V SubE(const V& a, const V& b) { V c; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&a), "r"(&c), "r"(&b) : "memory"); return c; }
static inline void SubTo(V* c, const V& a, const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&a), "r"(c), "r"(&b) : "memory"); }
static inline void SubTo2(V* c, const V& a, const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(c), "r"(&a), "r"(&b) : "memory"); }
static inline V SubW1(const V& a, const V& b) { V c; SubTo(&c, a, b); return c; }
static inline V SubW2(const V& a, const V& b) { V c; SubTo2(&c, a, b); return c; }
static inline V SubE2(const V& a, const V& b) { return SubE(a, b); }
static inline void SubTo3(V* c, const V& a, const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&b), "r"(&a), "r"(c) : "memory"); }
static inline void SubTo4(V* c, const V& a, const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&a), "r"(&b), "r"(c) : "memory"); }
static inline V SubW3(const V& a, const V& b) { V c; SubTo3(&c, a, b); return c; }
static inline V SubW4(const V& a, const V& b) { V c; SubTo4(&c, a, b); return c; }
static inline void ZA2(V* c, const V& a, const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(c), "r"(&a), "r"(&b) : "memory"); }
static inline void ZB2(V* c, const V& a, const V& b) { ZA2(c, a, b); }
static inline void ZC2(V* c, const V& a, const V& b) { ZB2(c, a, b); }
static inline V ZW3_2(const V& a, const V& b) { V c; ZB2(&c, a, b); return c; }
static inline V ZW4_2(const V& a, const V& b) { V c; ZC2(&c, a, b); return c; }
static inline V FS3(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&a), "r"(&b), "r"(&c) : "memory");
    return c;
}
static inline V FA3(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&a), "r"(&b), "r"(&c) : "memory");
    return c;
}
static inline V FS4(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(&c), "r"(&a) : "memory");
    return c;
}
static inline V FA4(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%2); lqc2 $vf2, 0x0(%0); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(&c), "r"(&a) : "memory");
    return c;
}
static inline V FS5(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&b), "r"(&a), "r"(&c) : "memory");
    return c;
}
static inline V FA5(const V& a, const V& b) {
    V c;
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%2)" : : "r"(&b), "r"(&a), "r"(&c) : "memory");
    return c;
}
struct Box { V mn; V mx; };
struct CT {
    V p[3];
    V n;
    unsigned char flags; char pad41[0x1F];
    V v60;
};
struct VecRecordList;
extern "C" int std_vector_imp_cVector_insert(VecRecordList* list, V* pos, int n, V* value);
struct VecRecordList { int unk0; int count; V* data; V* End() { V** p = &data; return *p + count; } void Push(V* v) { std_vector_imp_cVector_insert(this, End(), 1, v); } };
extern "C" {
extern VecRecordList* D_00542D00;
V* cCollisionFace_UnitNormal(CT* t);
float cVector_X_void(V* v);
float cVector_Y_void(V* v);
float cVector_Z_void(V* v);
float Math_Fabs(float f);
V* cCollisionFace_Vertex(CT* t, int i);
void cVector_opSub(V* out, const V* a, const V* b);
int CheckPotentiallyStoppedByTaperingSpace(V* a, V* b, VecRecordList* l);
void cBox_Empty(Box* b);
void cBox_Include(Box* b, V* v);
void cVector_opAdd(V* out, V* a, V* b);
void cBox_Grow(Box* b, float r);
int std_vector_imp_cVector_insert(VecRecordList* list, V* pos, int n, V* value);
}
struct CQ {
    unsigned char b0; char pad1[0xF];
    V v10; char pad20[0x20];
    V v40; char pad50[0x10];
    V v60;
    V v70; char pad80[0x10];
    V v90;
    float fA0; char padA4[0xC];
    Box box;
    int xD0; float fD4; float fD8; char padDC[4];
    V vE0; char padF0[0x10];
    float f100, f104, f108, f10C;
    unsigned char b110; char pad111[3]; float f114; unsigned char b118; unsigned char b119;
    V Dest() const { return vE0 + v70; }
    void UM3() {
        fA0 = v70.Dot2(v70);
        cBox_Empty(&box);
        cBox_Include(&box, &vE0);
        V t;
        cVector_opAdd(&t, &vE0, &v70);
        cBox_Include(&box, &t);
        cBox_Grow(&box, fD4);
    }
    void UM2() { UM3(); }
    void UM1() { UM2(); }
    void UpdateMove() { UM1(); }
};
extern "C" unsigned char cCollisionProbe_SphereSweptRay_TestFaceEdgesAndVertices(CQ* q, CT* tri, void* r);

static inline unsigned char TriBoxOverlap(CT* tri, Box* b)
{
    int r;
    V* p0 = &tri->p[0];
    V* p1;
    V* p2;
    p2 = &tri->p[2];
    p1 = &tri->p[1];
    V* mn = &b->mn;
    V* mx = &b->mx;
    asm {
        .set noreorder
        lqc2 vf1, 0(p0)
        lqc2 vf2, 0(p1)
        vmax.xyz vf5, vf1, vf2
        vmini.xyz vf4, vf1, vf2
        lqc2 vf3, 0(p2)
        vmax.xyz vf5, vf5, vf3
        vmini.xyz vf4, vf4, vf3
        lqc2 vf6, 0(mn)
        vsub.xyz vf7, vf5, vf6
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf6, 0(mx)
        vsub.xyz vf7, vf6, vf4
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
static inline float Clamp(float x, float lo, float hi) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2; min.s %0, %0, %3" : "+f"(r) : "f"(x), "f"(lo), "f"(hi)); return r; }
static inline float Sign(float x) { return x > 0.0f ? 1.0f : -1.0f; }
static inline bool InUnit(float u, float v) { return u >= 0.0f && v >= 0.0f; }
static inline bool PIT3(CT* tri, const V* P)
{
    int axis;
    float ax = Math_Fabs(cVector_X_void(cCollisionFace_UnitNormal(tri)));
    float ay = Math_Fabs(cVector_Y_void(cCollisionFace_UnitNormal(tri)));
    float az = Math_Fabs(cVector_Z_void(cCollisionFace_UnitNormal(tri)));
    if (!(ax <= ay)) { if (!(az <= ax)) axis = 2; else axis = 0; }
    else { if (!(ay <= az)) axis = 1; else axis = 2; }
    V e1; cVector_opSub(&e1, cCollisionFace_Vertex(tri, 1), cCollisionFace_Vertex(tri, 0));
    V e2; cVector_opSub(&e2, cCollisionFace_Vertex(tri, 2), cCollisionFace_Vertex(tri, 0));
    V d; cVector_opSub(&d, P, cCollisionFace_Vertex(tri, 0));
    float u, v;
    switch ((unsigned char)axis) {
    case 0: {
        float det = e1.y * e2.z - e1.z * e2.y;
        float inv = 1.0f / det;
        u = inv * (e2.z * d.y - e2.y * d.z);
        v = inv * (d.z * e1.y - d.y * e1.z);
        break;
    }
    case 1: {
        float det = e1.z * e2.x - e1.x * e2.z;
        float inv = 1.0f / det;
        u = inv * (e2.x * d.z - e2.z * d.x);
        v = inv * (d.x * e1.z - d.z * e1.x);
        break;
    }
    case 2: {
        float det = e1.x * e2.y - e1.y * e2.x;
        float inv = 1.0f / det;
        u = inv * (e2.y * d.x - e2.x * d.y);
        v = inv * (d.y * e1.x - d.x * e1.y);
        break;
    }
    }
    bool r = false;
    if (InUnit(u, v) && u + v <= 1.0f) r = true;
    return r;
}
static inline bool PIT2(CT* tri, const V* P) { return PIT3(tri, P); }
static inline bool PIT1(CT* tri, const V* P) { return PIT2(tri, P); }
static inline bool PointInTri(CT* tri, const V* P) { return PIT1(tri, P); }
static inline int Is(unsigned char m, int k) { return m == k; }
static inline bool A1(CQ* q)
{
    unsigned char m = q->b110;
    return Is(m, 4) || Is(m, 5);
}
static inline bool A2(CQ* q) { bool r = true; if (!A1(q) && !Is(q->b110, 1)) r = false; return r; }
static inline bool A3(CQ* q) { bool r = true; if (!A2(q) && !Is(q->b110, 2)) r = false; return r; }
static inline bool A4(CQ* q) { bool r = true; if (!A3(q) && !Is(q->b110, 3)) r = false; return r; }
static inline bool Allowed(CQ* q) { bool r = false; if (A4(q) && q->b118) r = true; return r; }


extern "C" unsigned char cCollisionProbe_SphereSweptRay_DetectForCollision_cCollisionFaceR(CQ* q, CT* tri)
{
    unsigned char hit = 0;
    if (!TriBoxOverlap(tri, &q->box))
        return 0;
    V d = q->vE0 - tri->p[0];
    float dist = d.DotX(tri->n);
    if ((tri->flags & 2) && dist < 0.0f) {
        tri->n.Neg();
        dist = -dist;
    }
    if (!(dist < q->f108)) {
        float nd = -q->v90.Dot(tri->n);
        if (!(nd < q->f100)) {
            float md = -q->v70.Dot(tri->n);
            if (dist - md <= q->f10C) {
                unsigned char pri0 = 0;
                if (Allowed(q)) { V* tn = &tri->n; if (CheckPotentiallyStoppedByTaperingSpace(&q->v90, tn, D_00542D00))
                    pri0 = 1; }
                unsigned char pri = pri0;
                if ((!(nd < q->f104) || pri) && !(md <= 0.0f)) {
                    if (q->b110 && !pri)
                        return 0;
                    float t = Clamp((dist - q->fD4) / md, 0.0f, 1.0f);
                    VM move = MulM(q->v70, t);
                    V P = q->vE0.S4B(MulN(tri->n, q->fD4)) + move;
                    if (PointInTri(tri, &P)) {
                        q->b0 = 1;
                        q->v10 = tri->n;
                        q->v40 = P;
                        q->v70 = move;
                        q->UpdateMove();
                        hit = 1;
                    } else {
                        hit = cCollisionProbe_SphereSweptRay_TestFaceEdgesAndVertices(q, tri, 0);
                    }
                } else {
                    if (!q->b110)
                        return 0;
                    VE e = AddE(q->vE0, q->v70);
                    V ep = SubW2(e, tri->p[0]);
                    float dd = ep.Dot(tri->n);
                    V proj = e - tri->n.MulB(dd);
                    if (PointInTri(tri, &proj)) {
                        switch (q->b110) {
                        case 1: case 5: case 4: break;
                        default: return 0;
                        }
                        q->b0 = 1;
                        { V* tn = &tri->n; q->v10 = *tn; }
                        q->v40 = proj;
                        if (!(nd < 0.0f) && dd < q->fD4) {
                            q->v70 = proj.A4B(MulN(tri->n, q->fD4)) - q->vE0;
                            q->v90 = !q->v70.IsZero() ? q->v70.Unit() : V(0.0f, 0.0f, 0.0f, 0.0f);
                            q->UpdateMove();
                        }
                        hit = 1;
                    } else {
                        if (q->b110 != 4 && q->b110 != 5 && q->b110 != 2 && q->b110 != 3) return 0;
                        if (cCollisionProbe_SphereSweptRay_TestFaceEdgesAndVertices(q, tri, 0)) {
                            unsigned char pri20 = 0;
                            if (q->b118 && CheckPotentiallyStoppedByTaperingSpace(&q->v90, &q->v10, D_00542D00))
                                pri20 = 1;
                            unsigned char pri2 = pri20;
                            if (!pri2) {
                                V n2 = q->v10;
                                V s = q->Dest();
                                V w = e - s;
                                float d = w.DotV(n2);
                                VT t = SubT(e, n2 * d);
                                q->v70 = t.S3B(q->vE0);
                                if (q->b110 == 5 || q->b110 == 3) {
                                    if (Sign(q->v70.z) == Sign(n2.z)) {
                                        n2.z *= q->f114;
                                        if (n2.IsZero()) {
                                            n2 = q->v10;
                                        } else {
                                            n2.Normalize();
                                            t = e - n2 * w.DotV(n2);
                                            q->v70 = ZW3_2(t, q->vE0);
                                        }
                                    }
                                }
                                q->v90 = !q->v70.IsZero() ? q->v70.Unit0() : V(0.0f, 0.0f, 0.0f, 0.0f);
                                q->UpdateMove();
                            }
                            hit = 1;
                        }
                    }
                }
            }
        }
    }
    if (hit) {
        { V* s = &tri->v60; QQ(&q->v60, s); }
        D_00542D00->Push(&q->v10);
    }
    return hit;
}
static inline void merge_flush_func_003BDF60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BDF60 */
