/*
 * SFOGame/Source/inventory: 1 file, 00470CF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00470CF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004C3348[];
extern "C" char D_004DCF10[];
extern "C" char D_004DFD80[];
extern "C" char D_004E1AC0[];
MSG_CLONE_BEGIN(cNetInventoryMsg_Clone, 0x28, D_004C3348, 0x36)
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
    p->vt = D_004E1AC0;
    F(short, 0x24) = S(short, 0x24);
    F(char, 0x26) = S(char, 0x26);
    F(char, 0x27) = S(char, 0x27);
MSG_CLONE_END
static inline void merge_flush_func_00470CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00470CF0 */
