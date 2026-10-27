/*
 * SFOGame/Source/scriptUtils: 16 files, 00269070-002693F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00269070 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptUtils_types.h"

#if 0 /* merge_units */
void* Array_SOBJ_convert(void* self); /* gsynth: defined below */
#endif /* merge_units */
void * Array_SOBJ_convert(); /* merge_units */

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int Array_SOBJ_toInt(int value);
#if 0 /* merge_units */
extern void* Array_SOBJ_convert(void* obj);
#endif /* merge_units */
void * Array_SOBJ_convert(); /* merge_units */



void Array_SOBJ_init(void) {
}

int func_00269080(int value) {
    return Array_SOBJ_toInt(value);
}

/* Identity. volatile mirrors the original stack temporary. */
int Array_SOBJ_toInt(int value) {
    volatile int v = value;
    return v;
}

void* ScriptArray_Cast_Thunk(void* obj) {
    return Array_SOBJ_convert(obj);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269070 */

/* merge_units: begin func_002690C0 */
#pragma push /* merge_units */
extern int D_004F8488;  /* script array type key */
extern int* Array_SOBJ_getClassId(void);

/* Cast from script object to array (identity). */
void* Array_SOBJ_convert(void* self) {
    return self;
}

int* func_002690D0(void) {
    return Array_SOBJ_getClassId();
}

int* Array_SOBJ_getClassId(void) {
    return &D_004F8488;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002690C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002690C0 */

/* merge_units: begin func_002690F0 */
#pragma push /* merge_units */
extern int Global_RoundToInt(float value);

/* Script native: RoundToInt(value = args[0]).
 * volatile mirrors the original stack temporaries. */
int Script_RoundToInt(ScriptArg* args) {
    volatile int result;
    volatile int bits = args[0].i;
    result = Global_RoundToInt(*(float*)&bits);
    return result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002690F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002690F0 */

/* merge_units: begin func_00269120 */
#pragma push /* merge_units */
#include "float_to_int.h"

/* Convert a float to int. */
DEFINE_FLOAT_TO_INT(Global_RoundToInt)
static inline void merge_flush_func_00269120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00269120 */

/* merge_units: begin func_00269130 */
#pragma push /* merge_units */
#if 0 /* merge_units */
void Global_Randomize(void); /* gsynth: defined below */
#endif /* merge_units */
void Global_Randomize(); /* merge_units */

/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern int Global_Randomize(void);
#endif /* merge_units */
void Global_Randomize(); /* merge_units */



int Script_Randomize(void) {
    Global_Randomize();
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269130 */

/* merge_units: begin func_00269150 */
#pragma push /* merge_units */
extern float RandomInt_float_float(float lo, float hi);

/* Script native: RandomInt(lo, hi); the float result is returned as raw bits. */
int Script_RandomInt_2(ScriptArg* args) {
    volatile float result;
    volatile int hi = args[1].i;
    volatile int lo = args[0].i;
    result = RandomInt_float_float(*(float*)&lo, *(float*)&hi);
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269150 */

/* merge_units: begin func_00269190 */
#pragma push /* merge_units */
typedef union { int i; float f; } ScriptArg_00269190;

extern float RandomInt_float(float range);

/* Script native: returns a random value for the given range, as raw bits. */
int Script_RandomInt(ScriptArg_00269190* args)
{
    ScriptArg_00269190 out[1];
    ScriptArg_00269190 in[1];
    in[0].i = args[0].i;
    out[0].f = RandomInt_float(in[0].f);
    return out[0].i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269190 */

/* merge_units: begin func_002691C0 */
#pragma push /* merge_units */
typedef union { int i; float f; } ScriptArg_002691C0;

extern float Random_float_float(float lo, float hi);

/* Script native: returns a random float between two bounds, as raw bits. */
int Script_Random_2(ScriptArg_002691C0* args)
{
    ScriptArg_002691C0 result[1];
    ScriptArg_002691C0 hi[1];
    ScriptArg_002691C0 lo[1];
    hi[0].i = args[1].i;
    lo[0].i = args[0].i;
    result[0].f = Random_float_float(lo[0].f, hi[0].f);
    return result[0].i;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002691C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002691C0 */

/* merge_units: begin func_00269200 */
#pragma push /* merge_units */
extern float Random_float(float max);

/* Script native: returns a random float in [0, args[0]). */
int Script_Random(int* args)
{
    volatile float result;
    int x[1];
    x[0] = args[0];
    result = Random_float(*(float*)x);
    return *(int*)&result;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269200(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269200 */

/* merge_units: begin func_00269230 */
#pragma push /* merge_units */
extern int g_TimerAccum;
extern void srand(int seed);
/* Seeds the random generator from the hardware timer plus a global. */
void Global_Randomize(void) { srand(*(volatile int*)0x10000800 + g_TimerAccum); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269230 */

/* merge_units: begin func_00269250 */
#pragma push /* merge_units */
extern int Libc_Rand(void);
float RandomInt_float_float(float lo, float hi)
{
    float r = (float)Libc_Rand() / 2147483648.0f;
    float d = (float)((int)hi - (int)lo);
    return (float)(int)((float)(int)lo + d * r);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269250(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269250 */

/* merge_units: begin func_002692D0 */
#pragma push /* merge_units */
float RandomInt_float(float max)
{
    return (float)(int)((float)(int)max * ((float)Libc_Rand() / 2147483648.0f));
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002692D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002692D0 */

/* merge_units: begin func_00269320 */
#pragma push /* merge_units */
/* Returns a random float in [lo, hi). */
float Random_float_float(float lo, float hi) {
    float t = (float)Libc_Rand() / 2147483648.0f;
    float range = hi - lo;
    return lo + range * t;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269320 */

/* merge_units: begin func_00269380 */
#pragma push /* merge_units */
/* Returns a random float in [0, range). */
float Random_float(float range) { return range * ((float)Libc_Rand() / 2147483648.0f); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269380(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269380 */

/* merge_units: begin func_002693C0 */
#pragma push /* merge_units */
typedef union { int i; void* p; float f; } ScriptArg_002693C0;
#if 0 /* merge_units */
extern void Debug_PrintStub(int s);
#endif /* merge_units */
void Debug_PrintStub(); /* merge_units */

/* Script native: prints its argument. */
int Script_Print(ScriptArg_002693C0* args)
{
    volatile int s = args[0].i;
    Debug_PrintStub(s);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002693C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002693C0 */

/* merge_units: begin func_002693F0 */
#pragma push /* merge_units */
extern void* cNodeList_ctor(void* obj);
extern int cNodeList_SOBJ_toInt(void* obj);
extern void* cGroup_SOBJ_convert(void* obj);

void Debug_PrintStub(void) {
}

/* Script native: CreateNodeList(args[0]). */
int Script_CreateNodeList(ScriptArg* args) {
    return cNodeList_SOBJ_toInt(cNodeList_ctor(cGroup_SOBJ_convert(args[0].p)));
}
static inline void merge_flush_func_002693F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002693F0 */
