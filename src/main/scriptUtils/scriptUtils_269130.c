/*
 * main/scriptUtils: range (6 files, 00269130-00269230)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "scriptUtils_types.h"

/* merge_units: begin func_00269130 */
#pragma push /* merge_units */
void Global_Randomize(void); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int Global_Randomize(void);
#endif /* merge_units */
#define Global_Randomize() (Global_Randomize()) /* merge_units */


int Script_Randomize(void) {
    Global_Randomize();
    return 0;
}
#undef Global_Randomize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269130 */

/* merge_units: begin func_00269150 */
#pragma push /* merge_units */
extern float Global_RandomInt(float lo, float hi);

/* Script native: RandomInt(lo, hi); the float result is returned as raw bits. */
int Script_RandomInt_2(ScriptArg* args) {
    volatile float result;
    volatile int hi = args[1].i;
    volatile int lo = args[0].i;
    result = Global_RandomInt(*(float*)&lo, *(float*)&hi);
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269150 */

/* merge_units: begin func_00269190 */
#pragma push /* merge_units */
typedef union { int i; float f; } ScriptArg_00269190;

extern float Script_RandomIntCore(float range);

/* Script native: returns a random value for the given range, as raw bits. */
int Script_RandomInt(ScriptArg_00269190* args)
{
    ScriptArg_00269190 out[1];
    ScriptArg_00269190 in[1];
    in[0].i = args[0].i;
    out[0].f = Script_RandomIntCore(in[0].f);
    return out[0].i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269190 */

/* merge_units: begin func_002691C0 */
#pragma push /* merge_units */
typedef union { int i; float f; } ScriptArg_002691C0;

extern float Global_Random_2(float lo, float hi);

/* Script native: returns a random float between two bounds, as raw bits. */
int Script_Random_2(ScriptArg_002691C0* args)
{
    ScriptArg_002691C0 result[1];
    ScriptArg_002691C0 hi[1];
    ScriptArg_002691C0 lo[1];
    hi[0].i = args[1].i;
    lo[0].i = args[0].i;
    result[0].f = Global_Random_2(lo[0].f, hi[0].f);
    return result[0].i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002691C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002691C0 */

/* merge_units: begin func_00269200 */
#pragma push /* merge_units */
extern float Global_Random(float max);

/* Script native: returns a random float in [0, args[0]). */
int Script_Random(int* args)
{
    volatile float result;
    int x[1];
    x[0] = args[0];
    result = Global_Random(*(float*)x);
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269200 */

/* merge_units: begin func_00269230 */
#pragma push /* merge_units */
extern int D_00533870;
extern void srand(int seed);
/* Seeds the random generator from the hardware timer plus a global. */
void Global_Randomize(void) { srand(*(volatile int*)0x10000800 + D_00533870); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269230 */
