#include "types.h"
typedef struct { char pad[0x58]; void* res; char p1[0x68 - 0x5C]; void* inst; } T244A10;
extern void cHud_ClearTarget(T244A10* p);
extern void cInterfaceModel_SetPerspective(void* r, int f);
extern void* cInterfaceModel_CreateInstance(void* r);
extern void cInterfaceElement_Activate(void* i, int f);
extern void viBufGetTs(void* i, float t);
extern void cAnimator_AnimateTo(void* i, float t);
void cHud_ActivateAimCursor(T244A10* p) {
    cHud_ClearTarget(p);
    if (p->res) {
        cInterfaceModel_SetPerspective(p->res, 0);
        p->inst = cInterfaceModel_CreateInstance(p->res);
        cInterfaceElement_Activate(p->inst, 1);
        viBufGetTs(p->inst, 0.0f);
        cAnimator_AnimateTo(p->inst, 17.0f);
    }
}