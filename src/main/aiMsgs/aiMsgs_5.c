/*
 * main/aiMsgs: 2 files, 00270630-00270690
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin cAIGOBJMsg_v02 */
#pragma push /* merge_units */
#include "types.h"
#include "ai_msg_pack.h"
int cAIGOBJMsg_v02(AIMsgPackObj* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    AIMsg_PackBase(self, a1, type, a3, t0, len, buf);
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end cAIGOBJMsg_v02 */

/* merge_units: begin cAIWeaponFiredMsg_v01 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004DCBF0[];
extern "C" char D_004DCD70[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAIWeaponFiredMsg_v01, 0x34, "aiMsgs.hh", 0xFC)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCD70;
    F(int, 0x24) = S(int, 0x24);
    p->vt = D_004DCBF0;
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
    F(unsigned char, 0x30) = S(unsigned char, 0x30);
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end cAIWeaponFiredMsg_v01 */
