/*
 * SFOGame/Source/humanCollision: 4 files, 001E5CF0-001E6230
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001E5CF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Ctl5CF0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int Check54();
    virtual int Check58(void* o);
};
typedef struct { char pad[0x4C]; int kind; char pad50[0x58 - 0x50]; Ctl5CF0* ctl; char pad5C[0x346D - 0x5C]; unsigned char inWater; } O_5CF0;
typedef struct { char pad[0x38]; float level; } W_5CF0;
typedef struct { int pad0; O_5CF0* obj; char pad8[0xE4 - 8]; float depth; char padE8[0x170 - 0xE8]; W_5CF0 water; } A_5CF0;
extern "C" {
void cWaterFx_AddBody_cGOBJP_float(float, int, O_5CF0*);
void cWaterFx_RemoveBody(int, O_5CF0*);
void cWaterFx_ChangeWaterHeight(float, int, O_5CF0*);
}
extern float g_NegFltMax;
extern int D_004FFC34;
extern int g_HumanActorClassKey;
static inline unsigned char C54(O_5CF0* o) { unsigned char r = 0; Ctl5CF0* c = o->ctl; if (c && c->Check54()) r = 1; return r; }
#pragma opt_common_subs off
static inline unsigned char IsDeep(A_5CF0* a, float d) {
    unsigned char r = 0;
    float k = g_NegFltMax;
    if (d != g_NegFltMax) {
        W_5CF0* w = (d != k) ? &a->water : 0;
        if (!(w->level <= 0.974f)) r = 1;
    }
    return r;
}
static inline unsigned char Left(int was, int is) { unsigned char r = 0; if (was) { int ok = (is != 0) ^ 1; if (ok) r = 1; } return r; }
static inline unsigned char Moved(int was, int is, float p, float d) { unsigned char r = 0; int ok = was != 0; ok = ok ? is != 0 : ok; if (ok && p != d) r = 1; return r; }
extern "C" void cHumanCollisionRoutine_HandleWaterCollisionIfDetected(A_5CF0* a, float prev)
{
    float d = a->depth;
    int wasIn, isIn; unsigned char left, moved;
    O_5CF0* o;
    d = IsDeep(a, d) ? d : -3.4028235e38f;
    wasIn = prev != -3.4028235e38f;
    isIn = d != -3.4028235e38f;
    left = Left(wasIn, isIn);
    moved = Moved(wasIn, isIn, prev, d);
    o = 0;
    { O_5CF0* ob = a->obj; if (ob->kind == g_HumanActorClassKey) { unsigned char ok = 0; Ctl5CF0* c = ob->ctl; if (c && c->Check58(ob)) ok = 1; if (ok || C54(a->obj)) o = a->obj; } }
    if (o) o->inWater = isIn;
    if (isIn) {
        cWaterFx_AddBody_cGOBJP_float(d, D_004FFC34, a->obj);
        if (moved) cWaterFx_ChangeWaterHeight(d, D_004FFC34, a->obj);
    } else if (left) {
        cWaterFx_RemoveBody(D_004FFC34, a->obj);
    }
}
static inline void merge_flush_func_001E5CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5CF0 */

/* merge_units: begin func_001E5F30 */
#pragma push /* merge_units */
typedef struct { __int128 q; } V_5F30;
typedef struct { V_5F30 rows[4]; char part40[0x10]; unsigned char flag50; unsigned char flag51; unsigned char flag52; char pad53[0xD]; int part60[2]; char pad68[8]; } Tri_5F30;
typedef struct { unsigned char hit; char p1[0x57]; float f58; char p5C[4]; char src[0xB0]; unsigned char b110; char p111[0xCF]; } Res_5F30;
typedef struct { char p0[0xE4]; float fE4; char pE8[0x170 - 0xE8]; Tri_5F30 tri; } Act_5F30;
void cCollisionProbe_SphereSweptRay_ctor(Res_5F30*);
void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(Res_5F30*, void*, V_5F30*, V_5F30*, float, float, float, float, float, int);
int ColQuery_ExecuteThunk(Res_5F30*, int, int);
void cVector_ctor_void(void*);
void cCollisionModel_FaceProperties_ctor(void*);
void cCollisionModel_FaceLocator_ctor(void*);
#if 0 /* merge_units */
void cCollisionFace_Set_cCollisionModelFaceLocatorR(Tri_5F30*, void*);
#endif /* merge_units */
void cCollisionFace_Set_cCollisionModelFaceLocatorR(); /* merge_units */

