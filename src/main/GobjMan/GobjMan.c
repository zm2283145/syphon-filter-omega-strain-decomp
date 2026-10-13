/*
 * main/GobjMan: 3 files, 0040C080-0040C120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin IdMgr_IsOccupied */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
char * ObjRegistry_Find();                           

char * IdMgr_IsOccupied(int arg0) {
    char *var_v1;
    char * temp_v0;

    temp_v0 = (char *)(ObjRegistry_Find());
    if (temp_v0 != NULL) {
        var_v1 = (char *)(F_(temp_v0, 0x1C, int));
        if (var_v1 != NULL) {
loop_2:
            if ((int)var_v1 == (int)arg0) {
                return temp_v0;
            }
            var_v1 = *(char **)var_v1;
            if (var_v1 == NULL) {
                goto block_6;
            }
            goto loop_2;
        }
    }
block_6:
    return NULL;
}
#pragma pop /* merge_units */
/* merge_units: end IdMgr_IsOccupied */

/* merge_units: begin func_0040C0E0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GobjMan.cc: pointer-vector iterator helpers.
 */


/* Iterator inequality. */
int func_0040C0E0(Iter* a, Iter* b) {
    return !(a->p == b->p);
}

/* end() iterator of a pointer vector. */
void func_0040C100(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040C0E0 */

/* merge_units: begin func_0040C120 */
#pragma push /* merge_units */
#pragma bool off
typedef struct { int** data; int size; } VC120;
extern int** func_0040C1E0(VC120* v);
static inline int c120ne(int* a, int* b) { return (a == b) ^ 1; }
/* Finds val in the pointer vector; stores the iterator (end if absent). */
void func_0040C120(int** out, VC120* v, int* val) {
    int* it = *func_0040C1E0(v);
    int* end = *func_0040C1E0(v) + v->size;
    while (c120ne(it, end)) {
        if (*it == *val) {
            *out = it;
            return;
        }
        it++;
    }
    *out = end;
}
#pragma bool reset
#pragma pop /* merge_units */
/* merge_units: end func_0040C120 */
