/*
 * SFOGame/Source/humanCollision: 4 files, 001ED8D0-001EDCC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001ED8D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct BitsD8D0 {
    int w[1];
    BitsD8D0() {}
    BitsD8D0(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; }
    BitsD8D0& operator=(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] = o.w[i]; return *this; }
    BitsD8D0& operator&=(const BitsD8D0& o) { for (int i = 0; i < 1; i++) w[i] &= o.w[i]; return *this; }
};
extern "C" int cBitArray_19_opAnd(BitsD8D0* out, const BitsD8D0& a, const BitsD8D0& b) {
    BitsD8D0 t(a);
    t &= b;
    *out = t;
    return 0;
}
static inline void merge_flush_func_001ED8D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED8D0 */

/* merge_units: begin func_001ED910 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
    V(const V& o) { V* pd = this; const V* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } }
    V& operator=(const V& o) { V* pd = this; const V* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Edge { V a; V pad10; V b; V pad30; V n; };
static inline void Cross(V* r, const V* a, const V* b) {
    __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline void Sub(const V* a, V* r, const V* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(r)
    }
}
static inline void Normalize(V* a) { V* r = a;
    asm {
        lqc2 vf1, 0x0(a)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(r)
    }
}
static inline float Dot3(const V* a, const V* b) {
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
static inline void Neg(V* r, const V* a) {
    asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(r)
        .set noreorder
        nop
        .set reorder
    }
}
static inline V CrossV(const V& a, const V& b) { V r; Cross(&r, &a, &b); return r; }
static inline V SubV(const V& a, const V& b) { V r; Sub(&a, &r, &b); return r; }
static inline void SetNormalized(V* d, V v) { *d = v; Normalize(d); }
static inline float DotV(const V& a, V b) { return Dot3(&a, &b); }
#pragma opt_common_subs off
extern "C" V CalculateUnitEdgeOutwardXYNormal(Edge* e)
{
    V n; const V& en = e->n; V up(0.0f, 0.0f, 1.0f, 0.0f);
    SetNormalized(&n, CrossV(en, up));
    if (DotV(n, SubV(e->b, e->a)) > 0.0f) Neg(&n, &n);
    return n;
}
static inline void merge_flush_func_001ED910(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001ED910 */

/* merge_units: begin func_001EDA40 */
#pragma push /* merge_units */
#pragma cplusplus on

/* cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes: build the ledge-probe mask for a collision query mask. A rule table is
 * built on first use (each element registered for destruction); every rule whose required
 * bits are all set in the query and whose forbidden bits are all clear adds its bit. */

struct Mask { int w[1]; };
struct Rule { signed char bit; Mask need; Mask forbid; };

extern "C" {
extern signed char D_004F5310;   /* rule table built */
extern Rule D_004A0380[];        /* rule table, terminated by bit -1 */
extern Rule D_004A038C;
extern Rule D_004A0398;
extern Rule D_004A03A4;
extern signed char D_0048A978;
extern signed char D_0048A980;
extern signed char D_0048A988;
extern char D_004F5318[];        /* destruction records */
extern char D_004F5328[];
extern char D_004F5338[];
extern char D_004F5348[];

void __register_global_object(void* obj, void* dtor, void* rec);
void* func_001EDCC0(void* self, short flag);
void* cBitArray_5_dtor(void* self, short flag);
int cBitArray_5_opAnd(Mask* out, Mask* a, Mask* b);
int cBitArray_5_opCompl(Mask* out, Mask* a);
int cBitArray_5_opEq(Mask* a, Mask* b);
int cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes(Mask* out, void* self, Mask* q);
}

/* the element initialisers write through the element's this pointer; the int round trip keeps
 * MW from folding the constant address into each store (retail stores through a0) */
static inline Rule* This(Rule* r) { return (Rule*)(int)r; }
static inline Mask* MaskRef(Mask* m) { return (Mask*)(int)m; }

static inline Mask* MaskBit(Mask* t, int set)
{
    t->w[0] = 0;
    t->w[0] |= set;
    return MaskRef(t);
}

static inline void RuleInit(Rule* r, signed char bit, Mask* f)
{
    int i;
    r->bit = bit;
    r->need.w[0] = 0;
    for (i = 0; i < 1; i++) r->forbid.w[i] = f->w[i];
}

static inline bool MaskEq(Mask* a, Mask* b)
{
    int i;
    for (i = 0; i < 1; i++) {
        if (a->w[i] != b->w[i]) return false;
    }
    return true;
}

int cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_TranslateTestResultsToSubtypes(Mask* out, void* self, Mask* q)
{
    Mask res;
    Rule* e;
    int i;
    if (!D_004F5310) {
        {
            Mask t;
            Mask* f = MaskBit(&t, 0x10);
            Rule* r;
            D_004A0380[0].bit = D_0048A978;
            r = This(D_004A0380);
            r->need.w[0] = 0;
            for (i = 0; i < 1; i++) r->forbid.w[i] = f->w[i];
        }
        __register_global_object(D_004A0380, func_001EDCC0, D_004F5318);
        { Mask t; RuleInit(This(&D_004A038C), D_0048A980, MaskBit(&t, 0x4)); }
        __register_global_object(This(&D_004A038C), func_001EDCC0, D_004F5328);
        { Mask t; RuleInit(This(&D_004A0398), D_0048A988, MaskBit(&t, 0x2)); }
        __register_global_object(This(&D_004A0398), func_001EDCC0, D_004F5338);
        {
            Rule* r = This(&D_004A03A4);
            r->bit = -1;
            r->need.w[0] = 0;
            r->forbid.w[0] = 0;
        }
        __register_global_object(This(&D_004A03A4), func_001EDCC0, D_004F5348);
        D_004F5310 = 1;
    }
    res.w[0] = 0;
    for (e = D_004A0380; e->bit != -1; e++) {
        Mask t;
        cBitArray_5_opAnd(&t, q, &e->need);
        if (MaskEq(&t, &e->need)) {
            Mask n;
            Mask u;
            unsigned char ok;
            cBitArray_5_opCompl(&n, q);
            cBitArray_5_opAnd(&u, &n, &e->forbid);
            ok = cBitArray_5_opEq(&u, &e->forbid);
            cBitArray_5_dtor(&u, -1);
            cBitArray_5_dtor(&n, -1);
            if (ok) res.w[e->bit / 32] |= 1 << (e->bit & 31);
        }
    }
    for (i = 0; i < 1; i++) out->w[i] = res.w[i];
    return 0;
}
static inline void merge_flush_func_001EDA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EDA40 */

/* merge_units: begin func_001EDCC0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "trivial_dtor.h"

/* Deleting destructor with nothing to destroy. */
DEFINE_TRIVIAL_DTOR(func_001EDCC0)
static inline void merge_flush_func_001EDCC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EDCC0 */
