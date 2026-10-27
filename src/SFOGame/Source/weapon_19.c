/*
 * SFOGame/Source/weapon: 1 file, 00143B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00143B60 */
#pragma push /* merge_units */
#include "types.h"

extern int cWeapon_StoreWeapon_eWpnSlot(int, int);
extern int cWeapon_CanChangeWeapon(int);

void cWeapon_StoreWeapon_void(int a0) {
    int a1, s0, v0, v1;
    int cond;

    s0 = a0;
    v0 = cWeapon_CanChangeWeapon(a0);
    cond = v0 == 0;
    if (cond) goto L00143BA8;
    a0 = *(unsigned char*)((char*)s0 + 132);
    v1 = 0 + 6;
    cond = a0 == v1;
    if (cond) goto L00143BA0;
    a1 = *(signed char*)((char*)s0 + 132);
    a0 = s0;
    v0 = cWeapon_StoreWeapon_eWpnSlot(a0, a1);
    goto L00143BA8;
L00143BA0:;
    *(char*)((char*)s0 + 133) = v1;
L00143BA8:;
    goto ret;
ret:;
}
static inline void merge_flush_func_00143B60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143B60 */
