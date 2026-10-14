/*
 * main/scriptUtils: range (5 files, 00268B80-00268DD0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00268B80 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268B80;
typedef struct { float* data; int cap; int count; } Arr_268B80;
extern Arr_268B80* ScriptArray_Cast(int h);
static inline void SetIdx_268B80(int h, int i, float v)
{
    Arr_268B80* a = ScriptArray_Cast(h);
    if (i >= 0 && i < a->count)
        a->data[i] = v;
}
int Script_Array_ChangeIndex(ScriptArg_268B80* args)
{
    int v[1];
    int idx[1];
    v[0] = args[2].i;
    idx[0] = args[1].i;
    SetIdx_268B80(args[0].i, *(int*)idx, *(float*)v);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268B80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268B80 */

/* merge_units: begin func_00268BF0 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268BF0;
typedef struct { float* data; int cap; int count; } Arr_268BF0;
#if 0 /* merge_units */
extern Arr_268BF0* ScriptArray_Cast(int h);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((Arr_268BF0 *)ScriptArray_Cast((a0))) /* merge_units */

static inline float Get_268BF0(Arr_268BF0* a, int i)
{
    if (i >= 0 && i < a->count)
        return a->data[i];
    return 0.0f;
}
static inline void Remove_268BF0(Arr_268BF0* a, int i)
{
    if (i >= 0 && i < a->count) {
        for (; i < a->count - 1; i++)
            a->data[i] = a->data[i + 1];
        a->count--;
    }
}
int Script_Array_GetAndRemoveIndex(ScriptArg_268BF0* args)
{
    int idx[1];
    float r[1];
    Arr_268BF0* a;
    int i;
    idx[0] = args[1].i;
    i = *(int*)idx;
    a = ScriptArray_Cast(args[0].i);
    {
        float v = Get_268BF0(a, i);
        Remove_268BF0(a, i);
        r[0] = v;
    }
    return *(int*)r;
}
#undef ScriptArray_Cast /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268BF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268BF0 */

/* merge_units: begin func_00268CC0 */
#pragma push /* merge_units */
typedef struct { float* data; int pad; int count; } ScriptArr_e1;
#if 0 /* merge_units */
extern ScriptArr_e1* ScriptArray_Cast(int);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((ScriptArr_e1 *)ScriptArray_Cast((a0))) /* merge_units */

int Script_Array_GetIndex(int* args)
{
    volatile int idx = args[1];
    volatile float r;
    int i = idx;
    ScriptArr_e1* a = ScriptArray_Cast(args[0]);
    float f;
    if (i >= 0 && i < a->count) {
        f = a->data[i];
    } else {
        f = 0.0f;
    }
    r = f;
    return *(int*)&r;
}
#undef ScriptArray_Cast /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268CC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268CC0 */

/* merge_units: begin func_00268D30 */
#pragma push /* merge_units */
typedef union { int i; float f; void* p; } ScriptArg_268D30;
typedef struct { float* data; int cap; int count; } Arr_268D30;
#if 0 /* merge_units */
extern Arr_268D30* ScriptArray_Cast(int h);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((Arr_268D30 *)ScriptArray_Cast((a0))) /* merge_units */

extern float Script_RandomIntCore(float max);
int Script_Array_RandomizeArray(ScriptArg_268D30* args)
{
    Arr_268D30* a = ScriptArray_Cast(args[0].i);
    int i;
    for (i = a->count; i > 0; i--) {
        int j = (int)Script_RandomIntCore((float)i);
        float t = a->data[i - 1];
        a->data[i - 1] = a->data[j];
        a->data[j] = t;
    }
    return 0;
}
#undef ScriptArray_Cast /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268D30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268D30 */

/* merge_units: begin func_00268DD0 */
#pragma push /* merge_units */
typedef struct { float* data; int pad; int count; } ScriptArr_b6;
#if 0 /* merge_units */
extern ScriptArr_b6* ScriptArray_Cast(int);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((ScriptArr_b6 *)ScriptArray_Cast((a0))) /* merge_units */

int Script_Array_Sort(int* args)
{
 ScriptArr_b6* a = ScriptArray_Cast(args[0]);
 int i, j;
 for (i = 0; i < a->count - 1; i++) {
 for (j = i; j < a->count; j++) {
 if (!(a->data[i] <= a->data[j])) { float t = a->data[i]; a->data[i] = a->data[j]; a->data[j] = t; }
 }
 }
 return 0;
}
#undef ScriptArray_Cast /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268DD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00268DD0 */
