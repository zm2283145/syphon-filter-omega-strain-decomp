/*
 * SFOGame/Source/activation: 2 files, 002244D0-00224530
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002244D0 */
#pragma push /* merge_units */
#include "types.h"

extern int cNIEventBase_GetVUMInTree(int);

int IsVUM(int a0) {
    int a1, v0, v1;
    int cond;

    v1 = 0 + 1;
    a1 = *(unsigned char*)((char*)a0 + 73);
    cond = a1 != v1;
    v0 = 0;
    if (cond) goto L002244F0;
    v0 = a0;
    goto L00224520;
L002244F0:;
    v1 = 0 + 15;
    cond = a1 != v1;
    if (cond) goto L00224508;
    v0 = *(int*)((char*)a0 + 100);
    goto L00224520;
L00224508:;
    v1 = 0 + 16;
    cond = a1 != v1;
    if (cond) goto L00224520;
    v0 = cNIEventBase_GetVUMInTree(a0);
L00224520:;
    goto ret;
ret:
    return v0;
}
static inline void merge_flush_func_002244D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002244D0 */

/* merge_units: begin func_00224530 */
#pragma push /* merge_units */
extern signed char D_004F7530;
extern char D_004F7548[];
extern char D_004F7538[];
extern void std_list_deleter_voidPtr_ctor_void(void* obj);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern void cGOBJActivationMan_dtor(void);

/* Returns the lazily constructed static collection. */
void* GetGOBJActivationMan(void) {
    if (!D_004F7530) {
        std_list_deleter_voidPtr_ctor_void(D_004F7548);
        __register_global_object(D_004F7548, cGOBJActivationMan_dtor, D_004F7538);
        D_004F7530 = 1;
    }
    return D_004F7548;
}
static inline void merge_flush_func_00224530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00224530 */
