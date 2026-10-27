/*
 * main/AgentData: range (3 files, 0032F340-0032F510)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0032F340 */
#pragma push /* merge_units */
#pragma cplusplus on
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F340(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F340 */

/* merge_units: begin func_0032F420 */
#pragma push /* merge_units */
#pragma cplusplus on
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F420 */

/* merge_units: begin func_0032F510 */
#pragma push /* merge_units */
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char pad[0xB08]; unsigned int bits[1]; } A2F510;
int Script_cAgentData_UnlockSpecial(ScriptArg* args)
{
    int i = args[1].b;
    A2F510* self = (A2F510*)args[0].p;
    if (i > -1)
        self->bits[i / 32] |= 1 << (i & 31);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F510(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F510 */
