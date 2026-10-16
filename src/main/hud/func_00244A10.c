#include "types.h"
typedef struct { char pad[0x58]; void* res; char p1[0x68 - 0x5C]; void* inst; } T244A10;
extern void Hud_ClearTargetLock(T244A10* p);
extern void func_003EE830(void* r, int f);
extern void* func_003EF010(void* r);
extern void func_003E8DE0(void* i, int f);
extern void func_003F45A0(void* i, float t);
extern void func_003F44E0(void* i, float t);
void func_00244A10(T244A10* p) {
    Hud_ClearTargetLock(p);
    if (p->res) {
        func_003EE830(p->res, 0);
        p->inst = func_003EF010(p->res);
        func_003E8DE0(p->inst, 1);
        func_003F45A0(p->inst, 0.0f);
        func_003F44E0(p->inst, 17.0f);
    }
}