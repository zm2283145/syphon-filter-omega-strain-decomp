/*
 * main/hudTargets: range (2 files, 00272CD0-00272D10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00272CD0 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int key; } Node2CD0;
typedef struct { char pad[0x34]; Node2CD0* node; int key; } Obj2CD0;
Node2CD0* func_00272CD0(Obj2CD0* o) {
    Node2CD0* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00272CD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00272CD0 */

/* merge_units: begin func_00272D10 */
#pragma push /* merge_units */
void func_00272D10(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 52) = a1;
    if (cond) goto L00272D28;
    v1 = a1 + 12;
    goto L00272D38;
L00272D28:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L00272D38:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 56) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00272D10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00272D10 */
