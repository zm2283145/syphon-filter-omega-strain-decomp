#pragma cplusplus on
#include "types.h"
union ScriptArg2F340 { int i; float f; void* p; };
struct Z2F340 { signed char a, b, c, d; };
struct A2F340 { char p0[0xD8]; int count; Z2F340 z[1]; char pad[0xB72 - 0xE0]; unsigned char dirty; };
/* Script: removes the matching zeus unlock entry (stage, level-1, mission-1) from the agent. */
extern "C" int Script_cAgentData_LockZeus(ScriptArg2F340* args)
{
    int c[1];
int b[1];
int a[1];
    int av;
int bv;
int cv;
    A2F340* ag;
    int i;
    c[0] = args[3].i;
    cv = *(int*)c;
    b[0] = args[2].i;
    bv = *(int*)b;
    a[0] = args[1].i;
    av = *(int*)a;
    ag = (A2F340*)args[0].p;
    for (i = 0; i < *(volatile int*)&ag->count; i++) {
        Z2F340* z = &ag->z[i];
        if (z->a == av && z->b == bv - 1 && z->c == cv - 1) {
            ag->count--;
            *(Z2F340*)((char*)ag + (i << 2) + 0xDC) = ag->z[ag->count];
            ag->dirty = 1;
            break;
        }
    }
    return 0;
}
