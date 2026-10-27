/*
 * Libs/SFOLib/Source/character: 1 file, 003E7000
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin character_3E7000 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DFD80[];
extern "C" char D_004E0180[];
extern "C" char D_004E0840[];
MSG_CLONE_BEGIN(cCharActionMsg_ObjectId_Int_Clone, 0x34, "character.hh", 0x296)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0840;
    F(int, 0x24) = S(int, 0x24);
    F(char, 0x28) = S(char, 0x28);
    p->vt = D_004E0180;
    F(int, 0x2C) = S(int, 0x2C);
    F(int, 0x30) = S(int, 0x30);
MSG_CLONE_END
static inline void merge_flush_character_3E7000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end character_3E7000 */
