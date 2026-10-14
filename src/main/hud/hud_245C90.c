/*
 * main/hud: range (4 files, 00245C90-00245E30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "buf_holder_dtor.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "obj_list_dtor.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_00245C90 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR(func_00245C90)
#pragma pop /* merge_units */
/* merge_units: end func_00245C90 */

/* merge_units: begin func_00245D80 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy an object list: erase all nodes, optionally delete. */
DEFINE_OBJ_LIST_DTOR(func_00245D80)
#pragma pop /* merge_units */
/* merge_units: end func_00245D80 */

/* merge_units: begin func_00245E00 */
#pragma push /* merge_units */
extern int func_0045CE10(int, int, int, int);

void func_00245E00(int a0) {
    int a1, a2, a3, v0;
    int cond;

    a0 = *(int*)((char*)a0 + 1700);
    cond = a0 == 0;
    if (cond) goto L00245E20;
    v0 = func_0045CE10(a0, a1, a2, a3);
L00245E20:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245E00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245E00 */

/* merge_units: begin func_00245E30 */
#pragma push /* merge_units */
typedef struct { int cap; int count; int* data; } List245E;
typedef struct { char pad[0xD4]; List245E* list; } Mgr245E;
typedef struct { char pad[0x54]; int* ctx; char pad2[0x24]; char m7C[4]; } Obj245E;
extern Mgr245E* D_004FFD30;
extern int func_00260D50(int ctx, int id);
extern void func_00245EE0(void* set, int* h);
extern void func_003E8DE0(int h, int v);
#pragma opt_strength_reduction off
void func_00245E30(Obj245E* s) {
    int ctx = *s->ctx;
    List245E* list = D_004FFD30->list;
    int i;
    for (i = 0; i < list->count; i++) {
        int h[1];
        h[0] = func_00260D50(ctx, list->data[i]);
        func_00245EE0(s->m7C, h);
        func_003E8DE0(h[0], 0);
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00245E30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00245E30 */
