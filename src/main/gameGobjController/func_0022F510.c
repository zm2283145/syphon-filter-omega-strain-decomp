#include "types.h"
/* Controller_GetShooterMotion: motion block of the controlled human, or a zeroed default */
typedef struct Pt1SmComp { char pad[0x310]; int motion[4]; } Pt1SmComp;
typedef struct Pt1SmActor { char pad0[0x4C]; int kind; char pad50[0x3310 - 0x50]; Pt1SmComp* comp; } Pt1SmActor;
typedef struct Pt1SmCtrl { char pad0[0x30]; Pt1SmActor* actor; } Pt1SmCtrl;
extern int D_0049D010;
extern signed char D_004E1D88;
extern int D_004E1D90;
extern int D_004E1D94;
extern int D_004E1D98;
extern int D_004E1D9C;
static inline int* Pt1Sm_Default(void)
{
    if (!D_004E1D88) {
        D_004E1D90 = 0;
        D_004E1D88 = 1;
        D_004E1D94 = 0;
        D_004E1D98 = 0;
        D_004E1D9C = 0;
    }
    return &D_004E1D90;
}int* func_0022F510(Pt1SmCtrl* c)
{
    Pt1SmActor* a = c->actor;
    a = (a && a->kind == D_0049D010) ? a : 0;
    if (a)
        return a->comp ? a->comp->motion : Pt1Sm_Default();
    return 0;
}
