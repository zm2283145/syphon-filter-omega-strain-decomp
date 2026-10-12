#pragma cplusplus on
#include "types.h"
struct Obj2492A0 { char p[0xC]; int id; };
struct T2492A0 { char p[0x3C]; int flags; char p40[0x7C]; unsigned char bBC; char pBD[3]; Obj2492A0* tgt; int tid; Obj2492A0* lk; int lid; char pD0[0x14]; int fE4; };
extern "C" {
extern void* D_004FFC2C;
void func_00244280(void* p);
}
static inline Obj2492A0* Get2492A0(T2492A0* s) {
    bool isNull;
bool ok;
Obj2492A0* t;
    t = s->tgt;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != s->tid) ok = false;
    return ok ? t : 0;
}
static inline void Set2492A0(T2492A0* s, Obj2492A0* p) {
    int none;
    s->lk = p;
    s->lid = *(p ? &p->id : (none = -1, &none));
}
extern "C" void HudTargets_DropLock(T2492A0* t, Obj2492A0* o)
{
    if (Get2492A0(t) == o) {
        t->fE4 = -1;
        Set2492A0(t, 0);
        t->bBC = 1;
        if ((t->flags >> 5) & 1) func_00244280(D_004FFC2C);
    }
}
