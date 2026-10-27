/*
 * SFOGame/Source/npc: 1 file, 00147BA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin npc_147BA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004D92A0[];
extern "C" char D_004D92C0[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAISoundSystemGOBJMessage_Clone, 0x34, "ai.hh", 0x15B)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004D92A0;
    F(char, 0x24) = S(char, 0x24);
    F(char, 0x25) = S(char, 0x25);
    F(float, 0x28) = S(float, 0x28);
    F(float, 0x2C) = S(float, 0x2C);
    p->vt = D_004D92C0;
    F(int, 0x30) = S(int, 0x30);
MSG_CLONE_END
static inline void merge_flush_npc_147BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end npc_147BA0 */
