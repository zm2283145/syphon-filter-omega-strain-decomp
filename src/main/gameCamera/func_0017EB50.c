#include "types.h"
extern char D_004DA410[];
extern void cSplinedMotion_cVector_TeleportByDelta();
extern void cSplinedMotion_cVector_UpdateVelocity();
extern void cSplinedMotion_cVector_UpdateSplinePoints();
extern void cSplinedMotion_float_UpdateSplinePoints();
extern void cSplinedMotion_float_UpdateVelocity();
extern void cSplinedMotion_float_FixUpResultOfSplineEvaluation();
extern void cSplinedMotion_cVector_FixUpResultOfSplineEvaluation();
extern void func_0017ECD0();
extern void cCollisionSystem_cBox_dtor_void();
extern void cSplinedMotion_float_TeleportByDelta();
void * const D_004DA380[12] = { (void*)0x0, (void*)0x0, (void*)func_0017ECD0, (void*)cSplinedMotion_float_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_float_UpdateSplinePoints, (void*)cSplinedMotion_float_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_float_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004DA3B0[12] = { (void*)0x0, (void*)0x0, (void*)cCollisionSystem_cBox_dtor_void, (void*)cSplinedMotion_cVector_TeleportByDelta, (void*)0x0, (void*)0x0, (void*)cSplinedMotion_cVector_UpdateSplinePoints, (void*)cSplinedMotion_cVector_FixUpResultOfSplineEvaluation, (void*)cSplinedMotion_cVector_UpdateVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char D_004DA3E0[];
extern void cSplinedMotion_Scalar_dtor_void(void* p, int f);
extern void operator_delete(void* p);
typedef struct { void* vt; } V_EB50;
V_EB50* cCameraShake_dtor(V_EB50* self, short flag)
{
    if (self) {
        V_EB50* m = (V_EB50*)((char*)self + 0x80);
        void* m2;
        if (m) {
            self[0x20].vt = D_004DA410;
            if (m)
                self[0x20].vt = ((char*)D_004DA3B0);
        }
        m2 = (char*)self + 0x38;
        if (m2)
            cSplinedMotion_Scalar_dtor_void(m2, -1);
        if (self) {
            self->vt = D_004DA3E0;
            if (self)
                self->vt = ((char*)D_004DA380);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}