/*
 * Libs/SFOLib/Source/particle: 8 files, 0039EEF0-0039FF30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0039EEF0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void cVector_VU0Cross(V4* a, V4* b, V4* c) {
    asm {
        lqc2 vf1, 0x0(b)
        lqc2 vf2, 0x0(c)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(a)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039EEF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039EEF0 */

/* merge_units: begin func_0039EF10 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Info9EF10 {
    char pad[0x8F4];
    int busy;                   /* 0x8F4 */
};

class Obj9EF10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Info9EF10* GetInfo();   /* vtable +0x14 */
    char pad04[0x60 - 0x04];
    float delay;                /* 0x60 */
    float last;                 /* 0x64 */
    char pad68[0x74 - 0x68];
    int owner;                  /* 0x74 */
    char pad78[0x16C - 0x78];
    unsigned char ready;        /* 0x16C */
};

extern "C" unsigned char cParticleShatter_Done(Obj9EF10* self, float now)
{
    unsigned char r;
    if (self->owner == 0) r = self->ready;
    else r = !(self->GetInfo()->busy != 0) && now - self->last > self->delay;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0039EF10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0039EF10 */

/* merge_units: begin func_0039EF90 */
#pragma push /* merge_units */
#pragma cplusplus on

static inline void* CopyQ1(void* d, const void* s) { __int128 q; asm { .set reorder; lq q, 0x0(s); sq q, 0x0(d) } return d; }
struct V4_0039EF90 {
    float x, y, z, w;
    V4_0039EF90() {}
    V4_0039EF90(const V4_0039EF90& x, const V4_0039EF90& y, float) { const V4_0039EF90* pb = &y; const V4_0039EF90* a = &x; asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(this)
        } }
    V4_0039EF90(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V4_0039EF90(const V4_0039EF90& source) { void* xx = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, unsigned char) { const V4_0039EF90* src = &source; void* xx = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(src) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, unsigned short) { void* xx = this; const V4_0039EF90* src = &source; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(src) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, unsigned long) { const V4_0039EF90* src = &source; V4_0039EF90* t = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(t), "r"(src) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, signed char) { V4_0039EF90* t = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(t), "r"(&source) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, int) { __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, short) { V4_0039EF90* t = this; const V4_0039EF90* src = &source; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(t), "r"(src) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, char) { const V4_0039EF90* src = &source; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(src) : "memory"); }
    V4_0039EF90(const V4_0039EF90& source, long) { void* xx = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    V4_0039EF90& operator=(const V4_0039EF90& source) { void* xx = this; __int128 reg; V4_0039EF90& refThis = *this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    V4_0039EF90 operator-(const V4_0039EF90& b) const {
        V4_0039EF90 r; V4_0039EF90* o = &r; const V4_0039EF90* a = this; const V4_0039EF90* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(o)
        }
        return r;
    }
    V4_0039EF90 operator-() const {
        V4_0039EF90 r; V4_0039EF90* o = &r; const V4_0039EF90* a = this;
        asm {
            lqc2 vf1, 0x0(a)
            vmulax.xyzw ACC, vf0, vf0x
            vmsubw.xyzw vf1, vf1, vf0w
            sqc2 vf1, 0x0(o)
        }
        return r;
    }
    V4_0039EF90& operator+=(const V4_0039EF90& b) {
        V4_0039EF90* d = this; const V4_0039EF90* a = this; const V4_0039EF90* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
    V4_0039EF90& operator*=(float s) {
        V4_0039EF90* a = this; int t;
        asm {
            .set noreorder
            lqc2 vf1, 0x0(a)
            mfc1 t, s
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0x0(a)
            .set reorder
        }
        return *this;
    }
    V4_0039EF90& Normalize() {
        V4_0039EF90* d = this; V4_0039EF90* a = this;
        asm {
            lqc2 vf1, 0x0(a)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vrsqrt Q, vf0w, vf3w
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0x0(a)
        }
        return *this;
    }
    float LengthSq() const {
        int t; float r = 0.0f;
        asm {
            lqc2 vf1, 0x0(this)
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
    float Dot(const V4_0039EF90& b) const {
        const V4_0039EF90* a = this; const V4_0039EF90* pb = &b; int t; float r = 0.0f;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
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
    V4_0039EF90 Cross(const V4_0039EF90& b) const {
        V4_0039EF90 r; V4_0039EF90* o = &r; const V4_0039EF90* a = this; const V4_0039EF90* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vopmula.xyz ACC, vf1, vf2
            vopmsub.xyz vf3, vf2, vf1
            vsubw.w vf3, vf0, vf0w
            sqc2 vf3, 0x0(o)
        }
        return r;
    }
    V4_0039EF90 GetNormalized() const { return V4_0039EF90(*this).Normalize(); }
    V4_0039EF90 SubM(const V4_0039EF90& b, int) const {
        V4_0039EF90 r(*this, b, 0.0f); return V4_0039EF90(r, (long)0);
    }
    V4_0039EF90 SubK(const V4_0039EF90& b) const {
        V4_0039EF90 r; V4_0039EF90* o = &r; const V4_0039EF90* a = this; const V4_0039EF90* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(o)
        }
        return V4_0039EF90(r);
    }
    V4_0039EF90 SubN(const V4_0039EF90& b) const {
        V4_0039EF90 r; V4_0039EF90* o = &r; const V4_0039EF90* a = this; const V4_0039EF90* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(o)
        }
        return V4_0039EF90(r, 0);
    }
    void SetXYZ(const V4_0039EF90& v) { float s = w; *this = v; w = s; }
} __attribute__((aligned(16)));

struct M4 {
    V4_0039EF90 r[4];
    void Apply(V4_0039EF90* o, const V4_0039EF90* v) const {
        const M4* m = this; V4_0039EF90* po = o; const V4_0039EF90* pv = v;
        asm {
            lqc2 vf8, 0x0(pv)
            lqc2 vf4, 0x0(m)
            lqc2 vf5, 0x10(m)
            lqc2 vf6, 0x20(m)
            lqc2 vf7, 0x30(m)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(po)
        }
    }
};

class Xform {
public:
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void Update();
    M4 mat;
    unsigned char needUpdate;
};
struct Mesh { char pad0[0x50]; Xform* xf; };
struct ShapeInfo { char pad[0x1C]; int type; };
struct Shape { Mesh* mesh; ShapeInfo** info; };
struct Box { V4_0039EF90 a; V4_0039EF90 b; };
struct Bnd { V4_0039EF90 a; V4_0039EF90 b; V4_0039EF90 c; V4_0039EF90 d; V4_0039EF90& B() { return b; } };
class Obj {
public:
    virtual void v8();
    virtual void vC();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual Box* GetBox();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual Shape* GetShape();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual V4_0039EF90 GetPos();
    virtual Bnd GetBounds();
};
struct Info2 { char pad[0x14]; unsigned int count; };
struct Ref { char pad[4]; Info2* info; short* ids; int At(unsigned int i) { if (i < info->count) return ids[i]; return -1; } bool Has() { return info->count != 0; } };
struct Src { char pad[0x68]; Ref* ref; };
struct Owner { char pad[0x74]; int id; };

struct Panel {
    char pad0[0xB0];
    V4_0039EF90 normal;
    char padC0[0xE0 - 0xC0];
    V4_0039EF90 edge;
    V4_0039EF90 dir;
    V4_0039EF90 p0;
    V4_0039EF90 p1;
    Owner* owner;
    char pad124[0x130 - 0x124];
    V4_0039EF90 c0;
    V4_0039EF90 c1;
    char pad150[0x154 - 0x150];
    float f154;
    char pad158[0x170 - 0x158];
    int id;
};

extern "C" int cCollisionModelMaster_GetData(int);
extern "C" V4_0039EF90* cCollisionModel_Data_GetVertex(int, int);
extern "C" void cTexMan_AddTextureReference(int, int);
extern int g_TextureMgr;
static inline V4_0039EF90 GetPt(int info, int i) { return *cCollisionModel_Data_GetVertex(cCollisionModelMaster_GetData(info), i); }
#pragma inline_depth(16)




static inline V4_0039EF90 CrossF(V4_0039EF90 a, V4_0039EF90 b) { return a.Cross(b); }
static inline V4_0039EF90 Sub(const V4_0039EF90& x, const V4_0039EF90& y) { return x.SubK(y); }
static inline V4_0039EF90 Sub2(const V4_0039EF90& x, const V4_0039EF90& y) { return Sub(x, y); }
static inline V4_0039EF90 Sub3(const V4_0039EF90& x, const V4_0039EF90& y) { return Sub2(x, y); }
static inline V4_0039EF90 Sub4(const V4_0039EF90& x, const V4_0039EF90& y) { return Sub3(x, y); }
static inline V4_0039EF90 Neg(const V4_0039EF90& x) { return -x; }
static inline V4_0039EF90 Neg2(const V4_0039EF90& x) { return Neg(x); }
static inline V4_0039EF90 CrossF2(V4_0039EF90 a, V4_0039EF90 b) { return CrossF(a, b); }
static inline V4_0039EF90 CrossR(const V4_0039EF90& a, const V4_0039EF90& b) { return a.Cross(b); }

static inline V4_0039EF90 Neg3(const V4_0039EF90& x) { return Neg2(x); }
static inline V4_0039EF90 CrossF3(V4_0039EF90 a, V4_0039EF90 b) { return CrossF2(a, b); }
static inline V4_0039EF90 CrossR2(const V4_0039EF90& a, const V4_0039EF90& b) { return CrossR(a, b); }
static inline V4_0039EF90 CrossR3(const V4_0039EF90& a, const V4_0039EF90& b) { return CrossR2(a, b); }
static inline V4_0039EF90 CrossR4(const V4_0039EF90& a, const V4_0039EF90& b) { return CrossR3(a, b); }
static inline V4_0039EF90 SubD(const V4_0039EF90& x, const V4_0039EF90& y, V4_0039EF90 r = V4_0039EF90()) { V4_0039EF90* o = &r; const V4_0039EF90* a = &x; const V4_0039EF90* pb = &y; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) } return r; }
static inline V4_0039EF90 SubD2(const V4_0039EF90& x, const V4_0039EF90& y) { return SubD(x, y); }
static inline V4_0039EF90 NegD(const V4_0039EF90& x, V4_0039EF90 r = V4_0039EF90()) { V4_0039EF90* o = &r; const V4_0039EF90* a = &x; asm { lqc2 vf1, 0x0(a); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(o) } V4_0039EF90& rr = r; return rr; }
static inline V4_0039EF90 CrossD(const V4_0039EF90& x, const V4_0039EF90& y, V4_0039EF90 r = V4_0039EF90()) { const V4_0039EF90* a = &x; const V4_0039EF90* pb = &y; V4_0039EF90* o = &r; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(o) } V4_0039EF90& rr = r; return rr; }
static inline V4_0039EF90 CrossD2(const V4_0039EF90& x, const V4_0039EF90& y) { return CrossD(x, y); }extern "C" void cParticleShatter_SetShatterData(Panel* p, Obj* a, Src* src, Obj* b, V4_0039EF90 v0, V4_0039EF90 v1, float f)
{
    V4_0039EF90 normal;
    p->p0 = v0;
    p->p1 = v1;
    p->f154 = f;
    p->dir = a->GetPos().SubN(b->GetPos()).GetNormalized();
    Shape* sh = a->GetShape();
    if (sh != 0 && sh->mesh->xf != 0 && (*sh->info)->type == 4) {
        Shape* s = a->GetShape();
        Xform* xf = s->mesh->xf;
        V4_0039EF90 pts[4];
        V4_0039EF90 sum(0.0f, 0.0f, 0.0f, 0.0f);
        int i;
        for (i = 0; i < 4; i++) {
            pts[i] = GetPt((int)s->info, i);
            if (xf->needUpdate) {
                xf->Update();
            }
            xf->mat.Apply(&pts[i], &pts[i]);
            sum += pts[i];
        }
        sum *= 0.25f;
        int best = 0;
        int j;
        for (j = 1; j < 4; j++) {
            if (pts[j].z < sum.z && pts[j].x + pts[j].y < sum.x + sum.y) {
                best = j;
            }
        }
        p->c0 = pts[best];
        int second;
        int far = 3 - best;
        float maxd = 0.0f;
        int k;
        for (k = 0; k < 4; k++) {
            float l = p->c0.SubM(pts[k], 0).LengthSq();
            if (l > maxd) {
                second = far;
                maxd = l;
                far = k;
            }
        }
        V4_0039EF90 c2 = pts[second];
        p->c1 = pts[far];
        p->edge.SetXYZ(p->c1 - p->c0);
        normal = CrossR3(Sub(p->c0, c2), p->c1 - c2);
        normal.Normalize();
        p->c0 = p->c0 - sum;
        p->c1 = SubD2(p->c1, sum);
    } else {
        normal = a->GetBounds().B();
        p->c1 = a->GetBox()->b;
        p->c0 = a->GetBox()->a;
        p->edge.SetXYZ(p->c1 - p->c0);
    }
    if (normal.Dot(p->dir) > 0.0f) {
        normal = -normal;
    }
    p->normal = normal;
    if (src != 0) {
        Ref* r = src->ref;
        p->id = r->At(0);
        if (p->id >= 0) {
            cTexMan_AddTextureReference(g_TextureMgr, p->id);
        }
    } else {
        p->id = p->owner->id;
        if (p->id >= 0) {
            cTexMan_AddTextureReference(g_TextureMgr, p->id);
        }
    }
}
static inline void merge_flush_func_0039EF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039EF90 */