void cVector_opAssign(void*, void*);
void cCollisionModel_FaceProperties_opAssign(void*, void*);
void cCollisionModel_FaceLocator_opAssign(void*, void*);
static inline V_5F30 Sub_5F30(V_5F30* a, V_5F30* b) {
    V_5F30 r;
    V_5F30* pr = &r;
    asm { lqc2 vf1, 0(a); lqc2 vf2, 0(b); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0(pr) }
    return r;
}
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_propagation off
void cHumanCollisionRoutine_DetectForWater(Act_5F30* a, void* p1, V_5F30* p2, V_5F30* p3) {
    Res_5F30 res;
    V_5F30 dir;
    cCollisionProbe_SphereSweptRay_ctor(&res);
    dir = Sub_5F30(p3, p2);
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(&res, p1, p2, &dir, 0.1f, 0.05f, 0.05f, 0.0f, 0.1f, 0);
    res.b110 = 0;
    ColQuery_ExecuteThunk(&res, 0x80, 0);
    if (res.hit) {
        Tri_5F30 tri;
        Tri_5F30* t = &tri;
        V_5F30* v = t->rows;
        V_5F30* e;
        do { cVector_ctor_void(v); v++; } while (v != (e = t->rows + 3));
        cVector_ctor_void(e);
        cCollisionModel_FaceProperties_ctor(t->part40);
        cCollisionModel_FaceLocator_ctor(t->part60);
        cCollisionFace_Set_cCollisionModelFaceLocatorR(t, res.src);
        cVector_opAssign(&a->tri.rows[0], &tri.rows[0]);
        cVector_opAssign(&a->tri.rows[1], &tri.rows[1]);
        cVector_opAssign(&a->tri.rows[2], &tri.rows[2]);
        cVector_opAssign(&a->tri.rows[3], &tri.rows[3]);
        a->tri.flag50 = tri.flag50;
        cCollisionModel_FaceProperties_opAssign(a->tri.part40, tri.part40);
        cCollisionModel_FaceLocator_opAssign(a->tri.part60, tri.part60);
        a->tri.flag51 = tri.flag51;
        a->tri.flag52 = tri.flag52;
        a->fE4 = res.f58;
    }
}
static inline void merge_flush_func_001E5F30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E5F30 */

/* merge_units: begin func_001E60C0 */
#pragma push /* merge_units */
typedef struct { char pad00[3]; unsigned char version; char pad04[0x14]; int dataOffset; char pad1C[0x10]; int key; } Hdr_60C0;
typedef struct { Hdr_60C0* hdr; } Ref_60C0;
typedef struct { int unk00; Ref_60C0* ref; } Owner_60C0;
typedef struct { unsigned char a, b, c, d; } Surf_60C0;
typedef struct { int index; Owner_60C0* owner; } Src_60C0;
extern signed char D_004E9F98;
extern int D_004F4FD0;
extern Surf_60C0 D_004E9FA0;
extern unsigned char D_004E9FA2;
extern void cCollisionModel_FaceProperties_dtor(void);
extern void __register_global_object(void*, void*, void*);
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(Hdr_60C0* owner, int* key);
extern unsigned char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(Hdr_60C0* hdr, int* offset);
extern void cCollisionFace_SetWithoutCalculatingNormal(void* out, unsigned char* rec, int index, Surf_60C0* surf, Owner_60C0* owner);
#if 0 /* merge_units */
extern void cCollisionFace_CalculateUnitNormal(void* out);
#endif /* merge_units */
void cCollisionFace_CalculateUnitNormal(); /* merge_units */

