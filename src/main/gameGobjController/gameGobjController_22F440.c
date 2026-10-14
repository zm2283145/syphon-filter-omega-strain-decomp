/*
 * main/gameGobjController: range (2 files, 0022F440-0022F510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0022F440 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Controller_IsEnemyTeam: true when this controller's team treats `other` as an enemy */
typedef struct { unsigned char enemy : 1; unsigned char rest : 7; } Pt1EtRel;
struct Pt1EtCtrl {
    VPAD16(a) VPAD8(b)
    virtual int GetTeam();
};
extern "C" Pt1EtRel (*D_004EE620)[16];
static inline int Pt1Et_IsEnemy(int a, int b)
{
    if (D_004EE620 && a > -1 && a < 16 && b > -1 && b < 16)
        return D_004EE620[a][b].enemy;
    return 0;
}
extern "C" unsigned char Controller_IsEnemyTeam(Pt1EtCtrl* c, int other)
{
    unsigned char r = 0;
    if (c->GetTeam() >= 0 && other >= 0)
        r = Pt1Et_IsEnemy(c->GetTeam(), other);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F440(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F440 */

/* merge_units: begin func_0022F510 */
#pragma push /* merge_units */
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
}int* Controller_GetShooterMotion(Pt1SmCtrl* c)
{
    Pt1SmActor* a = c->actor;
    a = (a && a->kind == D_0049D010) ? a : 0;
    if (a)
        return a->comp ? a->comp->motion : Pt1Sm_Default();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022F510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022F510 */
