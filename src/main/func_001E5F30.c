#include "types.h"
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
void cCollisionFace_Set_cCollisionModelFaceLocatorR(Tri_5F30*, void*);
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