static inline Surf_60C0* GetSurf_60C0(Owner_60C0* ctx, int index) {
    int key[1];
    Hdr_60C0* owner = ctx->ref->hdr;
    if (owner->version < 3) {
        if (D_004E9F98 == 0) {
            D_004E9FA0.a = 0;
            D_004E9FA2 = 0;
            __register_global_object(&D_004E9FA0, cCollisionModel_FaceProperties_dtor, &D_004F4FD0);
            D_004E9F98 = 1;
        }
        return &D_004E9FA0;
    }
    key[0] = owner->key;
    return (Surf_60C0*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_3(owner, key) + index * 16);
}
void cCollisionFace_Set_cCollisionModelFaceLocatorR(void* out, Src_60C0* src) {
    unsigned char* rec;
    int surf;
    Owner_60C0* owner;
    int index;
    int offset64;
    int offset32;
    int offset16;
    Hdr_60C0* hdr;
    owner = src->owner;
    index = src->index;
    hdr = owner->ref->hdr;
    if (hdr->version < 4) {
        offset64 = hdr->dataOffset;
        rec = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset64) + index * 64;
    } else if (hdr->version < 5) {
        offset32 = hdr->dataOffset;
        rec = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset32) + index * 32;
    } else {
        offset16 = hdr->dataOffset;
        rec = cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(hdr, &offset16) + index * 16;
    }
    surf = (unsigned char)(rec[10] >> 1);
    cCollisionFace_SetWithoutCalculatingNormal(out, rec, index, GetSurf_60C0(owner, surf), owner);
    cCollisionFace_CalculateUnitNormal(out);
}
static inline void merge_flush_func_001E60C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E60C0 */

/* merge_units: begin func_001E6230 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma peephole off
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 v0; V4 v1; V4 v2; V4 n; } Tri_001E6230;
static inline void V4_Sub(V4 *o, V4 *a, V4 *b) {
    V4 *q = a;
    asm {
        lqc2 vf1, 0x0(q)
        lqc2 vf2, 0x0(b)
        vsub.xyzw vf1, vf1, vf2
        sqc2 vf1, 0x0(o)
    }
}
static inline void V4_Scale(V4 *p, V4 *a, float k) {
    int t;
    V4 *q = a;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(q)
        mfc1 t, k
        qmtc2.ni t, vf2
        vmulx.xyzw vf1, vf1, vf2x
        sqc2 vf1, 0x0(p)
        .set reorder
    }
}
static inline void V4_Cross(V4 *p, V4 *a, V4 *b) {
    long long t;
    asm {
        lqc2 vf1, 0x0(a)
        lqc2 vf2, 0x0(b)
        vopmula.xyz ACC, vf1, vf2
        vopmsub.xyz vf3, vf2, vf1
        vsubw.w vf3, vf0, vf0w
        sqc2 vf3, 0x0(p)
        paddub t, zero, zero
    }
}
static inline void V4_Copy(V4 *d, V4 *s) {
    asm {
        lq s, 0x0(s)
        sq s, 0x0(d)
    }
}
void cCollisionFace_CalculateUnitNormal(Tri_001E6230 *t)
{
    V4 e1;
    V4 e2;
    V4 r;
    V4 n;
    V4 t1;
    V4 t2;
    V4 ts;
    V4 tc;
    float k;
    V4_Sub(&t1, &t->v1, &t->v0);
    V4_Copy(&e1, &t1);
    V4_Sub(&t2, &t->v2, &t->v0);
    V4_Copy(&e2, &t2);
    k = t->n.w;
    V4_Cross(&tc, &e1, &e2);
    n = tc;
    {
        V4 *ps = &ts;
        V4_Scale(ps, &n, k);
        r = *ps;
    }
    t->n = r;
}
static inline void merge_flush_func_001E6230(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001E6230 */
