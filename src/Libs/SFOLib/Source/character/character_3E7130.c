#pragma cplusplus on
#include "msg_clone.h"
extern "C" char D_004E01A0[];
extern "C" char D_004DFD80[];
extern "C" char D_004E0840[];
MSG_CLONE_BEGIN(cCharActionMsg_ObjectId_Clone, 0x30, "character.hh", 0x267)
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
    p->vt = D_004E01A0;
    F(int, 0x2C) = S(int, 0x2C);
MSG_CLONE_END
