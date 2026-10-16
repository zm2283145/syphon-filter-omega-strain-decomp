/*
 * main/NPCInfoObject: 2 files, 00438A10-00438A70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00438A10 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002EC878(int, int);                        
extern int D_00497550;
extern int D_00497558;
extern signed char D_00582D00;

#pragma push
#pragma opt_propagation off
unsigned char func_00438A10(void) {
    unsigned char var_s0;
    int b; int a;

    var_s0 = 0;
    b = D_00497558; a = D_00497550;
    if (func_002EC878(a, b) == 0) {
        var_s0 = 1;
    }
    D_00582D00 = 0;
    D_00497550 = -1;
    D_00497558 = -1;
    return var_s0;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00438A10 */

/* merge_units: begin func_00438A70 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void* D_00497550;
#endif /* merge_units */
#define D_00497550 (*(void **)&D_00497550) /* merge_units */

#if 0 /* merge_units */
extern unsigned char D_00582D00;
#endif /* merge_units */
#define D_00582D00 (*(unsigned char*)&D_00582D00) /* merge_units */

#if 0 /* merge_units */
extern void* D_00497558;
#endif /* merge_units */
#define D_00497558 (*(void **)&D_00497558) /* merge_units */

extern int func_002EC7D0(void* a, void* b);

/* Registers (a, b) as the active pair if func_002EC7D0 accepts them; returns 1 on success. */
unsigned char func_00438A70(void* a, void* b)
{
    unsigned char ok = 0;
    if (func_002EC7D0(a, b) == 0) {
        D_00497550 = a;
        ok = 1;
        D_00582D00 = 1;
        D_00497558 = b;
    }
    return ok;
}
#undef D_00497550 /* merge_units */
#undef D_00582D00 /* merge_units */
#undef D_00497558 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00438A70 */
