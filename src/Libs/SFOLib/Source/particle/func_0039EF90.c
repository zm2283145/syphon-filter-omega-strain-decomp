#pragma cplusplus on
#include "types.h"

static inline void* CopyQ1(void* d, const void* s) { __int128 q; asm { .set reorder; lq q, 0x0(s); sq q, 0x0(d) } return d; }
struct V4 {
    float x, y, z, w;
    V4() {}
    V4(const V4& x, const V4& y, float) { const V4* pb = &y; const V4* a = &x; asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(this)
        } }
    V4(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    V4(const V4& source) { void* xx = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    V4(const V4& source, unsigned char) { const V4* src = &source; void* xx = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(src) : "memory"); }
    V4(const V4& source, unsigned short) { void* xx = this; const V4* src = &source; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(src) : "memory"); }
    V4(const V4& source, unsigned long) { const V4* src = &source; V4* t = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(t), "r"(src) : "memory"); }
    V4(const V4& source, signed char) { V4* t = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(t), "r"(&source) : "memory"); }
    V4(const V4& source, int) { __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    V4(const V4& source, short) { V4* t = this; const V4* src = &source; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(t), "r"(src) : "memory"); }
    V4(const V4& source, char) { const V4* src = &source; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(src) : "memory"); }
    V4(const V4& source, long) { void* xx = this; __int128 reg; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(this), "r"(&source) : "memory"); }
    V4& operator=(const V4& source) { void* xx = this; __int128 reg; V4& refThis = *this; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(reg) : "r"(&refThis), "r"(&source) : "memory"); return refThis; }
    V4 operator-(const V4& b) const {
        V4 r; V4* o = &r; const V4* a = this; const V4* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(o)
        }
        return r;
    }
    V4 operator-() const {
        V4 r; V4* o = &r; const V4* a = this;
        asm {
            lqc2 vf1, 0x0(a)
            vmulax.xyzw ACC, vf0, vf0x
            vmsubw.xyzw vf1, vf1, vf0w
            sqc2 vf1, 0x0(o)
        }
        return r;
    }
    V4& operator+=(const V4& b) {
        V4* d = this; const V4* a = this; const V4* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vadd.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(d)
        }
        return *this;
    }
    V4& operator*=(float s) {
        V4* a = this; int t;
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
    V4& Normalize() {
        V4* d = this; V4* a = this;
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
    float Dot(const V4& b) const {
        const V4* a = this; const V4* pb = &b; int t; float r = 0.0f;
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
    V4 Cross(const V4& b) const {
        V4 r; V4* o = &r; const V4* a = this; const V4* pb = &b;
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
    V4 GetNormalized() const { return V4(*this).Normalize(); }
    V4 SubM(const V4& b, int) const {
        V4 r(*this, b, 0.0f); return V4(r, (long)0);
    }
    V4 SubK(const V4& b) const {
        V4 r; V4* o = &r; const V4* a = this; const V4* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(o)
        }
        return V4(r);
    }
    V4 SubN(const V4& b) const {
        V4 r; V4* o = &r; const V4* a = this; const V4* pb = &b;
        asm {
            lqc2 vf1, 0x0(a)
            lqc2 vf2, 0x0(pb)
            vsub.xyzw vf1, vf1, vf2
            sqc2 vf1, 0x0(o)
        }
        return V4(r, 0);
    }
    void SetXYZ(const V4& v) { float s = w; *this = v; w = s; }
} __attribute__((aligned(16)));

struct M4 {
    V4 r[4];
    void Apply(V4* o, const V4* v) const {
        const M4* m = this; V4* po = o; const V4* pv = v;
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
struct Box { V4 a; V4 b; };
struct Bnd { V4 a; V4 b; V4 c; V4 d; V4& B() { return b; } };
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
    virtual V4 GetPos();
    virtual Bnd GetBounds();
};
struct Info2 { char pad[0x14]; unsigned int count; };
struct Ref { char pad[4]; Info2* info; short* ids; int At(unsigned int i) { if (i < info->count) return ids[i]; return -1; } bool Has() { return info->count != 0; } };
struct Src { char pad[0x68]; Ref* ref; };
struct Owner { char pad[0x74]; int id; };

struct Panel {
    char pad0[0xB0];
    V4 normal;
    char padC0[0xE0 - 0xC0];
    V4 edge;
    V4 dir;
    V4 p0;
    V4 p1;
    Owner* owner;
    char pad124[0x130 - 0x124];
    V4 c0;
    V4 c1;
    char pad150[0x154 - 0x150];
    float f154;
    char pad158[0x170 - 0x158];
    int id;
};

extern "C" int cCollisionModelMaster_GetData(int);
extern "C" V4* cCollisionModel_Data_GetVertex(int, int);
extern "C" void cTexMan_AddTextureReference(int, int);
extern int g_TextureMgr;
static inline V4 GetPt(int info, int i) { return *cCollisionModel_Data_GetVertex(cCollisionModelMaster_GetData(info), i); }
#pragma inline_depth(16)




static inline V4 CrossF(V4 a, V4 b) { return a.Cross(b); }
static inline V4 Sub(const V4& x, const V4& y) { return x.SubK(y); }
static inline V4 Sub2(const V4& x, const V4& y) { return Sub(x, y); }
static inline V4 Sub3(const V4& x, const V4& y) { return Sub2(x, y); }
static inline V4 Sub4(const V4& x, const V4& y) { return Sub3(x, y); }
static inline V4 Neg(const V4& x) { return -x; }
static inline V4 Neg2(const V4& x) { return Neg(x); }
static inline V4 CrossF2(V4 a, V4 b) { return CrossF(a, b); }
static inline V4 CrossR(const V4& a, const V4& b) { return a.Cross(b); }

static inline V4 Neg3(const V4& x) { return Neg2(x); }
static inline V4 CrossF3(V4 a, V4 b) { return CrossF2(a, b); }
static inline V4 CrossR2(const V4& a, const V4& b) { return CrossR(a, b); }
static inline V4 CrossR3(const V4& a, const V4& b) { return CrossR2(a, b); }
static inline V4 CrossR4(const V4& a, const V4& b) { return CrossR3(a, b); }
static inline V4 SubD(const V4& x, const V4& y, V4 r = V4()) { V4* o = &r; const V4* a = &x; const V4* pb = &y; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(o) } return r; }
static inline V4 SubD2(const V4& x, const V4& y) { return SubD(x, y); }
static inline V4 NegD(const V4& x, V4 r = V4()) { V4* o = &r; const V4* a = &x; asm { lqc2 vf1, 0x0(a); vmulax.xyzw ACC, vf0, vf0x; vmsubw.xyzw vf1, vf1, vf0w; sqc2 vf1, 0x0(o) } V4& rr = r; return rr; }
static inline V4 CrossD(const V4& x, const V4& y, V4 r = V4()) { const V4* a = &x; const V4* pb = &y; V4* o = &r; asm { lqc2 vf1, 0x0(a); lqc2 vf2, 0x0(pb); vopmula.xyz ACC, vf1, vf2; vopmsub.xyz vf3, vf2, vf1; vsubw.w vf3, vf0, vf0w; sqc2 vf3, 0x0(o) } V4& rr = r; return rr; }
static inline V4 CrossD2(const V4& x, const V4& y) { return CrossD(x, y); }extern "C" void cParticleShatter_SetShatterData(Panel* p, Obj* a, Src* src, Obj* b, V4 v0, V4 v1, float f)
{
    V4 normal;
    p->p0 = v0;
    p->p1 = v1;
    p->f154 = f;
    p->dir = a->GetPos().SubN(b->GetPos()).GetNormalized();
    Shape* sh = a->GetShape();
    if (sh != 0 && sh->mesh->xf != 0 && (*sh->info)->type == 4) {
        Shape* s = a->GetShape();
        Xform* xf = s->mesh->xf;
        V4 pts[4];
        V4 sum(0.0f, 0.0f, 0.0f, 0.0f);
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
        V4 c2 = pts[second];
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






