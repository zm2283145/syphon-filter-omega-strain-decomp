/*
 * main/SpecFxDefs: range (4 files, 00232570-00232690)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00232570 */
#pragma push /* merge_units */
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern char D_0053B5C0[];
extern void cWind_Set(void* wind, float a, float b, float c, float d, float e);

/* Script native: sets the global wind parameters from five float args; returns 0. */
int Script_Wind(ScriptArg* args)
{
    int a[1];
    int b[1];
    int c[1];
    int d[1];
    int e[1];
    e[0] = args[4].i;
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    cWind_Set(D_0053B5C0, *(float*)a, *(float*)b, *(float*)c, *(float*)d, *(float*)e);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232570(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232570 */

/* merge_units: begin func_002325D0 */
#pragma push /* merge_units */
typedef union ScriptArg_002325D0 {
    int i;
    float f;
    void* p;
    signed char c;
} ScriptArg_002325D0;

extern void World_StartAtmosphereEffect_Thunk(signed char, int, float, float, float, float);

/* Script: AtmosphericEffect(type, a, b, c, d, e); arguments are staged through the stack. */
int Script_AtmosphericEffect_2(ScriptArg_002325D0* args) {
    int e[1];
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    e[0] = args[5].i;
    d[0] = args[4].i;
    c[0] = args[3].i;
    b[0] = args[2].i;
    a[0] = args[1].i;
    World_StartAtmosphereEffect_Thunk(args[0].c, *(int*)e, *(float*)a, *(float*)b, *(float*)c, *(float*)d);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002325D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002325D0 */

/* merge_units: begin func_00232630 */
#pragma push /* merge_units */
typedef struct AtmosArgs {
    signed char type;
    char pad[3];
    int p1, p2, p3, p4; /* float parameters passed as raw words */
} AtmosArgs;

#if 0 /* merge_units */
extern void World_StartAtmosphereEffect_Thunk(int type, int id, float p1, float p2, float p3, float p4);
#endif /* merge_units */
#define World_StartAtmosphereEffect_Thunk(a0, a1, a2, a3, a4, a5) (World_StartAtmosphereEffect_Thunk((signed char)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */


/* Script native: AtmosphericEffect(type, p1, p2, p3, p4). */
int Script_AtmosphericEffect(AtmosArgs* args) {
    float p1, p2, p3, p4;
    volatile int w4, w3, w2, w1;
    w4 = args->p4;
    p4 = *(float*)&w4;
    w3 = args->p3;
    p3 = *(float*)&w3;
    w2 = args->p2;
    p2 = *(float*)&w2;
    w1 = args->p1;
    p1 = *(float*)&w1;
    World_StartAtmosphereEffect_Thunk(args->type, -1, p1, p2, p3, p4);
    return 0;
}
#undef World_StartAtmosphereEffect_Thunk /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232630(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232630 */

/* merge_units: begin func_00232690 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Script natives that start the level-specific weather effects.
 */


extern int Global_FogMyanmar(void);
extern int Global_RainLorelei(void);
extern int Global_RainTokyo(void);
extern int Global_SmokeToronto3(void);
extern int Global_SnowBelarus2(void);

int Script_SnowBelarus2(void) {
    Global_SnowBelarus2();
    return 0;
}

int Script_RainLorelei(void) {
    Global_RainLorelei();
    return 0;
}

int Script_RainTokyo(void) {
    Global_RainTokyo();
    return 0;
}

int Script_SmokeToronto3(void) {
    Global_SmokeToronto3();
    return 0;
}

int Script_FogMyanmar(void) {
    Global_FogMyanmar();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00232690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00232690 */
