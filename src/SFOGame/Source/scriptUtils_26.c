/*
 * SFOGame/Source/scriptUtils: 1 file, 002699F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002699F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DCB90[];
extern "C" char D_004DCF10[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cNetLocalTimerMsg_v01, 0x2C, "scriptUtils.cc", 0x26B)
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
    p->vt = D_004DCB90;
    F(float, 0x24) = S(float, 0x24);
    F(int, 0x28) = S(int, 0x28);
MSG_CLONE_END
static inline void merge_flush_func_002699F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002699F0 */
