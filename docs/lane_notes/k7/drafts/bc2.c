#pragma cplusplus on
#pragma always_inline on
#pragma opt_strength_reduction off
#include "types.h"
#include "cmessage.h"

union V4 {
    __int128 q; float f[4];
    V4() {}
    V4(const V4& o) { __int128 t; asm volatile("lq %0,0(%1)\n\tsq %0,0(%2)" : "=r"(t) : "r"(&o), "r"(this) : "memory"); }
    V4(V4* a, V4* b)
    {
        V4* p = this;
        asm volatile("lqc2 vf1,0(%0)\n\tlqc2 vf2,0(%1)\n\tvadd.xyzw vf1,vf1,vf2\n\tsqc2 vf1,0(%2)" : : "r"(a), "r"(b), "r"(p) : "memory");
    }
};
struct Mtx { __int128 q[4]; };
struct Bounds { V4 mn; V4 mx; };
class Ctl {
public:
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4();
    virtual void c5(); virtual void c6(); virtual void c7(); virtual void c8(); virtual void c9();
    virtual void c10(); virtual void c11(); virtual void c12(); virtual void c13(); virtual void c14();
    virtual void c15(); virtual void c16(); virtual void c17(); virtual void c18();
    virtual int Active();
    char pad4[0x10]; unsigned char b14;
};
struct Proj;
class Obj {
public:
    virtual void o0(); virtual void o1(); virtual void o2(); virtual void o3(); virtual void o4();
    virtual void o5(); virtual void o6(); virtual void o7(); virtual void o8(); virtual void o9();
    virtual void o10(); virtual void o11(); virtual void o12(); virtual void o13(); virtual void o14();
    virtual void o15(); virtual void o16(); virtual void o17(); virtual void o18(); virtual void o19();
    virtual void o20(); virtual void o21(); virtual void o22(); virtual void o23(); virtual void o24();
    virtual void o25(); virtual void o26(); virtual void o27(); virtual void o28(); virtual void o29();
    virtual void o30(); virtual void o31();
    virtual Bounds* GetBounds();
    virtual void o33(); virtual void o34(); virtual void o35(); virtual void o36(); virtual void o37();
    virtual void o38(); virtual void o39(); virtual void o40(); virtual void o41(); virtual void o42();
    virtual void o43(); virtual void o44(); virtual void o45();
    virtual V4 AimPos(int k);
    virtual void o47(); virtual void o48(); virtual void o49(); virtual void o50(); virtual void o51(); virtual void o52(); virtual void o53(); virtual void o54();
    virtual V4 Center();
    virtual void o56(); virtual void o57(); virtual void o58(); virtual void o59(); virtual void o60();
    virtual void o61(); virtual void o62();
    virtual int Hit(Proj* p);
    char pad4[8]; int serial; char pad10[0x48]; Ctl* ctl;
};
struct Handle { Obj* p; int serial;
    Obj* P() const { return p; }
    bool Same() const { return p->serial == serial; }
};
struct LNode { int pad0; LNode* next; Handle h; };
struct It {
    LNode* n;
    It(LNode* p) : n(p) {}
    bool operator!=(const It& o) const { return n != o.n; }
    It() {}
    It operator++(int) { It r; It old = *this; n = n->next; r = old; return r; }
};
struct Tbl { char pad0[0x34]; int a; int b; int c; char pad40[0x24]; int va; int vb; int vc; };
struct Proj {
    Obj* owner; Mtx* xf; Obj* target; unsigned char bC; char padD[3]; int k; float range;
    Tbl* tbl; float bias; unsigned char b20; char pad21[3]; int f24; char pad28[5]; unsigned char b2D; char pad2E[2];
    int f30; int pad34; int f38; int pad3C; float f40;
};
struct SndMsg { CMSG_HEADER; char pad[0x19C]; };

extern "C" {
extern char D_004F78DC[];
extern char D_004A6470[];
extern char D_004EF3F0[];
extern char D_004FFB50[];
extern char D_004DAE30[];
LNode* WorldObjList_Get(void* p);
void Mtx_Transpose3x3(Mtx* d, Mtx* s);
int Mtx_IsTranslationZero(Mtx* m);
V4* func_00133EC0(Mtx* m);
void Vec4_Assign(V4* d, V4* s);
void Vec3_Negate(V4* v);
void Mtx_TransformByTranspose(V4* v, Mtx* m);
void Mtx_SetTranslation(Mtx* m, V4* v);
void func_00127358(char* fmt, int n);
void SoundEvent_CtorFromPreset(void* m, void* preset, Obj* o);
void Event_Send(void* m, void* dst, int f);
void func_0036E220(void* p, int f);
}

