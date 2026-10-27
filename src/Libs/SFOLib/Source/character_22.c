/*
 * Libs/SFOLib/Source/character: 1 file, 003E6EC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin character_3E6EC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DFD80[];
extern "C" char D_004E0160[];
extern "C" char D_004E0840[];
MSG_CLONE_BEGIN(cCharActionMsg_ObjectId_Int_Scalar_Bool_Clone, 0x3C, "character.hh", 0x2D8)
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
    p->vt = D_004E0160;
    F(int, 0x2C) = S(int, 0x2C);
    F(int, 0x30) = S(int, 0x30);
    F(float, 0x34) = S(float, 0x34);
    F(unsigned char, 0x38) = S(unsigned char, 0x38);
MSG_CLONE_END
static inline void merge_flush_character_3E6EC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end character_3E6EC0 */
