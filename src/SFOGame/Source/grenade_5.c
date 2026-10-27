/*
 * SFOGame/Source/grenade: 6 files, 0025A860-0025AC50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0025A860 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_vector_pod_int_insert(PtrVec*, int*, int, int*);

/* push_back */
int func_0025A860(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}
static inline void merge_flush_func_0025A860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A860 */

/* merge_units: begin func_0025A880 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_A880;
static inline V4_A880 Sub_A880(V4_A880* a, V4_A880* b) {
    V4_A880 r; V4_A880* p = &r;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(p)
    }
    return *p;
}
#pragma opt_common_subs off
int ClipSegmentToZRange(V4_A880* a, V4_A880* b, float lo, float hi) {
    V4_A880 d = Sub_A880(b, a);
    float t;
    float z;
    z = a->z;
    if (z > hi) {
        if (b->z > hi) return 0;
        t = (hi - z) / d.z;
        a->x += d.x * t;
        a->y += d.y * t;
        a->z = hi;
    } else if (z < lo) {
        if (b->z < lo) return 0;
        t = (lo - z) / d.z;
        a->x += d.x * t;
        a->y += d.y * t;
        a->z = lo;
    }
    z = b->z;
    if (z > hi) {
        t = (hi - z) / d.z;
        b->x += d.x * t;
        b->y += d.y * t;
        b->z = hi;
    } else if (z < lo) {
        t = (lo - z) / d.z;
        b->x += d.x * t;
        b->y += d.y * t;
        b->z = lo;
    }
    return 1;
}
static inline void merge_flush_func_0025A880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025A880 */

/* merge_units: begin func_0025AA20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
/* SegmentIntersectsSphere: does the segment a-b pass within radius r of point c */
struct V;
// VU0 macro-mode vector op (COP2), not expressible in C
static inline void ScaleV(V* rp, const V* tp, float k) { __int128 t = 0; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(rp), "r"(tp), "f"(k) : "memory"); }
struct V {
    float x, y, z, w;
    V() {}
    // 128-bit lq/sq quadword copy idiom
    V(const V& o) { const __int128* s = (const __int128*)&o; __int128* d = (__int128*)this; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s)); *d = t; }
    // VU0 macro-mode vector op (COP2), not expressible in C
    V operator-(const V& o) const;
    V operator*(float k) const { V r; ScaleV(&r, this, k); return r; }
} __attribute__((aligned(16)));
static inline void SubV(V* d, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
inline V V::operator-(const V& o) const { V r; SubV(&r, this, &o); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float LenSq(const V* a) { int t; float r = 0.0f; __asm__("lqc2 $vf1, 0x0(%2); vaddw.x $vf3, $vf0, $vf0w; vmul.xyz $vf2, $vf1, $vf1; vmulax.x $ACC, $vf3, $vf2x; vmadday.x $ACC, $vf3, $vf2y; vmaddz.x $vf4, $vf3, $vf2z; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(a) : "memory"); return r; }
// VU0 macro-mode vector op (COP2), not expressible in C
static inline float Len(const V* a) { int rv0; float ret = 0.0f; asm { lqc2 vf1, 0x0(a); vmul.xyz vf2, vf1, vf1; vmulax.w ACC, vf0, vf2x; vmadday.w ACC, vf0, vf2y; vmaddz.w vf3, vf0, vf2z; vsqrt Q, vf3w; vwaitq; vaddq.x vf4, vf0, Q; qmfc2.ni rv0, vf4; mtc1 rv0, ret } return ret; }
// VU0 macro-mode dot product (COP2), not expressible in C
static inline float Dot3(const V* a, const V* b)
{
    int rv0;
    float ret = 0.0f;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 0x6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni rv0, vf4
        qfsrv rv0, rv0, rv0
        mtc1 rv0, ret
    }
    return ret;
}
extern "C" int SegmentIntersectsSphere(V* a, V* b, V* c, float r);
static inline float LenSq0(const V* a) { return LenSq(a); }
static inline float LenSqV(V v) { return LenSq0(&v); }
int SegmentIntersectsSphere(V* a, V* b, V* c, float r)
{
    
    V ac = *c - *a;
    float r2 = r * r;
    float d2 = LenSq(&ac);
    if (d2 < r2 || LenSqV(*c - *b) < r2) return 1;
    V ab = *b - *a;
    float len = Len(&ab);
    V dir = ab * (1.0f / len);
    float t = Dot3(&ac, &dir);
    if (t > 0.0f && t < len && d2 - t * t < r2) return 1;
    return 0;
}
static inline void merge_flush_func_0025AA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AA20 */

/* merge_units: begin func_0025AC00 */
#pragma push /* merge_units */
typedef struct ObjBC {
    char pad[0xBC];
    signed char value;
} ObjBC;

typedef struct Holder120 {
    char pad[0x120];
    ObjBC* obj;
} Holder120;

/* Returns the signed byte at obj+0xBC of the linked object, or 0. */
int cGrenade_GetDamageType(Holder120* h) {
    if (h->obj != 0) return h->obj->value;
    return 0;
}
static inline void merge_flush_func_0025AC00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AC00 */

/* merge_units: begin func_0025AC20 */
#pragma push /* merge_units */
#include "grenade_types.h"

extern char D_005716C0[];   /* default resource */

/* Vtable slot +0x88: resource for the projectile, or the default one. */
char* cGrenade_GetBBox(Grenade* self) {
    char* res = self->def->unk13C;

    if (res != 0) {
        return res + 992;
    }
    return D_005716C0;
}
static inline void merge_flush_func_0025AC20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AC20 */

/* merge_units: begin func_0025AC50 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct V_AC5 { float x, y, z, w; V_AC5() {} } __attribute__((aligned(16)));
struct R_AC5 {
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad[0x4C];
    unsigned char x50;
};
struct Q_AC5 { char pad[0x11C]; void* x11C; char pad2[0x1C]; void* x13C; };
struct O_AC5 {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d)
    virtual V_AC5 GetPos();
    char pad[0x34];
    int x38;
    char pad3C[0x14];
    R_AC5* x50;
    char pad54[0x90];
    unsigned char xE4;
    char padE5[0x3B];
    Q_AC5* x120;
};
extern "C" {
extern V_AC5 D_00535D40;
extern unsigned char D_00535D60;
extern unsigned char D_00535D61;
void gunList_GunRender(void* a, int b, void* c, int d);
void cGrenade_Render(O_AC5* o);
}
static inline unsigned char eq4_(V_AC5* a, V_AC5* b) {
    int k, f, r;
    asm {
        .set noreorder
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vsub.xyzw vf3, vf1, vf2
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
    return r;
}
#pragma push
#pragma bool off
#pragma opt_common_subs off

void cGrenade_Render(O_AC5* o)
{
    if (!o->xE4) {
        void* m; R_AC5* r; V_AC5 p = o->GetPos();
        if ((eq4_(&D_00535D40, (V_AC5*)&p) != 0) ^ 1) {
            { const V_AC5* s = &p; V_AC5* d = &D_00535D40; __int128 t; asm { .set reorder; lq t, 0(s) } asm { sq t, 0(d) } }
            D_00535D60 = 1; D_00535D61 = 1;
        }
        /* empty barrier keeps the then-block (b over the else) like retail */
        { Q_AC5* q = o->x120; m = q->x11C; if (m) { asm { .set reorder } } else m = q->x13C; }
        if (m) {
            r = o->x50;
            if (r->x50) r->Update();
            gunList_GunRender(m, o->x38, (void*)((int)r + 0x10), 0);
        }
    }
}
#pragma pop
static inline void merge_flush_func_0025AC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0025AC50 */
