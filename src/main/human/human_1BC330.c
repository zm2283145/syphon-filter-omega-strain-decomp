/*
 * main/human: range (3 files, 001BC330-001BC490)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001BC330 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
void Xform_Translate_1BC330(V4* a, V4* b) {
    char* pv1 = (char*)a + 0x10;
    asm {
        lqc2 vf1, 0x30(pv1)
        lqc2 vf2, 0x0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x30(pv1)
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BC330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BC330 */

/* merge_units: begin func_001BC350 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct { V4 rot; V4 pos; } Plc;
static inline void QRot(V4* v, V4* q) {
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
static inline void VAdd3(V4* s, V4* d) {
    asm {
        lqc2 vf1, 0x0(d)
        lqc2 vf2, 0x0(s)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(d)
    }
}
static inline V4 MulS(V4* a, float k) {
    V4 r;
    V4* d = &r;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    }
    return r;
}
static inline void MulS2(V4* d, V4* a, float k) {
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    }
}
static inline V4 MulS3(V4* a, float k) { V4 r; MulS2(&r, a, k); return r; }
static inline void QC(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
struct VC { float x, y, z, w; VC() {} VC(const VC& o) { VC* dd = this; QC(dd, &o); } } __attribute__((aligned(16)));
static inline VC MulV(V4* a, float k) { VC r; int t; VC* d = &r; asm {
        .set noreorder
        lqc2 vf1, 0x0(a)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(d)
        .set reorder
    } return r; }
static inline VC MulV2(V4* a, float k) { VC r; VC* d = &r; MulS2((V4*)d, a, k); return *d; }
static inline V4 MulW(V4* a, float k) { V4 r; V4* d = &r; MulS2(d, a, k); return *d; }
static inline void SetPos(Plc* p, V4* v) { V4* dd = &p->pos; QC(dd, v); }
static inline void SetPos2(V4* d, V4* v) { V4* dd = d; QC(dd, v); }
struct Nd { char pad[0x80]; Plc p; char padA0[2]; unsigned char dirty; char padA3[0xD]; int bB0; };
extern "C" {
void* Root_GetParent(Nd* n);
Plc* Root_GetWorldPlacement(void* r);
void Transform_SetOrientation(Plc* d, Plc* s);
void Placement_Invert(Plc* p);
void SceneRoot_SetPoseCachePos(Nd* self, V4* pos);
}
#pragma opt_propagation off
void SceneRoot_SetPoseCachePos(Nd* self, V4* pos)
{
    { Plc* d = &self->p; V4* dd = &d->pos; QC(dd, pos); }
    if (self->bB0) {
        Plc inv; Plc* ip; Plc* p; V4* ipos; V4* v;
        Transform_SetOrientation(&inv, Root_GetWorldPlacement(Root_GetParent(self)));
        Placement_Invert(&inv);
        p = &self->p;
        ip = &inv;
        v = &p->pos;
        ipos = &ip->pos;
        QRot(v, &ip->rot);
        float* pw = &v->w;
        float w = *pw;
        if (1.0f == w) {
            VAdd3(ipos, v);
        } else {
            VC t = MulV(ipos, w); V4* tq = (V4*)&t;
            VAdd3(tq, v);
            float* pw2 = &v->w; *pw2 = t.w;
        }
    }
    self->dirty = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BC350(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BC350 */

/* merge_units: begin func_001BC490 */
#pragma push /* merge_units */
V4* Actor_AddTeleportXyz(V4* a, V4* b) {
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vadd.xyz vf1, vf1, vf2
        sqc2 vf1, 0x0(a)
    }
    return a;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BC490(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BC490 */
