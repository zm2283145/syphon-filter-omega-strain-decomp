/*
 * SFOGame/Source/backpack: 2 files, 00258BC0-00258CE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00258BC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DC460[];
extern "C" char D_004DCF10[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cInventoryMsg_Clone, 0x30, "backpack.hh", 0xCB)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCF10;
    p->vt = D_004DC460;
    F(int, 0x24) = S(int, 0x24);
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
MSG_CLONE_END
static inline void merge_flush_func_00258BC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00258BC0 */

/* merge_units: begin func_00258CE0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cCrateInteractMsg virtual slot.
 */

#include "types.h"

extern int D_004F7EA8;

int cCrateInteractMsg_v05(void) {
    return D_004F7EA8;
}
static inline void merge_flush_func_00258CE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00258CE0 */