struct Vt {
    V4 v;
    Vt(V4* s) { Vec4_Assign(&v, s); }
    Vt& Neg() { Vec3_Negate(&v); return *this; }
    Vt& TT(Mtx* m) { Mtx_TransformByTranspose(&v, m); return *this; }
    V4* p() { return &v; }
};
static inline void InvRT(Mtx* m)
{
    if (!Mtx_IsTranslationZero(m)) {
        V4 t;
        Vec4_Assign(&t, func_00133EC0(m));
        Vec3_Negate(&t);
        Mtx_TransformByTranspose(&t, m);
        Mtx_SetTranslation(m, &t);
    }
}
static inline It Begin(LNode* l) { It r(l->next); return r; }
static inline It End(LNode* l) { It r(l); return r; }
static inline Obj* Get(Handle* h)
{
    bool ok = !h->P() || h->Same();
    if (ok) return h->p;
    return 0;
}
static inline void MulV(Mtx* m, V4* v, V4* o)
{
    Mtx* mm = m; V4* vv = v; V4* oo = o;
    asm volatile {
        lqc2 vf8, 0(vv)
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf7, 0x30(mm)
        vmulax.xyzw ACC, vf4, vf8x
        vmadday.xyzw ACC, vf5, vf8y
        vmaddaz.xyzw ACC, vf6, vf8z
        vmaddw.xyzw vf12, vf7, vf8w
        sqc2 vf12, 0(oo)
    }
}
static inline V4 Add(V4* a, V4* b)
{
    V4 r;
    V4* p = &r;
    asm volatile {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vadd.xyzw vf1, vf1, vf2
        sqc2 vf1, 0(p)
    }
    return r;
}
static inline V4 Mul(V4 v, float k)
{
    V4 r;
    V4* p = &r;
    V4* s = &v;
    __int128 t = 0;
    asm volatile {
        .set noreorder
        lqc2 vf1, 0x0(s)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(p)
        .set reorder
    }
    return r;
}
static inline V4 Half(V4* a, V4* b)
{
    V4 v;
    V4 r;
    V4 sum(a, b);
    __int128 t = 0;
    float k = 0.5f;
    V4* p = &r;
    { __int128 q; asm volatile("lq %0,0(%2)\n\tsq %0,0(%1)" : "=r"(q) : "r"(&v), "r"(&sum) : "memory"); }
    V4* s = &v;
    asm volatile("lqc2 vf1,0x0(%0)" : : "r"(s) : "memory");
    asm volatile {
        .set noreorder
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        .set reorder
    }
    asm volatile("sqc2 vf1,0x0(%0)" : : "r"(p) : "memory");
    return r;
}
static inline void SubEq(V4* o, V4* a, V4* b)
{
    asm volatile("lqc2 vf1,0(%1)\n\tlqc2 vf2,0(%2)\n\tvsub.xyzw vf1,vf1,vf2\n\tsqc2 vf1,0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline float Len(V4* v)
{
    float r = 0.0f;
    int t;
    asm volatile {
        lqc2 vf1, 0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline float LenSq(V4* v)
{
    float r = 0.0f;
    int t;
    asm volatile {
        lqc2 vf1, 0(v)
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

static inline void InvRT2(Mtx* m) { InvRT(m); }
static inline void InvRT3(Mtx* m) { InvRT2(m); }
extern "C" void CheckBulletCollisions(Proj* self)
{
    char* w = D_004F78DC;
    It it = Begin(WorldObjList_Get(w + 4));
    It end = End(WorldObjList_Get(w + 4));
    int n = 0;
    bool done;
    Obj* objs[20];
    float dists[20];
    Mtx m;
    V4 pos;
    V4 ext;

    {
        Mtx* src = self->xf;
        __int128 qa, qb;
        Mtx* d = &m;
        qa = src->q[0]; qb = src->q[1]; d->q[0] = qa; qa = src->q[2]; d->q[1] = qb; qb = src->q[3]; d->q[2] = qa; d->q[3] = qb;
        Mtx_Transpose3x3(&m, d);
    }
    InvRT3(&m);
    for (; it != end; it++) {
        Obj* o = Get(&it.n->h);
        Bounds* b;
        if (o && o != self->owner) {
        b = o->GetBounds();
        if (b) {
            bool hit;
            float y;
            float len;
            if (o == self->target)
                pos = o->AimPos(self->k);
            else
                pos = o->Center();
            MulV(&m, &pos, &pos);
            hit = 0;
            y = pos.f[1];
            ext = Half(&b->mn, &b->mx);
            SubEq(&ext, &ext, &b->mn);
            len = Len(&ext);
            if (!(y <= 0.0f) && y - len < self->range) {
                pos.f[1] = 0.0f;
                hit = LenSq(&pos) < len * len;
            }
            if (hit) {
                if (n < 20) {
                    objs[n] = o;
                    dists[n] = y;
                    n++;
                } else {
                    func_00127358(D_004A6470, n);
                }
            }
        }
        }
    }
    self->f30 = 0;
    done = 0;
    self->f38 = 0;
    while (!done) {
        int best = -1;
        int i;
        for (i = 0; i < n; i++) {
            if (objs[i]) {
                if (best < 0 || dists[i] < dists[best]) best = i;
            }
        }
        if (best < 0) {
            done = 1;
        } else {
            Obj* o = objs[best];
            int r = 0;
            if (o != self->target || self->bC) {
                self->f40 = 0.0f;
                if (!self->b20) {
                    int v;
                    Tbl* t = self->tbl;
                    float d = self->bias + dists[best];
                    v = t->vb;
                    if (!(d <= (float)t->a)) {
                        float num, den, frac;
                        if (!(d <= (float)t->b)) {
                            frac = d - (float)t->b;
                            num = (float)(t->vc - t->va);
                            den = (float)(t->c - t->b);
                        } else if (!(d <= (float)t->a)) {
                            num = (float)(t->va - t->vb);
                            den = (float)(t->b - t->a);
                            frac = d - (float)t->a;
                        }
                        v = (int)((float)v + num * frac / den);
                    }
                    self->f40 = (float)v;
                }
                r = o->Hit(self);
            }
            if ((unsigned char)r) {
                if (self->f24 <= 0) done = 1;
            } else if (o->ctl && o->ctl->Active() && o->ctl->b14 && !self->b20 && !self->b2D) {
                SndMsg msg;
                void* pre = D_004EF3F0;
                SoundEvent_CtorFromPreset(&msg, pre, o);
                msg.kind = 1;
                Event_Send(&msg, D_004FFB50, 1);
                msg.vtable = D_004DAE30;
                func_0036E220((char*)&msg + 0x114, -1);
                func_0036E220((char*)&msg + 0x78, -1);
                cMessage_dtor(&msg, 0);
            }
            objs[best] = 0;
        }
    }
}