/* merge_units: begin func_0039F740 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int cMemMan_Deallocate(...);                         
int cTexMan_RemoveTexture(...);                       
int operator_delete(...);                          
extern char D_004BC5D0;
extern char D_004DFAD8;
extern "C" void cParticleShatter_Render();
extern "C" void cParticleShatter_NextFrame();
#if 0 /* merge_units */
extern "C" void cParticleShatter_Done();
#endif /* merge_units */

extern "C" void cParticleBase_GetRenderMatrix();
extern "C" void cParticleShatter_Definition();
extern void * const D_004DFB10[];
extern char D_004DFB50;
extern unsigned char g_ProfileLockEnabled;
}
#pragma opt_common_subs off
extern "C" char * cParticleShatter_dtor(char * arg0, long long arg1) {
    int temp_a1;
    int temp_s2;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004DFB10));
        temp_a1 = F_(arg0, 0x170, int);
        if (temp_a1 >= 0) {
            cTexMan_RemoveTexture(g_TextureMgr, temp_a1, 1);
        }
        temp_s2 = F_(arg0, 0x124, int);
        if (temp_s2 != 0) {
            {
                AllocGuard g;
            cMemMan_Deallocate(0, temp_s2, &D_004BC5D0, 0x99B);
            }
            F_(arg0, 0x124, int) = 0;
        }
        if (arg0 != NULL) {
            F_(arg0, 0x0, int) = (int)(&D_004DFB50);
            if (arg0 != NULL) {
                F_(arg0, 0x0, int) = (int)(&D_004DFAD8);
            }
        }
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DFB10[8] = { (void*)0x0, (void*)0x0, (void*)cParticleShatter_dtor, (void*)cParticleShatter_Render, (void*)cParticleShatter_NextFrame, (void*)cParticleShatter_Definition, (void*)cParticleShatter_Done, (void*)cParticleBase_GetRenderMatrix };
static inline void merge_flush_func_0039F740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039F740 */

