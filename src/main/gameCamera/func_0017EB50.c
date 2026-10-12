#include "types.h"
extern char D_004DA410[];
extern void CameraRig_TranslateFollowCurves();
extern void Curve_ComputeRates();
extern void Curve_PreUpdate();
extern void Curve_Retarget();
extern void Curve_SetVelocity();
extern void Curve_VirtualNop();
extern void func_0017CE90();
extern void func_0017ECD0();
extern void func_0017ED80();
extern void func_00180020();
void * const D_004DA380[12] = { (void*)0x0, (void*)0x0, (void*)func_0017ECD0, (void*)func_00180020, (void*)0x0, (void*)0x0, (void*)Curve_Retarget, (void*)Curve_VirtualNop, (void*)Curve_SetVelocity, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004DA3B0[12] = { (void*)0x0, (void*)0x0, (void*)func_0017ED80, (void*)CameraRig_TranslateFollowCurves, (void*)0x0, (void*)0x0, (void*)Curve_PreUpdate, (void*)func_0017CE90, (void*)Curve_ComputeRates, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char D_004DA3E0[];
extern void func_0017EC70(void* p, int f);
extern void operator_delete(void* p);
typedef struct { void* vt; } V_EB50;
V_EB50* func_0017EB50(V_EB50* self, short flag)
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
            func_0017EC70(m2, -1);
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