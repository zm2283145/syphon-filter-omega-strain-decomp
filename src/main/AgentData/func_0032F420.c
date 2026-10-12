#pragma cplusplus on
#include "types.h"
union ScriptArg2F420 { int i; float f; void* p; };
struct Z2F420 { signed char a, b, c, d; };
struct A2F420 { char p0[0xD8]; int count; Z2F420 z[1]; char pad[0xB72 - 0xE0]; unsigned char dirty; };
static inline unsigned char Has2F420(A2F420* ag, int av, int bv, int cv)
{
    int i;
    for (i = 0; i < *(volatile int*)&ag->count; i++) {
        Z2F420* z = &ag->z[i];
        if (z->a == av && z->b == bv - 1 && z->c == cv - 1) return 1;
    }
    return 0;
}
/* Script: adds the zeus unlock entry (stage, level-1, mission-1) unless already present. */
extern "C" int Script_cAgentData_UnlockZeus(ScriptArg2F420* args)
{
    int c[1];
int b[1];
int a[1];
    A2F420* ag;
int av;
int bv;
int cv;
    c[0] = args[3].i;
    cv = *(int*)c;
    b[0] = args[2].i;
    bv = *(int*)b;
    a[0] = args[1].i;
    av = *(int*)a;
    ag = (A2F420*)args[0].p;
    if (!Has2F420(ag, av, bv, cv)) {
        Z2F420* z = (Z2F420*)((char*)ag + (ag->count++ << 2) + 0xDC);
        z->a = av;
        z->b = bv - 1;
        z->c = cv - 1;
        z->d = 0;
        ag->dirty = 1;
    }
    return 0;
}