/* merge_units: begin func_0039F860 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

struct W { int x, y, z, w; W() {} W(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; } W& operator=(const W& o) { x = o.x; y = o.y; z = o.z; w = o.w; return *this; } };

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    void Set2(const V& o) { __int128 t; __asm__("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o)); }
    void Set(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));

struct M {
    V r0, r1, r2, r3;
    M() {}
    void SetB(const M& o) { __int128 qa; __int128 qb; const M* s = &o; M* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    void SetX(const M& o) { void* xx = this; __int128 qa; __int128 qb; const M* s = &o; M* d = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
    M& TrP() { M* p = this; float f; f = p->r0.y; p->r0.y = p->r1.x; p->r1.x = f; f = p->r0.z; p->r0.z = p->r2.x; p->r2.x = f; f = p->r1.z; p->r1.z = p->r2.y; p->r2.y = f; return *p; }
    M& TrT() { float f; f = r0.y; r0.y = r1.x; r1.x = f; f = r0.z; r0.z = r2.x; r2.x = f; f = r1.z; r1.z = r2.y; r2.y = f; return *this; }
    M& operator=(const M& o) { void* xx = this; __int128 qa; __int128 qb; M* d = this; const M* s = &o; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); return *this; }
    M(const M& o) { __int128 qa; __int128 qb; const M* s = &o; M* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));

/* VU0 4x4 matrix multiply, in place into d */
static inline void MulM(M* d, const M* a)
{
    __asm__ volatile(
        "lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1)\n"
        "lqc2 $vf8, 0x0(%0); lqc2 $vf9, 0x10(%0); lqc2 $vf10, 0x20(%0); lqc2 $vf11, 0x30(%0)\n"
        "vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w\n"
        "vmulax.xyzw $ACC, $vf4, $vf9x; vmadday.xyzw $ACC, $vf5, $vf9y; vmaddaz.xyzw $ACC, $vf6, $vf9z; vmaddw.xyzw $vf13, $vf7, $vf9w\n"
        "vmulax.xyzw $ACC, $vf4, $vf10x; vmadday.xyzw $ACC, $vf5, $vf10y; vmaddaz.xyzw $ACC, $vf6, $vf10z; vmaddw.xyzw $vf14, $vf7, $vf10w\n"
        "vmulax.xyzw $ACC, $vf4, $vf11x; vmadday.xyzw $ACC, $vf5, $vf11y; vmaddaz.xyzw $ACC, $vf6, $vf11z; vmaddw.xyzw $vf15, $vf7, $vf11w\n"
        "sqc2 $vf12, 0x0(%0); sqc2 $vf13, 0x10(%0); sqc2 $vf14, 0x20(%0); sqc2 $vf15, 0x30(%0)"
        : : "r"(d), "r"(a) : "memory");
}
static inline M& MulInto(M* t, const M* a) { M* p = t; MulM(p, a); return *p; }

