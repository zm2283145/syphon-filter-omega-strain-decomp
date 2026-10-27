/*
 * main/scriptUtils: 5 files, 00269250-00269320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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
typedef union { int i; void* p; float f; } ScriptArg;
extern void Debug_PrintStub(int s);
/* Script native: prints its argument. */
int Script_Print(ScriptArg* args)
{
    volatile int s = args[0].i;
    Debug_PrintStub(s);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002693C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002693C0 */
