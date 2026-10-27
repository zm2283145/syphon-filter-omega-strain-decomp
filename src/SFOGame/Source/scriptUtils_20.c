/*
 * SFOGame/Source/scriptUtils: 4 files, 00269070-00269120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00269070 */
#pragma push /* merge_units */
#include "types.h"
#include "scriptUtils_types.h"

void* Array_SOBJ_convert(void* self); /* gsynth: defined below */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int Array_SOBJ_toInt(int value);
extern void* Array_SOBJ_convert(void* obj);


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
