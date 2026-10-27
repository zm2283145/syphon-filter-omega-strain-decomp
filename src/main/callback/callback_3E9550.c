/*
 * main/callback: 5 files, 003E9550-003E9940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E9550 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_9550;
struct M4_9550 { V4_9550 r[4]; M4_9550() {} };
class Obj_9550 {
public:
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD2(d) VPAD1(e)
    virtual M4_9550 GetMatrix();
};
typedef struct { char pad[0x60]; int target; char pad64[4]; int id; } S_9550;
extern "C" {
Obj_9550* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
float cVector_X_void(V4_9550* v);
float cVector_Y_void(V4_9550* v);
float cVector_Z_void(V4_9550* v);
void cMatrix_SetWithAxisAngle(M4_9550* m, float x, float y, float z, float a);
void cInterfaceElement_SetView(int t, M4_9550* m);
extern float D_00493980;
}
static inline void Mul_9550(M4_9550* t, M4_9550* b) {
    asm {
        lqc2 vf4, 0x0(t)
        lqc2 vf5, 0x10(t)
        lqc2 vf6, 0x20(t)
        lqc2 vf7, 0x30(t)
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
        sqc2 vf12, 0x0(t)
        sqc2 vf13, 0x10(t)
        sqc2 vf14, 0x20(t)
        sqc2 vf15, 0x30(t)
    }
}
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void HudMapSprite_Place(S_9550* self)
{
    Obj_9550* o = nGobjManager_LookupGOBJ_cObjectIdR(&self->id);
    if (o != 0) {
        M4_9550 m = o->GetMatrix();
        M4_9550 rot;
        V4_9550 axis;
        float k;
        axis.x = 1.0f;
        axis.y = 0.0f;
        axis.z = 0.0f;
        axis.w = 0.0f;
        cMatrix_SetWithAxisAngle(&rot, cVector_X_void(&axis), cVector_Y_void(&axis), cVector_Z_void(&axis), -1.5707964f);
        { M4_9550* t = &m; M4_9550* b = &rot; Mul_9550(t, b); }
        k = D_00493980;
        m.r[0].x *= k;
        m.r[0].y *= k;
        m.r[0].z *= k;
        m.r[1].x *= k;
        m.r[1].y *= k;
        m.r[1].z *= k;
        m.r[2].x *= k;
        m.r[2].y *= k;
        m.r[2].z *= k;
        cInterfaceElement_SetView(self->target, &m);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003E9550 */

/* merge_units: begin func_003E96F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern void cInterfaceElement_SetLocation(int, void*);
extern void cIE_GOBJ_TransformPointIntoCamera(void*);
extern float cAnimator_AnimateTo(int, float);
extern void viBufGetTs(int, float);

void HudLockTracker_Draw(Unk3E96F0* self) {
    cIE_GOBJ_TransformPointIntoCamera(self->unk70);
    cInterfaceElement_SetLocation(self->unk60, self->unk70);
}

void HudLockTracker_Changed(Unk3E96F0* self) {
    viBufGetTs(self->unk60, 0.0f);
    self->unk84 = 1;
}

void cIE_GOBJ_AnimateOff(Unk3E96F0* self) {
    cAnimator_AnimateTo(self->unk60, 0.0f);
    self->unk84 = 1;
}

void cIE_GOBJ_SetHost(Unk3E96F0* self, int* value, int arg) {
    self->unk68 = *value;
    self->unk64 = 1;
    self->unk80 = arg;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E96F0 */

/* merge_units: begin func_003E97D0 */
#pragma push /* merge_units */
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V3E97D0;
typedef struct { char mtx[0x110]; } Cam3E97D0;
typedef struct { char p0[0x1F0]; Cam3E97D0 cams[1]; } W3E97D0;
typedef struct { char p0[0x60]; int h; char p64[0xC]; V3E97D0 dir; } S3E97D0;
#if 0 /* merge_units */
extern void cIE_GOBJ_TransformPointIntoCamera(V3E97D0*);
#endif /* merge_units */
#define cIE_GOBJ_TransformPointIntoCamera(a0) (cIE_GOBJ_TransformPointIntoCamera((void *)(a0))) /* merge_units */

extern void cXViewport_GetScreenVert(V3E97D0* out, void* m, V3E97D0* v);
#if 0 /* merge_units */
extern void cInterfaceElement_SetLocation(int h, V3E97D0* v);
#endif /* merge_units */
#define cInterfaceElement_SetLocation(a0, a1) (cInterfaceElement_SetLocation((a0), (void *)(a1))) /* merge_units */

extern W3E97D0 g_Video;
extern int D_00538C60;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void HudTracker_Draw(S3E97D0* s)
{
    V3E97D0 t;
    unsigned char neg;
    cIE_GOBJ_TransformPointIntoCamera(&s->dir);
    neg = s->dir.y < 0.0f;
    cXViewport_GetScreenVert(&t, g_Video.cams[D_00538C60].mtx, &s->dir);
    {
        V3E97D0* d = &s->dir;
        V3E97D0* q = &t;
        V4Copy(d, q);
    }
    if (neg) s->dir.z = -s->dir.z;
    cInterfaceElement_SetLocation(s->h, &s->dir);
}
#pragma pop
#undef cIE_GOBJ_TransformPointIntoCamera /* merge_units */
#undef cInterfaceElement_SetLocation /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E97D0 */

/* merge_units: begin func_003E9880 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V_E98 { __int128 q; V_E98() {} V_E98& operator=(const V_E98& o) { V_E98* pd = this; const V_E98* ps = &o; asm volatile { lq ps, 0(ps); sq ps, 0(pd) } return *this; } };
struct Obj_E98 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45();
    virtual V_E98 GetNodePos(int node);
};
struct T_E98 { int a; float y; };
struct S_E98 {
    char pad[0x60];
    T_E98* x60;
    unsigned char x64;
    char pad65[3];
    int x68;
    char pad6C[4];
    V_E98 x70;
    int x80;
    unsigned char x84;
};
extern "C" {
#if 0 /* merge_units */
Obj_E98* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
#endif /* merge_units */
#define nGobjManager_LookupGOBJ_cObjectIdR(a0) ((Obj_E98 *)nGobjManager_LookupGOBJ_cObjectIdR((a0))) /* merge_units */

void nGobjManager_RemoveGOBJ(S_E98* s);
void cSystem_ActualScheduleDelete(S_E98* s, float t);
void cIE_GOBJ_NextFrame(S_E98* s);
}
void cIE_GOBJ_NextFrame(S_E98* s)
{
    if (s->x64) {
        Obj_E98* o = nGobjManager_LookupGOBJ_cObjectIdR(&s->x68);
        if (o) {
            s->x70 = o->GetNodePos(s->x80);
        } else {
            s->x64 = 0;
        }
    }
    if (s->x84 && s->x60->y < 0.5f) {
        nGobjManager_RemoveGOBJ(s);
        cSystem_ActualScheduleDelete(s, 0.1f);
        s->x84 = 0;
    }
}
#undef nGobjManager_LookupGOBJ_cObjectIdR /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E9880 */

/* merge_units: begin func_003E9940 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x5C]; void* m60; } G9940;
extern char D_004E05A0[];
extern void cInterfaceElement_Destroy(void* p);
extern void cGOBJ_dtor(void* self, short del);
extern void operator_delete(void* p);
G9940* cIE_GOBJ_dtor(G9940* self, short del)
{
    if (self) {
        self->vt = D_004E05A0;
        cInterfaceElement_Destroy(self->m60);
        cGOBJ_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E9940 */