/* VU0 3x3 rotate of a vector by a matrix */
static inline void Rot(V* o, const V* v, const M* m)
{
    __asm__ volatile("lqc2 $vf8, 0x0(%2); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); vmulax.xyz $ACC, $vf4, $vf8x; vmadday.xyz $ACC, $vf5, $vf8y; vmaddz.xyz $vf8, $vf6, $vf8z; sqc2 $vf8, 0x0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory");
}

struct Def {
    char pad0[0x14];
    float x14;
    char pad18[0x64 - 0x18];
    unsigned char x64;
    char pad65[0x8B0 - 0x65];
    M m;               /* 0x8B0 */
    char pad8F0[0x9B0 - 0x8F0];
    float f9B0, f9B4, f9B8, f9BC;
};
struct Obj_0039F860 {
    void* vt;
    char pad4[0x8];
    unsigned char xC;
    char padD[3];
    M m;               /* 0x10 */
    V v50;             /* 0x50 */
    float x60;
    char pad64[0x90 - 0x64];
    V a[6];            /* 0x90 */
    V bullet;          /* 0xF0 */
    char pad100[0x20];
    Def* def;          /* 0x120 */
    int x124;
    char pad128[0x16C - 0x128];
    unsigned char x16C;
    char pad16D[3];
    int x170;
};
#define V40(s) (*(V*)((char*)(s) + 0x40))
#define V10(s) (*(V*)((char*)(s) + 0x10))

