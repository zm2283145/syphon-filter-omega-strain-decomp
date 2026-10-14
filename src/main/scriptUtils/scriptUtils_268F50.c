/*
 * main/scriptUtils: range (2 files, 00268F50-00269000)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00268F50 */
#pragma push /* merge_units */
#pragma global_optimizer off
typedef union { int i; float f; void* p; } ScriptArg_268F50;
typedef struct { float* data; int cap; int count; } Arr_268F50;
extern Arr_268F50* ScriptArray_Cast(int h);
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
#undef ScriptArray_Cast /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00269000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00269000 */
