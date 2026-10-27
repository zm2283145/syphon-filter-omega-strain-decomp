/*
 * main/weapon: range (2 files, 00143BC0-00143C50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00143BC0 */
#pragma push /* merge_units */
typedef struct { char pad[8]; unsigned char b8; } Sub_143BC0;
typedef struct { Sub_143BC0* sub; char p4[0x9C]; unsigned char a0; char pa1[0x1B]; int bc; int c0; char pc4[0x2B]; unsigned char ef; } S_143BC0;
#pragma cplusplus on
static inline int Busy_143(S_143BC0* s) { int b = (s->ef != 0); if (!b) b = (s->a0 != 0); if (!b) b = (s->bc != 0); if (!b) b = (s->c0 != 0); return b; }
extern "C" bool cWeapon_CanChangeWeapon(S_143BC0* s) {
    bool r = false;
    if (Busy_143(s) ^ 1) {
        bool idle = !(s->sub != 0) || !(s->sub->b8 != 0);
        if (idle) r = true;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143BC0 */

/* merge_units: begin func_00143C50 */
#pragma push /* merge_units */
typedef struct { int x0; int x4; int x8; int xC; } Slot143C50;
typedef struct { Slot143C50 s[6]; } Inv143C50;
extern void cWeapon_DrawWeapon_eWpnSlot(Inv143C50*, int);
void cWeapon_DrawWeapon_void(Inv143C50* inv) {
    int slot = 6;
    int i;
    for (i = 0; i < 6; i++) {
        if (inv->s[i].x8 != -1) { slot = (unsigned char)i; break; }
    }
    if ((unsigned char)slot != 6) cWeapon_DrawWeapon_eWpnSlot(inv, slot);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143C50 */