extern "C" Obj_0039F860* cParticleBase_ctor(Obj_0039F860* self, Obj_0039F860* parent, Def* def, float f);
extern W D_00538350;
extern V D_004BC550;

static inline void Compose3(Obj_0039F860* self, Obj_0039F860* parent, M* m, M& r)
{
    M* pm;
    M t = *m;
    const M* pa = &parent->m;
    M& rr = (r = MulInto(&t, pa));
    void* xx = &self->m;
    pm = &self->m;
    *pm = rr;
}
static inline void Compose2(Obj_0039F860* self, Obj_0039F860* parent, M* m, M& r) { Compose3(self, parent, m, r); }
static inline void Compose(Obj_0039F860* self, Obj_0039F860* parent, M* m, M& r) { Compose2(self, parent, m, r); }

static inline M& Transpose(M& a)
{
    M* p = &a;
    float f;
    f = p->r0.y; p->r0.y = p->r1.x; p->r1.x = f;
    f = p->r0.z; p->r0.z = p->r2.x; p->r2.x = f;
    f = p->r1.z; p->r1.z = p->r2.y; p->r2.y = f;
    return *p;
}
static inline V& RotBy(M b, V& v) { Rot(&v, &v, &b); return v; }
static inline M Transposed(const M* m) { M a; a.SetX(*m); return Transpose(a); }
static inline V& RotT3(V& v, const M* m) { return RotBy(Transposed(m), v); }

