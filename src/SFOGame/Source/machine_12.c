/*
 * SFOGame/Source/machine: 1 file, 00169960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00169960 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004D97F0[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cPauseMusicMsg_Clone, 0x28, "gameSound_msg.hh", 0x9C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004D97F0;
    F(unsigned char, 0x24) = S(unsigned char, 0x24);
MSG_CLONE_END
static inline void merge_flush_func_00169960(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00169960 */
