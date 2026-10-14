/*
 * main/human: range (3 files, 001B28E0-001B2A00)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"

/* merge_units: begin func_001B28E0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
union V4_29A0 { float f[4]; __int128 q; };
struct E_29A0 { V4_29A0 p; V4_29A0 q; E_29A0() {} };
struct M_29A0 { E_29A0 e[2]; };
extern "C" M_29A0* func_001B29A0(M_29A0* m, const V4_29A0* a, const V4_29A0* b, const V4_29A0* c, const V4_29A0* d); /* gsynth: defined below */
#pragma pop
typedef struct { float x, y, z, w; } B8V_1B28E0;
typedef struct { char pad[0x40]; float s; float inv; } B8S_1B28E0;
extern void Vec4_Scale(B8V_1B28E0* out, B8V_1B28E0* in, float s);
#if 0 /* merge_units */
extern void func_001B29A0(B8S_1B28E0* p, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d);
#endif /* merge_units */
#define func_001B29A0(a0, a1, a2, a3, a4) ((void)func_001B29A0((void *)(a0), (void *)(a1), (void *)(a2), (void *)(a3), (void *)(a4))) /* merge_units */

void func_001B28E0(void* pv, int a, B8V_1B28E0* b, int c, B8V_1B28E0* d) {
    B8V_1B28E0 v1;
    B8V_1B28E0 v2;
    float s;
    float inv;
    B8S_1B28E0* p = (B8S_1B28E0*)pv;
    if (p) {
        s = ((B8S_1B28E0*)pv)->s;
        Vec4_Scale(&v1, b, s);
        Vec4_Scale(&v2, d, s);
        func_001B29A0(p, a, &v1, c, &v2);
        p->s = s;
        inv = (s != 0.0f) ? 1.0f / s : 0.0f;
        p->inv = inv;
    }
}
#undef func_001B29A0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B28E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B28E0 */

/* merge_units: begin func_001B29A0 */
#pragma push /* merge_units */
#pragma cplusplus on
inline void* operator new(unsigned int, void* p) { return p; }



/* Two-element array of quad pairs built from four vectors (by pointer).
   The quad copies keep retail's unfolded addresses with the peephole off. */
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" M_29A0* func_001B29A0(M_29A0* m, const V4_29A0* a, const V4_29A0* b, const V4_29A0* c, const V4_29A0* d)
{
    { E_29A0* e = m->e; E_29A0* end = m->e + 2; do { new (e) E_29A0; } while (++e != end); }
    E_29A0* e1 = &m->e[1];
    V4_29A0* q0 = &m->e[0].q;
    V4_29A0* p1 = &m->e[1].p;
    V4_29A0* q1 = &e1->q;
    m->e[0].p.q = a->q;
    q0->q = b->q;
    p1->q = c->q;
    q1->q = d->q;

    return m;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B29A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B29A0 */

/* merge_units: begin func_001B2A00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V4_1B2A00 { __int128 q; V4_1B2A00() {} };
extern "C" {
void func_0017CC60(void* p, int f);
void* func_00139BC0(unsigned int size, void* p);
void Curve_SetTangents(void* c, V4_1B2A00* a, V4_1B2A00* b, V4_1B2A00* d, V4_1B2A00* e, float t);
}
class VC_1B2A00 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual V4_1B2A00 s3();
};
struct Obj_1B2A00 : public VC_1B2A00 {
    char p0[0x1C];
    V4_1B2A00 a;
    V4_1B2A00 b;
    V4_1B2A00 c;
    char p1[0x10];
    char curve[0x40];
    float t;
};
static inline V4_1B2A00 Get_(VC_1B2A00* v) { return v->s3(); }
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void VecCurve_Reset(Obj_1B2A00* o, const V4_1B2A00* a)
{
    V4_1B2A00* d = &o->a;
    V4Copy(d, a);
    {
        V4_1B2A00 r = Get_(o);
        func_0017CC60(o->curve, -1);
        void* cv = func_00139BC0(0x50, o->curve);
        if (cv) Curve_SetTangents(cv, &o->a, &o->b, &o->c, &r, o->t);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B2A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B2A00 */