extern "C" Obj_0039F860* cParticleShatter_ctor(Obj_0039F860* self, Obj_0039F860* parent, Def* def, M* m, float st)
{
    M r;
    W c;

    cParticleBase_ctor(self, parent, def, st);
    self->vt = (void*)D_004DFB10;
    {
        V* q = self->a;
        V* e = self->a + 6;
        do { q++; } while (q != e);
    }
    self->def = def;
    self->xC = 1;
    if (!parent) {
        self->m = def->m;
        self->a[2] = V10(m);
    } else {
        Compose3(self, parent, m, r);
        self->a[2].Set(parent->a[2]);
        float w = self->a[5].w; self->a[5].Set(parent->a[5]); self->a[5].w = w;
    }
    self->a[0] = V40(self);
    self->a[0].w = def->x14;
    c = D_00538350;
    *(W*)&self->a[1] = c;
    self->a[4].Set(D_004BC550);
    self->a[4] = RotT3(self->a[4], m);
    self->a[4].w = (float)def->x64;
    self->x60 = def->f9BC + (def->f9B8 + (def->f9B0 + def->f9B4));
    self->x170 = -1;
    self->x124 = 0;
    self->x16C = 0;
    return self;
}
static inline void merge_flush_func_0039F860(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039F860 */

/* merge_units: begin func_0039FC10 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); void* xz = this; }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");  return *this; }
} __attribute__((aligned(16)));
struct cMatrix {
    float m[4][4];
    void Init(const cVector& a, const cVector& b, const cVector& c, const cVector& d);
    cVector operator*(const cVector& v) const {
        cVector r; cVector& rr = r; void* xx = &r; void* yy = &r; __int128 t;
        __asm__ volatile("lq %0, 0x0(%1)" : "=&r"(t) : "r"(&v) : "memory");
        const cMatrix* pm; __asm__ volatile("" : "=r"(pm) : "0"(this));
        __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(xx) : "memory");
        __asm__ volatile("lqc2 $vf8, 0x0(%0); lqc2 $vf4, 0x0(%1); lqc2 $vf5, 0x10(%1); lqc2 $vf6, 0x20(%1); lqc2 $vf7, 0x30(%1); vmulax.xyzw $ACC, $vf4, $vf8x; vmadday.xyzw $ACC, $vf5, $vf8y; vmaddaz.xyzw $ACC, $vf6, $vf8z; vmaddw.xyzw $vf12, $vf7, $vf8w; sqc2 $vf12, 0x0(%0)" : : "r"(&rr), "r"(pm) : "memory");
        return rr;
    }} __attribute__((aligned(16)));
static inline cVector Mm1(const cMatrix& a, const cVector& v) { return a * v; }
static inline cVector Mm2(const cMatrix& a, const cVector& v) { return Mm1(a, v); }
extern "C" {
extern signed char D_0053BB00;
extern cMatrix D_004BC560;
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix* m, const cVector& a, const cVector& b, const cVector& c, const cVector& d);
}
inline void cMatrix::Init(const cVector& a, const cVector& b, const cVector& c, const cVector& d) { const cVector& aa = a; cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, aa, b, c, d); }
struct cParticleSpline;
extern "C" void cParticleSpline_ComputeBezierFactors(const cParticleSpline* self, const cVector* controlPoints, cVector* mcp)
{
    cVector cp;
    cVector res;
    if (!D_0053BB00) {
        D_004BC560.Init(cVector(3.0f, -6.0f, 3.0f, 0.0f), cVector(-3.0f, 3.0f, 0.0f, 0.0f), cVector(1.0f, 0.0f, 0.0f, 0.0f), cVector(0.0f, 0.0f, 0.0f, 0.0f));
        D_0053BB00 = 1;
    }
    cp = cVector(controlPoints[0].x, controlPoints[1].x, controlPoints[2].x, 0.0f);
    res = D_004BC560 * cp;
    mcp[0] = cVector(res.x, res.y, res.z, 0.0f);
    cp = cVector(controlPoints[0].y, controlPoints[1].y, controlPoints[2].y, 0.0f);
    res = Mm1(D_004BC560, cp);
    mcp[1] = cVector(res.x, res.y, res.z, 0.0f);
    cp = cVector(controlPoints[0].z, controlPoints[1].z, controlPoints[2].z, 0.0f);
    res = Mm2(D_004BC560, cp);
    mcp[2] = cVector(res.x, res.y, res.z, 0.0f);
}
static inline void merge_flush_func_0039FC10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039FC10 */

/* merge_units: begin func_0039FF30 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
typedef __int128 u_long128;
struct cVector_0039FF30 {
    float x, y, z, w;
    cVector_0039FF30() {}
    cVector_0039FF30(const cVector_0039FF30& source) { void* xx = this; cVector_0039FF30& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); }
    cVector_0039FF30& operator=(const cVector_0039FF30& source) { void* xx = this; cVector_0039FF30& refThis = *this; u_long128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    cVector_0039FF30& operator-=(const cVector_0039FF30& vector) {
        const cVector_0039FF30* pv = &vector;
        asm {
            lqc2 vf1, 0(this)
            lqc2 vf2, 0(pv)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0(this)
        }
        return *this;
    }
    unsigned char IsZeroXYZ() const {
        int k, fl;
        int r = 0;
        asm {
            .set noreorder
            lqc2 vf1, 0(this)
            vaddx.xyz vf1, vf1, vf0x
            and r, zero, zero
            ori k, zero, 0xE
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
    cVector_0039FF30& Normalize(float& returnLength) {
        cVector_0039FF30& refThis = *this; u_long128 reg = 0; float* pl = &returnLength;
        asm {
            lqc2 vf1, 0(this)
            vmul.xyz vf2, vf1, vf1
            vmulax.w ACC, vf0, vf2x
            vmadday.w ACC, vf0, vf2y
            vmaddz.w vf3, vf0, vf2z
            vsqrt Q, vf3w
            vwaitq
            vaddq.x vf4, vf0, Q
            vdiv Q, vf0w, vf4x
            vwaitq
            vmulq.xyz vf1, vf1, Q
            sqc2 vf1, 0(this)
            qmfc2.ni reg, vf4
            sw reg, 0(pl)
        }
        
        return refThis;
    }
    cVector_0039FF30 GetNormalized(float& returnLength) const { return cVector_0039FF30(*this).Normalize(returnLength); }
    cVector_0039FF30 operator*(float scale) const {
        int t;
        cVector_0039FF30 result;
        cVector_0039FF30* pr = &result;
        asm {
            .set noreorder
            lqc2 vf1, 0(this)
            mfc1 t, scale
            qmtc2.ni t, vf2
            vmulx.xyzw vf1, vf1, vf2x
            sqc2 vf1, 0(pr)
            .set reorder
        }
        return result;
    }
} __attribute__((aligned(16)));
static inline float fabs_(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
struct cParticleSpline;
extern "C" void cParticleSpline_SplineComputeForceNormal(cParticleSpline* o, cVector_0039FF30& force, const cVector_0039FF30& pt1, const cVector_0039FF30& pt2, float desiredDistance, float k);
void cParticleSpline_SplineComputeForceNormal(cParticleSpline* o, cVector_0039FF30& force, const cVector_0039FF30& pt1, const cVector_0039FF30& pt2, float desiredDistance, float k)
{
    force = pt1;
    force -= pt2;
    if (!force.IsZeroXYZ()) {
        cVector_0039FF30 forceNormal; float distance; forceNormal = force.GetNormalized(distance);
        if (fabs_(distance - desiredDistance) > k) {
            force = forceNormal * k;
        }
    }
}
static inline void merge_flush_func_0039FF30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0039FF30 */

/* merge_units: begin func_003A0050 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_rotateloops off

typedef unsigned long long u64_t;

struct V4_0050 {
    float x, y, z, w;
    V4_0050() {}
    V4_0050(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4_0050& operator=(const V4_0050& o)
    {
        { void* xx = this; } /* dead on purpose: retail computes the destination first */
        __int128 t;
        __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
/* quadword copy through a register (lq/sq) */
static inline void QC_0050(void* d0, const void* s0) { void* d = d0; __int128 q; const void* s = s0; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }
struct Q_0050 { __int128 q; };


extern "C" {
extern char D_00537F80[];
extern char g_Video[];
extern char D_00538080[];
extern char D_0053B6A0[];
extern unsigned char D_0053B540;
extern unsigned int* D_005381C8;
unsigned int* cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(void* q, int a, int b, int c, int d);
void cDmaMan_EndChain_int_ulongP(void* q, int a, void* end);
int XLib_GetTexMan(void* r);
void* cTexMan_GetHalTexture(int reg, int tex);
u64_t* cTexture_GetTEX1_1(void* t);
u64_t* cTexture_GetTEX0_1(void* t);
void MEMCPY16(void* d, void* s, int n);
Q_0050* cRandomVector_Vector(void* tbl, int i);
unsigned int cVU1Man_GetMSCAL(void* q, int n);
}

static inline unsigned int Unpack_0050(unsigned int a, unsigned int n) { return (0x6C000000 | ((n) << 16) | (a)); }
/* the original copies quadwords into the packet with this inline-asm loop */
static inline void QCopy_0050(const void* s, void* d, int n)
{
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
/* per-site copy of QCopy_0050: parameter order picks retail registers */
static inline void QCopy1_0050(void* d, int n, const void* s)
{
    __int128 t;
    const void* ss = s;
    asm {
        .set noreorder
    lp:
        lq t, 0(ss)
        addiu d, d, 0x10
        addi n, n, -1
        addiu ss, ss, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}

static inline void V3Copy_0050(V4_0050* d, const V4_0050* s)
{
    float w = d->w;
    QC_0050(d, s);
    d->w = w;
}

static inline void Vif_Put(unsigned int v)
{
    unsigned int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = v;
}

/* same as Vif_Put with the value copied first (register choice at the first site) */
static inline void Vif_PutV(unsigned int v)
{
    unsigned int x = v;
    unsigned int* p = D_005381C8;
    D_005381C8 = p + 1;
    *p = x;
}

static inline void Vif_PadTo(unsigned int m)
{
    while (((unsigned int)D_005381C8 & 0xF) != m) {
        Vif_Put(0);
    }
}

extern "C" void cParticleSpline_Render(char* e, float t, float a, float b, float c)
{
    float x;
    float y;
    float z;
    float w;
    int i;
    if (F_(e, 0x6C, int) <= 0) return;
    x = 0.0f;
    F_(e, 0xAC, float) = a;
    y = 1.0f / (1.0f + x);
    F_(F_(e, 0x100, char*), 0x94C, float) = t - F_(e, 0x64, float);
    z = x;
    F_(F_(e, 0x100, char*), 0x970, float) = b;
    w = x;
    if (F_(F_(e, 0x100, char*), 0x8F0, int)) {
        V3Copy_0050((V4_0050*)(F_(e, 0x100, char*) + 0x900), (V4_0050*)(e + 0x50));
    }
    if (!D_0053B540 || !F_(F_(e, 0x100, char*), 0x58, int)) {
        F_(F_(e, 0x100, char*), 0x90C, float) = F_(F_(e, 0x100, char*), 0x50, float) * c;
    } else {
        F_(F_(e, 0x100, char*), 0x90C, float) = F_(F_(e, 0x100, char*), 0x54, float) * c;
    }
    for (i = 0; i < F_(F_(e, 0x100, char*), 0x3C, int) + 1; i++) {
        char* s3;
        char* s7;
        int left;
        int lim;
        u64_t* p;
        *(V4_0050*)(e + 0xC0) = V4_0050(x, y, z, w);
        D_005381C8 = cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 0);
        Vif_PutV(0x11000000);
        Vif_Put(0);
        Vif_PadTo(0xC);
        Vif_Put(Unpack_0050(0xF, 7));
        QCopy1_0050(D_005381C8, 7, e + 0x90);
        D_005381C8 += 0x1C;
        {
            char* src = F_(e, 0x100, char*) + 0x900;
            Vif_PadTo(0xC);
            Vif_Put(Unpack_0050(0x16, 0xB));
            QCopy_0050(src, D_005381C8, 0xB);
        }
        D_005381C8 += 0x2C;
        Vif_PadTo(0);
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, D_005381C8);
        s3 = F_(e, 0x100, char*);
        s7 = F_(e, 0x70, char*);
        left = F_(e, 0x6C, int);
        x -= F_(s3, 0x40, float);
        z += F_(s3, 0x44, float);
        w += F_(s3, 0x48, float);
        F_(s3, 0xB0, u64_t) = *cTexture_GetTEX1_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), F_(s3, 0x74, int)));
        F_(s3, 0xC0, u64_t) = *cTexture_GetTEX0_1(cTexMan_GetHalTexture(XLib_GetTexMan(g_Video), F_(s3, 0x74, int)));
        lim = 0x21;
        if (F_(s3, 0x64, unsigned char)) {
            F_(s3, 0xB8, u64_t) = 0x15;
            lim = 0xE;
            F_(s3, 0xC8, u64_t) = 7;
            F_(s3, 0xD0, u64_t) = 1 | ((u64_t)0x612F4000 << 32);
            F_(s3, 0xD8, u64_t) = 1 | ((u64_t)0x602F4000 << 32);
        }
        p = (u64_t*)cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(D_00537F80, 1, 1, 0, 1);
        *p = 0;
        p++;
        while (left > 0) {
            int n = left < lim ? left : lim;
            F_(s3, 0x130, u64_t) = (long long)n | (0x8000 | ((u64_t)0x602F4000 << 32));
            *p = 0;
            p++;
            *p = (u64_t)0x6C0D8000 << 32;
            p++;
            MEMCPY16(p, s3 + 0x80, 0xC);
            p += 0x18;
            *(Q_0050*)p = *cRandomVector_Vector(D_0053B6A0, (int)(s7 + left));
            p += 2;
            *p = cVU1Man_GetMSCAL(D_00538080, 0x18);
            p++;
            *p = 0;
            p++;
            left -= n;
        }
        cDmaMan_EndChain_int_ulongP(D_00537F80, 1, p);
    }
}
static inline void merge_flush_func_003A0050(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A0050 */
