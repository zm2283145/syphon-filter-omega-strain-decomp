/*
 * main/hud: range (3 files, 00244960-002449D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00244960 */
#pragma push /* merge_units */
typedef struct { char pad[0x68]; void* obj; } O4960;
extern void nHud_ComputeColor(void* tmp);
extern void cInterfaceElement_SetFilterColor(void* obj, void* tmp);
void cHud_SetAimCursorColor(O4960* self) {
    if (self->obj) {
        char tmp[16];
        nHud_ComputeColor(tmp);
        cInterfaceElement_SetFilterColor(self->obj, tmp);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00244960(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00244960 */

/* merge_units: begin func_002449A0 */
#pragma push /* merge_units */
extern void cInterfaceElement_Activate(int, int);

void cHud_DeactivateNoFireIcon(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0;
    if (cond) goto L002449C0;
    cInterfaceElement_Activate(a0, a1);
L002449C0:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002449A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002449A0 */

/* merge_units: begin func_002449D0 */
#pragma push /* merge_units */
void cHud_ActivateNoFireIcon(int a0) {
    int a1;
    int cond;

    a0 = *(int*)((char*)a0 + 120);
    cond = a0 == 0;
    a1 = 0 + 1;
    if (cond) goto L002449F0;
    cInterfaceElement_Activate(a0, a1);
L002449F0:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002449D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002449D0 */
