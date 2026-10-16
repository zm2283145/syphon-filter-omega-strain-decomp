#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma always_inline on
#pragma inline_depth(8)

static inline void Q16b(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(d) : "memory"); }
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V& operator=(const V& o) { void* xx = (void*)&o; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Plc { V rot, pos; };
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
struct Plc4 { V4 rot, pos; };
struct Mtx { V4 r0, r1, r2, r3; };

struct Elem { VPAD16(a) VPAD4(b) virtual void Sync(); char pad04[0xC]; Mtx m; unsigned char b50; };
extern "C" {
void Quat_Assign(V4*, V4*);
void func_0017D540(void*, float);
int func_0017D510(void*);
void func_0017D340(V4*, void*);
void func_0017D0A0(void*, float);
int func_0017D070(void*);
void func_0017CEA0(V4*, void*);
void Vec4_Copy(V4*, V4*);
}
struct QCtl {
    VPAD4(a) virtual void Begin(); virtual void End(); virtual void Step(float t, float u);
    char pad04[0xC];
    V4 prev;        /* 0x10 */
    V4 cur;         /* 0x20 */
    char pad30[0x10];
    V4 target;      /* 0x40 */
    char pad50[0x60];
    char filt[0x20];/* 0xB0 */
    void Update(float t, float u) {
        Quat_Assign(&prev, &cur);
        Begin();
        func_0017D540(filt, t);
        if (func_0017D510(this)) {
            V4 tmp;
            func_0017D340(&tmp, filt);
            Quat_Assign(&cur, &tmp);
            End();
        } else {
            Quat_Assign(&cur, &target);
        }
        Step(t, u);
    }
};
struct PCtl {
    VPAD4(a) virtual void Begin(); virtual void End(); virtual void Step(float t, float u);
    char pad04[0xC];
    V4 prev;        /* 0x10 */
    V4 cur;         /* 0x20 */
    char pad30[0x10];
    V4 target;      /* 0x40 */
    char pad50[0x60];
    char filt[0x20];/* 0xB0 */
    void Update(float t, float u) {
        Vec4_Copy(&prev, &cur);
        Begin();
        func_0017D0A0(filt, t);
        if (func_0017D070(this)) {
            V4 tmp;
            func_0017CEA0(&tmp, filt);
            Vec4_Copy(&cur, &tmp);
            End();
        } else {
            Vec4_Copy(&cur, &target);
        }
        Step(t, u);
    }
};

struct S {
    Plc4 base;          /* 0x00 */
    signed char idx;    /* 0x20 */
    char pad21[0xF];
    QCtl a;             /* 0x30 */
    PCtl b;             /* 0x100 */
};

extern "C" {
Elem* func_001CFF30(void* arr, int index);
void func_00132840(V*);
void Quat_Multiply(V*, V*, V*);
void func_00132800(V*, V*);
void func_001CFAE0(S* s, void* arr, float t, float u);
}
static inline Elem* GetElem(void* arr, const signed char& i) { return func_001CFF30(arr, i); }static inline Plc4* MtxToPlc(Mtx* m, Plc4* out) {
    Plc4* o = out;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(m)
        lqc2 vf2, 0x10(m)
        lqc2 vf3, 0x20(m)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(o)
        .set reorder
    }
    Q16(&out->pos, &m->r3);
    return out;
}

static inline void QRot(V* v, V* q) {
    asm {
        lqc2 vf1, 0x0(v)
        vmove.w vf6, vf1
        vmr32.w vf1, vf0
        lqc2 vf2, 0x0(q)
        vmove.w vf3, vf2
        vsub.xyz vf3, vf0, vf2
        vmul.xyzw vf4, vf2, vf1
        vopmula.xyz ACC, vf2, vf1
        vmaddaw.xyz ACC, vf1, vf2w
        vopmsub.xyz vf5, vf1, vf2
        vsubaz.w ACC, vf4, vf4z
        vmsubay.w ACC, vf0, vf4y
        vmsubx.w vf5, vf0, vf4x
        vopmula.xyz ACC, vf5, vf3
        vmaddaw.xyz ACC, vf5, vf3w
        vmaddaw.xyz ACC, vf3, vf5w
        vopmsub.xyz vf6, vf3, vf5
        sqc2 vf6, 0x0(v)
    }
}
static inline void VAdd3(V* s, V* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}

void func_001CFAE0(S* s, void* arr, float t, float u)
{
    Plc4* src;
    if (s->idx != -1) {
        Plc p;
        void* d1; __int128 q1; __int128 q2; void* d2; const void* s2; const signed char* ip;
        d1 = &p.rot; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q1) : "r"(&s->base.rot), "r"(d1) : "memory");
        ip = &s->idx;
        d2 = &p.pos; s2 = &s->base.pos; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q2) : "r"(s2), "r"(d2) : "memory");
        Elem* e = GetElem(arr, *ip);
        if (e->b50) {
            e->Sync();
        }
        Plc4 pil;
        MtxToPlc(&e->m, &pil);
        Plc* pi = (Plc*)&pil;
        V r;
        V q;
        func_00132840(&q);
        Quat_Multiply(&q, &pi->rot, &p.rot);
        func_00132800(&r, &q);
        p.rot = r;
        QRot(&p.pos, &pi->rot);
        V* pp = (V*)&pil.pos;
        VAdd3(pp, &p.pos);
        src = (Plc4*)&p;
    } else {
        src = &s->base;
    }
    {
    const void* t2; void* e1; __int128 r1; void* e2; __int128 r2;
    e1 = &s->a.target; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(r1) : "r"(e1), "r"(&src->rot) : "memory");
    t2 = &src->pos; e2 = &s->b.target; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(r2) : "r"(e2), "r"(t2) : "memory");
    }
    s->a.Update(t, u);
    s->b.Update(t, u);
}


