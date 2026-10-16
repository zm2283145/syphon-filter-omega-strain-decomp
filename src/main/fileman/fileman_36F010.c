/*
 * main/fileman: 6 files, 0036F010-0036F210
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0036F010 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void func_0036F010(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf4, 0x0(c)
        lqc2 vf5, 0x10(c)
        lqc2 vf6, 0x20(c)
        lqc2 vf7, 0x30(c)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(a)
        sqc2 vf13, 0x10(a)
        sqc2 vf14, 0x20(a)
        sqc2 vf15, 0x30(a)
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036F010 */

/* merge_units: begin func_0036F090 */
#pragma push /* merge_units */
void func_0036F090(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf4, 0x0(c)
        lqc2 vf5, 0x10(c)
        lqc2 vf6, 0x20(c)
        lqc2 vf7, 0x30(c)
        lqc2 vf8, 0x0(b)
        lqc2 vf9, 0x10(b)
        lqc2 vf10, 0x20(b)
        lqc2 vf11, 0x30(b)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        vmulax.xyzw ACC, vf4, vf9x
        vmadday.xyzw ACC, vf5, vf9y
        vmaddaz.xyzw ACC, vf6, vf9z
        vmaddw.xyzw vf13, vf7, vf9w
        vmulax.xyzw ACC, vf4, vf10x
        vmadday.xyzw ACC, vf5, vf10y
        vmaddaz.xyzw ACC, vf6, vf10z
        vmaddw.xyzw vf14, vf7, vf10w
        vmulax.xyzw ACC, vf4, vf11x
        vmadday.xyzw ACC, vf5, vf11y
        vmaddaz.xyzw ACC, vf6, vf11z
        vmaddw.xyzw vf15, vf7, vf11w
        sqc2 vf12, 0x0(a)
        sqc2 vf13, 0x10(a)
        sqc2 vf14, 0x20(a)
        sqc2 vf15, 0x30(a)
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036F090 */

/* merge_units: begin func_0036F110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class T36F110 {
public:
    VPAD16(a) VPAD1(b)
    virtual void f4C(int);
    char pad[0x9C]; int aA0;
};
class A36F110 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d)
    virtual T36F110* f44();
};
extern "C" void func_0036F110(int key, A36F110* a, int arg);
void func_0036F110(int key, A36F110* a, int arg)
{
    T36F110* t = a ? a->f44() : 0;
    if (t && t->aA0 == key) t->f4C(arg);
}
#pragma pop /* merge_units */
/* merge_units: end func_0036F110 */

/* merge_units: begin func_0036F190 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


int func_0036F190(void) {
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0036F190 */

/* merge_units: begin func_0036F1A0 */
#pragma push /* merge_units */
#pragma cplusplus on
class D6XObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual D6XObj* getNode();
    virtual void attach(void* parent, int flags);
};
extern "C" void Xform_AddChild(void* self, D6XObj* child, int flags)
{
    D6XObj* n = child ? child->getNode() : 0;
    if (n) {
        n->attach(self, flags);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036F1A0 */

/* merge_units: begin func_0036F210 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
static inline void G1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct V { float x, y, z, w; V& operator=(const V& o) { void* xx = this; G1(this, &o); return *this; } } __attribute__((aligned(16)));
struct M { V r[4];
    M() {}
    M(const M& o) { void* d = this; __int128 qa, qb; __asm__ volatile("lq %1, 0x0(%2); lq %0, 0x10(%2); sq %1, 0x0(%3); lq %1, 0x20(%2); sq %0, 0x10(%3); lq %0, 0x30(%2); sq %1, 0x20(%3); sq %0, 0x30(%3)" : "=&r"(qb), "=&r"(qa) : "r"(&o), "r"(d) : "memory"); }
};
static inline void G4(void* d, void* s) { __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
static inline void G1(void* d, void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void GMV(void* o, void* m, void* v) { __asm__ volatile("lqc2 vf8, 0x0(%2); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory"); }
typedef struct { int p; } It;
extern "C" {
void func_001CF100(It* it, void* c);
void func_001CF0E0(It* it, void* c);
int func_001CEF10(It* a, It* b);
void** func_001CF0D0(It* it);
void func_001CEF50(void* p);
void func_001CEF30(It* it);
void PtrVector_Resize(void* v, int n, int* fill);
M* Mtx_Transpose3x3(M* m);
int Mtx_IsTranslationZero(M* m);
V* func_00133EC0(M* m);
void Vec4_Assign(V* d, V* s);
V* Vec3_Negate(V* a);
V* Mtx_TransformByTranspose(V* a, M* b);
void Mtx_SetTranslation(M* m, V* v);
}
struct XVec { int cap; int size; struct Xform** data; };
struct Xform {
    virtual void v0(); virtual void SetWorld(M* m); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void Update();
    char pad4[0xC];
    M world;
    unsigned char dirty;
    char pad51[0x3F];
    V pos;
    Xform* parent;
    M GetWorld() { if (dirty) Update(); const M& w = world; return w; }
    XVec kids;
};
extern "C" void Xform_Detach(Xform* x, int keep)
{
    Xform* p = x->parent;
    Xform* self = x;
    int fill;
    It b;
    It e;
    if (p) {
        M m = self->GetWorld();
        { void* xx = &p->kids.data; }
        self->parent = 0;
        {
            int i;
            int last = p->kids.size - 1;
            for (i = 0; i <= last; i++) {
                Xform** e = &p->kids.data[i];
                if (*e == self) {
                    *e = p->kids.data[last];
                    last--;
                }
            }
            fill = 0;
            PtrVector_Resize(&p->kids, last + 1, &fill);
        }
        if (keep) {
            self->SetWorld(&m);
        } else if (!self->dirty) {
            It* pe;
            self->dirty = 1;
            func_001CF100(&b, &self->kids);
            func_001CF0E0(&e, &self->kids);
            pe = &e;
            while (func_001CEF10(&b, pe)) {
                func_001CEF50(*func_001CF0D0(&b));
                func_001CEF30(&b);
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0036F210 */
