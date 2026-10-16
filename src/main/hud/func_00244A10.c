#include "types.h"
typedef struct { char pad[0x58]; void* res; char p1[0x68 - 0x5C]; void* inst; } T244A10;
extern void Hud_ClearTargetLock(T244A10* p);
extern void func_003EE830(void* r, int f);
extern void* IeElement_Create(void* r);
extern void IeElement_SetShown(void* i, int f);
extern void IeElement_EvaluateAt(void* i, float t);
extern void IeElement_Fade(void* i, float t);
void func_00244A10(T244A10* p) {
    Hud_ClearTargetLock(p);
    if (p->res) {
        func_003EE830(p->res, 0);
        p->inst = IeElement_Create(p->res);
        IeElement_SetShown(p->inst, 1);
        IeElement_EvaluateAt(p->inst, 0.0f);
        IeElement_Fade(p->inst, 17.0f);
    }
}