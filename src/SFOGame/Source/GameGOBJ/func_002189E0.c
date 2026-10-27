#pragma cplusplus on
#include "types.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void VCopyN(void* d, const void* s) {
    __int128 t;
    asm { lq t, 0(s) }
    asm { sq t, 0(d) }
}
/* 16-byte lq/sq copy as GCC-style volatile asm (house idiom, c57da): MW keeps the
   later vcall receiver in a0 (`lw t9,0(a0)`) as retail does. */
static inline void VCopyFF(void* d, const void* s) {
    __int128 t;
    __asm__ volatile("lq %0,0(%2)\n sq %0,0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory");
}
struct Mtx { V4 r[4]; };
struct Plc { float m[3][4]; V4 pos; };
inline void* operator new(unsigned int, void* p) { return p; }
struct Src {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad4[0xC]; Mtx xform; unsigned char dirty;
};typedef struct { char pad[0x10]; } Elem16;
struct Obj;
extern "C" {
void PathObj_GetPoint(Obj* o, V4* out, int i);
void cMatrix_Copy_InvertRotTrans(Mtx* out, Mtx* in);
Elem16* func_002181C0(void* v, int i);
int func_002181D0(void* v);
void cPathedGOBJ_TransformAttached(Obj* o, Mtx m, int f);
void cPathedGOBJ_TeleportToPathPoint(Obj* self, int idx);
}
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void SetPlacement(Plc* p);
    char pad4[0x4C]; Src* src; char pad54[0xA4 - 0x54]; char vecA4[0xD0 - 0xA4]; int* pD0; char padD4[0xC]; float fE0;
};static inline Mtx* GetXform(Src* s) {
    if (s->dirty) s->Refresh();
    return &s->xform;
}
static inline void QToM(Mtx* m, Elem16* q) {
    asm {
        lqc2 vf1, 0x0(q)
        vadd.xyzw vf2, vf1, vf1
        vaddw.xyz vf3, vf0, vf0w
        vmulx.w vf8, vf0, vf0x
        vmulx.w vf9, vf0, vf0x
        vmuly.xyzw vf5, vf1, vf2y
        vmulz.xyzw vf6, vf1, vf2z
        vmulx.xyzw vf4, vf1, vf2x
        vmulx.w vf10, vf0, vf0x
        vsubay.x ACC, vf3, vf5y
        vmsubz.x vf8, vf3, vf6z
        vsubw.x vf9, vf5, vf6w
        vaddw.x vf10, vf6, vf5w
        vaddw.y vf8, vf4, vf6w
        vsubax.y ACC, vf3, vf4x
        vmsubz.y vf9, vf3, vf6z
        vsubw.y vf10, vf6, vf4w
        vsubw.z vf8, vf4, vf5w
        vaddw.z vf9, vf5, vf4w
        vsubax.z ACC, vf3, vf4x
        vmsuby.z vf10, vf3, vf5y
        sqc2 vf0, 0x30(m)
        sqc2 vf8, 0x0(m)
        sqc2 vf9, 0x10(m)
        sqc2 vf10, 0x20(m)
    }
}
static inline void Mul(Mtx* po, Mtx* b, Mtx* a) {
    Mtx* pa = a; Mtx* pb = b;
    asm {
        lqc2 vf4, 0x0(pb)
        lqc2 vf5, 0x10(pb)
        lqc2 vf6, 0x20(pb)
        lqc2 vf7, 0x30(pb)
        lqc2 vf8, 0x0(pa)
        lqc2 vf9, 0x10(pa)
        lqc2 vf10, 0x20(pa)
        lqc2 vf11, 0x30(pa)
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
        sqc2 vf12, 0x0(po)
        sqc2 vf13, 0x10(po)
        sqc2 vf14, 0x20(po)
        sqc2 vf15, 0x30(po)
    }
}
static inline void MCopy(Mtx* d, Mtx* ss) { __int128 qa; __int128 qb; Mtx* s = ss; asm {
 lq qa, 0x0(s)
 lq qb, 0x10(s)
 sq qa, 0x0(d)
 lq qa, 0x20(s)
 sq qb, 0x10(d)
 lq qb, 0x30(s)
 sq qa, 0x20(d)
 sq qb, 0x30(d)
 } }
#pragma opt_common_subs off
void cPathedGOBJ_TeleportToPathPoint(Obj* self, int idx) {
    V4 oldPos;
    V4 pt;
    Mtx inv;
    Plc p;
    Mtx mat;
    Elem16* q;
    int i;
    { Src* s = self->src; if (s->dirty) s->Refresh(); VCopyFF(&oldPos, &s->xform.r[3]); }
    PathObj_GetPoint(self, &pt, idx);
    pt.w = 1.0f;
    cMatrix_Copy_InvertRotTrans(&inv, GetXform(self->src));
    i = idx;
    if (idx < 0) i = 0;
    if (i < func_002181D0(self->vecA4)) q = func_002181C0(self->vecA4, i);
    else q = func_002181C0(self->vecA4, func_002181D0(self->vecA4) - 1);
    QToM(&mat, q);
    p.m[0][0] = mat.r[0].x; p.m[0][1] = mat.r[0].y; p.m[0][2] = mat.r[0].z;
    p.m[1][0] = mat.r[1].x; p.m[1][1] = mat.r[1].y; p.m[1][2] = mat.r[1].z;
    p.m[2][0] = mat.r[2].x; p.m[2][1] = mat.r[2].y; p.m[2][2] = mat.r[2].z;
    p.m[0][3] = mat.r[0].w; p.m[1][3] = mat.r[1].w; p.m[2][3] = mat.r[2].w;
    VCopyN(&p.pos, &pt);
    self->SetPlacement(&p);
    { Mtx m; Mtx t; Mul(&t, (Mtx*)&p, &inv); MCopy(&m, &t); cPathedGOBJ_TransformAttached(self, m, 1); }
    *self->pD0 = idx;
    self->fE0 = 1.0f;
}


