/*
 * main/playerControls: range (4 files, 002501B0-00250310)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002501B0 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int key; } Node2501;
typedef struct { Node2501* node; int key; } Ref2501;
Node2501* cSafePtr_cHuman_opCast_cHumanPtr(Ref2501* r) {
    Node2501* n = r->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != r->key) ok = 0;
    return ok ? n : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002501B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002501B0 */

/* merge_units: begin func_002501F0 */
#pragma push /* merge_units */
typedef struct { int head; int bits[1]; } SelectorT;
#pragma optimization_level 3
SelectorT* Selector_Copy(SelectorT* d, const SelectorT* s)
{
    int i;
    d->head = s->head;
    for (i = 0; i < 2; i++) {
        int w = i / 32;
        int b = i & 31;
        if ((s->bits[w] >> b) & 1)
            d->bits[w] |= 1 << b;
        else
            d->bits[w] &= ~(1 << b);
    }
    return d;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002501F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002501F0 */

/* merge_units: begin func_00250280 */
#pragma push /* merge_units */
typedef struct { int head; int bits[1]; } E7PS;
E7PS* PrioritySet_Copy(E7PS* dst, E7PS* src) {
    int i;
    dst->head = src->head;
    for (i = 0; i < 12; i++) {
        if ((*(int*)((char*)src + (i / 32) * 4 + 4) >> (i & 31)) & 1) {
            *(int*)((char*)dst + (i / 32) * 4 + 4) |= 1 << (i & 31);
        } else {
            *(int*)((char*)dst + (i / 32) * 4 + 4) &= ~(1 << (i & 31));
        }
    }
    return dst;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250280(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250280 */

/* merge_units: begin func_00250310 */
#pragma push /* merge_units */
extern char D_004F7E10[];
extern char D_004F7E20[];
extern char D_004F7E24[];
extern char D_004F7E28[];

int func_00250310(void) {
    int v0;
    int cond;

    v0 = *(signed char*)(char*)D_004F7E10;
    cond = v0 != 0;
    if (cond) goto L00250340;
    v0 = 0 + 1;
    *(int*)(char*)D_004F7E20 = 0;
    *(char*)(char*)D_004F7E10 = v0;
    *(int*)(char*)D_004F7E24 = 0;
    *(int*)(char*)D_004F7E28 = 0;
L00250340:;
    v0 = (int)D_004F7E20;
    goto ret;
ret:
    return v0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00250310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00250310 */
