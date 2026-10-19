/*
 * main/scriptUtils: 10 files, 00268B80-00268F50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268BF0(void) {}
#undef ScriptArray_Cast /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268CC0(void) {}
#undef ScriptArray_Cast /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268D30(void) {}
#undef ScriptArray_Cast /* merge_units */
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
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268DD0(void) {}
#undef ScriptArray_Cast /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268DD0 */

/* merge_units: begin func_00268E80 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

#if 0 /* merge_units */
extern ScriptArray* ScriptArray_Cast(void* obj);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((ScriptArray *)ScriptArray_Cast((int)(a0))) /* merge_units */


/* Script native: Array.Print(); the cast result is unused in this build. */
int Script_Array_Print(ScriptArg* args) {
    ScriptArray_Cast(args[0].p);
    return 0;
}
#undef ScriptArray_Cast /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268E80 */

/* merge_units: begin func_00268EA0 */
#pragma push /* merge_units */
typedef struct { float* data; int pad; int count; } SAF_Arr;
#if 0 /* merge_units */
extern SAF_Arr* ScriptArray_Cast(void* obj);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((SAF_Arr *)ScriptArray_Cast((int)(a0))) /* merge_units */

static inline int SAF_Find(SAF_Arr* arr, float val) {
    int i;
    for (i = 0; i < arr->count; i++) {
        if (arr->data[i] == val) return i;
    }
    return -1;
}
int Script_Array_FindElem(ScriptArg* args) {
    volatile ScriptArg a;
    volatile int r;
    float val;
    a.i = args[1].i;
    val = a.f;
    r = SAF_Find(ScriptArray_Cast(args[0].p), val);
    return r;
}
#undef ScriptArray_Cast /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268EA0 */

/* merge_units: begin func_00268F20 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern ScriptArray* ScriptArray_Cast(void* obj);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((ScriptArray *)ScriptArray_Cast((int)(a0))) /* merge_units */


/* Script native: Array.Count(). volatile mirrors the original stack temporary. */
int Script_Array_Count(ScriptArg* args) {
    volatile int count = ScriptArray_Cast(args[0].p)->count;
    return count;
}
#undef ScriptArray_Cast /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268F20 */

/* merge_units: begin func_00268F50 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268F50;
typedef struct { float* data; int cap; int count; } Arr_268F50;
#if 0 /* merge_units */
extern Arr_268F50* ScriptArray_Cast(int h);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((Arr_268F50 *)ScriptArray_Cast((a0))) /* merge_units */

static inline unsigned char Remove_268F50(int h, int i)
{
    Arr_268F50* a = ScriptArray_Cast(h);
    if (i >= 0 && i < a->count) {
        for (; i < a->count - 1; i++)
            a->data[i] = a->data[i + 1];
        a->count--;
        return 1;
    }
    return 0;
}
int Script_Array_RemoveIndex(ScriptArg_268F50* args)
{
    int idx[1];
    idx[0] = args[1].i;
    return Remove_268F50(args[0].i, *(int*)idx);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00268F50(void) {}
#undef ScriptArray_Cast /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00268F50 */

/* merge_units: begin func_00269000 */
#pragma push /* merge_units */
typedef struct { float* data; int cap; int count; } E7Arr;
#if 0 /* merge_units */
extern E7Arr* ScriptArray_Cast(int h);
#endif /* merge_units */
#define ScriptArray_Cast(a0) ((E7Arr *)ScriptArray_Cast((a0))) /* merge_units */


static inline unsigned char E7Push(E7Arr* a, float v) {
    if (a->count < a->cap) {
        a->data[a->count++] = v;
        return 1;
    }
    return 0;
}
int Script_Array_AddElem(int* args) {
    volatile int iv = args[1];
    float v = *(float*)&iv;
    return E7Push(ScriptArray_Cast(args[0]), v);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269000(void) {}
#undef ScriptArray_Cast /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00269000 */
